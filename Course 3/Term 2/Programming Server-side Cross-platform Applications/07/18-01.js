const express = require('express');
const passport = require('passport');
const VKStrategy = require('passport-vkontakte').Strategy;

const app = express();
app.use(passport.initialize());

passport.use(new VKStrategy({
    clientID: "51901162",
    clientSecret: "0e8e52111e8e51e8e2210d99a6f1111c9ad3219d61b13",
    callbackURL: "http://localhost:3000/auth/vk/callback"
  },
));

app.get('/login', (req, res) => {
    res.send('<a href="/auth/vk">VK</a>');
});

app.get('/auth/vk',
  passport.authenticate('vkontakte'),
  function(req, res){
  });

app.get('/auth/vk/callback', 
  passport.authenticate('vkontakte', { failureRedirect: '/login' }),
  function(req, res) {
    res.redirect('/resource');
  });

app.get('/logout', (req, res) => {
    req.logout();
    res.redirect('/login');
});

app.get('/resource', (req, res) => {
    if(req.isAuthenticated()){
        res.send('RESOURCE ' + JSON.stringify(req.user));
    } else {
        res.redirect('/login');
    }
});

app.use((req, res) => {
  res.status(404).send('404 Not Found');
});

app.listen(3000, () => {
    console.log('3000');
});
