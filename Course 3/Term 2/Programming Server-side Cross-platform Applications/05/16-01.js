const express = require('express');
const passport = require('passport');
const BasicStrategy = require('passport-http').BasicStrategy;
const app = express();
const port = 3000;

const users = require('./users.json');

passport.use(new BasicStrategy(
  function(username, password, done) {
    const user = users.find(u => u.username === username);
    if (!user) { return done(null, false); }
    if (user.password !== password) { return done(null, false); }
    return done(null, user);
  }
));

app.get('/login', passport.authenticate('basic', { session: false }), (req, res) => {
  res.send('Аутентификация прошла успешно');
});

app.get('/logout',
  (req, _res, next) => { delete req.headers['authorization']; next(); },
  passport.authenticate('basic', { session: false }),
);

app.get('/resource', passport.authenticate('basic', { session: false }), (req, res) => {
  res.send('RESOURCE');
});

app.use((req, res) => {
  res.status(404).send('Сообщение со статусом 404');
});

app.listen(port, () => {
  console.log(`Сервер запущен на порту ${port}`);
});
