const express = require('express');
const passport = require('passport');
const DigestStrategy = require('passport-http').DigestStrategy;
const app = express();
const port = 3000;


const users = require('./users.json');

passport.use(new DigestStrategy({ qop: 'auth' },
  function(username, done) {
    const user = users.find(u => u.username === username);
    if (!user) { return done(null, false); }
    return done(null, user, user.password);
  },
  function(params, done) {
    done(null, true)
  }
));

app.get('/login', passport.authenticate('digest', { session: false }), (req, res) => {
  res.send('Аутентификация прошла успешно');
});

app.get('/logout', (req, res) => {
  req.logout();
  res.send('Вы вышли из системы');
});

app.get('/resource', passport.authenticate('digest', { session: false }), (req, res) => {
  res.send('RESOURCE');
});

app.use((req, res) => {
  res.status(404).send('Сообщение со статусом 404');
});

app.listen(port, () => {
  console.log(`Сервер запущен на порту ${port}`);
});
