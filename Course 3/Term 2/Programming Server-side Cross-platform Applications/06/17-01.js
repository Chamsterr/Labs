const express = require('express');
const bodyParser = require('body-parser');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

const users = require('./users.json');

const app = express();

app.use(bodyParser.urlencoded({ extended: false }));
app.use(session({ secret: 'secret key', resave: false, saveUninitialized: false }));
app.use(passport.initialize());
app.use(passport.session());

passport.use(new LocalStrategy(
  function(username, password, done) {
    let user = users.find((user) => user.username === username);
    if (user === undefined || user.password !== password) {
      return done(null, false, { message: 'Неверное имя пользователя или пароль' });
    }
    return done(null, user);
  }
));

passport.serializeUser(function(user, done) {
  done(null, user.username);
});

passport.deserializeUser(function(username, done) {
  let user = users.find((user) => user.username === username);
  done(null, user);
});

app.get('/login', (req, res) => {
  res.send('<form action="/login" method="post"><div><label>Username:</label><input type="text" name="username"/></div><div><label>Password:</label><input type="password" name="password"/></div><div><input type="submit" value="Log In"/></div></form>');
});

app.post('/login', passport.authenticate('local', { successRedirect: '/resource', failureRedirect: '/login' }));

app.get('/logout', (req, res) => {

    req.session.destroy((err) => {
      if (err) {
        console.log(err);
      } else {
        res.clearCookie('connect.sid');
        res.redirect('/login');
        console.log('You have successfully logged out.');
      }
    });
});


app.get('/resource', (req, res) => {
  if (req.isAuthenticated()) {
    res.send(`RESOURCE: Authenticated user - ${req.user.username}`);
  } else {
    res.sendStatus(401);
  }
});

app.use((req, res) => {
  res.sendStatus(404);
});

app.listen(3000, () => {
  console.log('App is listening on port 3000');
});
