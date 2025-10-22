const express = require('express');
const jwt = require('jsonwebtoken');
const cookieParser = require('cookie-parser');
const { PrismaClient } = require('@prisma/client');
const Redis = require("ioredis");
const cors = require('cors');

const prisma = new PrismaClient();
const app = express();

app.use(cors());
app.use(express.json());
app.use(cookieParser());

const bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

const redisClient = new Redis({ legacyMode: true});


redisClient.on('connect', () => console.log('Redis Client Connected'));
redisClient.on('error', (err) => console.log('Redis Client Connection Error', err));

function blacklistToken(token) {
  redisClient.set(token, 'true', 'EX', 24 * 60 * 60);
}

async function isTokenBlacklisted(token) {
    const tokenInBlacklist = await redisClient.get(token);
  
    if (tokenInBlacklist) {
      return true;
    }
  
    return false;
  }
  

app.get('/login', (req, res) => {
    res.send('<form action="/login" method="post"><div><label>Username:</label><input type="text" name="username"/></div><div><label>Password:</label><input type="password" name="password"/></div><div><input type="submit" value="Log In"/></div></form>');
  });
  

app.post('/login', async (req, res) => {
  const { username, password } = req.body;
  const user = await prisma.user.findUnique({ where: { username } });
  
  if (!user || user.password !== password) {
    res.redirect('/login');
    return;
  }
  
  const accessToken = jwt.sign({ username }, 'access_secret', { expiresIn: '1s' });
  const refreshToken = jwt.sign({ username }, 'refresh_secret', { expiresIn: '1m' });
  
  res.cookie('access_token', accessToken, { httpOnly: true, sameSite: 'Strict' });
  res.cookie('refresh_token', refreshToken, { httpOnly: true, sameSite: 'Strict', path: '/refresh-token' });
  
  res.redirect('/resource');
});

app.get('/refresh-token', async (req, res) => {
  const refreshToken = req.cookies.refresh_token;
  
  if (!refreshToken) {
    res.sendStatus(401);
    return;
  }

  if (await isTokenBlacklisted(refreshToken)) {
    res.sendStatus(401);
    return;
  }
  
  jwt.verify(refreshToken, 'refresh_secret', (err, user) => {
    if (err) {
      res.sendStatus(401);
      return;
    }
    
    const newAccessToken = jwt.sign({ username: user.username }, 'access_secret', { expiresIn: '10m' });
    const newRefreshToken = jwt.sign({ username: user.username }, 'refresh_secret', { expiresIn: '24h' });
    
    blacklistToken(refreshToken);
    
    res.cookie('access_token', newAccessToken, { httpOnly: true, sameSite: 'Strict' });
    res.cookie('refresh_token', newRefreshToken, { httpOnly: true, sameSite: 'Strict', path: '/refresh-token' });
    
    res.sendStatus(200);
  });
});

app.get('/logout', (req, res) => {
  const refreshToken = req.cookies.refresh_token;
  console.log(redisClient.connected)
  blacklistToken(refreshToken);
  
  res.clearCookie('access_token');
  res.clearCookie('refresh_token');
  res.sendStatus(200);
});

app.get('/resource', (req, res) => {
  const accessToken = req.cookies.access_token;
  
  if (!accessToken) {
    res.sendStatus(401);
    return;
  }
  
  jwt.verify(accessToken, 'access_secret', (err, user) => {
    if (err) {
      res.sendStatus(401);
      return;
    }
    
    res.send(`RESOURCE и информация об аутентифицированном пользователе: ${user.username}`);
  });
});

app.get('/register', (req, res) => {
    const form = `
      <form action="/register" method="post">
        <label for="username">Имя пользователя:</label><br>
        <input type="text" id="username" name="username"><br>
        <label for="password">Пароль:</label><br>
        <input type="password" id="password" name="password"><br>
        <input type="submit" value="Зарегистрироваться">
      </form>
    `;
    res.send(form);
  });
  

app.post('/register', async (req, res) => {
    const { username, password } = req.body;
  
    const existingUser = await prisma.user.findUnique({ where: { username } });
    
    if (existingUser) {
      res.status(400).send('Пользователь с таким именем уже существует');
      return;
    }
  
    const user = await prisma.user.create({
      data: {
        username,
        password 
      },
    });
  
    res.status(201).send('Пользователь успешно зарегистрирован');
  });
  

app.use((req, res) => {
  res.status(404).send('Not Found');
});

app.listen(3000, () => {
  console.log('Сервер слушает порт 3000');
});
