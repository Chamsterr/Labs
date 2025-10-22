const express = require('express');
const passport = require('passport');
const GitHubStrategy = require('passport-github').Strategy;
const session = require('express-session');

const app = express();
app.listen(3000, () => console.log('3000'));

app.use(session({
  secret: 'секрет',
  resave: false,
  saveUninitialized: false
}));

passport.serializeUser((user, done) => done(null, user));
passport.deserializeUser((obj, done) => done(null, obj));

passport.use(new GitHubStrategy({
    clientID: '71d131a3a231d2eb8375f8',
    clientSecret: '111111ef2aaadd112352ddddfafaf21rfffff7b811111111111111111111111e',
    callbackURL: 'http://localhost:3000/auth/github/callback'
  },
  (accessToken, refreshToken, profile, cb) => cb(null, profile)
));

app.use(passport.initialize());
app.use(passport.session());

app.get('/login', (req, res) => res.send('<a href="/auth/github">GitHub</a>'));
app.get('/auth/github', passport.authenticate('github'));
app.get('/auth/github/callback', 
  passport.authenticate('github', { failureRedirect: '/login' }),
  (req, res) => res.redirect('/resource')
);
app.get('/logout', (req, res) => {
    req.logout(function(err) {
      if (err) { return next(err); }
      res.redirect('/login');
    });
  });
  
app.get('/resource', (req, res) => {
  if (req.isAuthenticated()) {
    res.send(`RESOURCE: ${req.user.username}`);
  } else {
    res.redirect('/login');
  }
});

app.use((req, res) => res.status(404).send('404 Not Found'));
