const TelegramBot = require('node-telegram-bot-api');
const requestModule = require('request');
const axiosModule = require('axios');
const prismaClientModule = require('./prisma/Clients');
const cronModule = require('node-cron');

const botToken = '7161920yKwNcWw5V4I0';
const dogApiKey = "live_NAsXRc2S5D0wKNGt5qGNBAyQAmR3BJHxm7FLTAErk0bNRV";
const ninjaApiKey = "VRSpPPoblq2yoHhtpa1fYKADtps";

const bot = new TelegramBot(botToken, { polling: true });

bot.setMyCommands([
  {command: '/weather', description: 'Get weather update'},
  {command: '/subscribe', description: 'Subscribe to minute fact'},
  {command: '/unsubscribe', description: 'Unsubscribe from minute'},
  {command: '/joke', description: 'Get a random joke'},
  {command: '/dog', description: 'Get a random dog image'},
]);


bot.on('message', (message) => {
    const chatId = message.chat.id;
    if(message.text === null){
      return;
    }
    bot.sendMessage(chatId, message.text);
});

bot.onText('', async (message) => {
    const chatId = message.chat.id;

    if (message.text.toLowerCase() === '/weather'){
        const weatherApiKey = 'c7f6ee8d23ce6d1074e9b71bd025dbcf';
        const cityName = 'Lida';
        const weatherApiUrl = `http://api.openweathermap.org/data/2.5/weather?q=${cityName}&appid=${weatherApiKey}&units=metric`;

        try {
            const weatherResponse = await axiosModule.get(weatherApiUrl);
            const weatherData = weatherResponse.data;
            const weatherDescription = weatherData.weather[0].description;
            const temperature = weatherData.main.temp;
            const humidity = weatherData.main.humidity;
            const pressure = weatherData.main.pressure;
            const windSpeed = weatherData.wind.speed;
            const sunrise = new Date(weatherData.sys.sunrise * 1000).toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit', hour12: false });
            const sunset = new Date(weatherData.sys.sunset * 1000).toLocaleTimeString('en-US', { hour: '2-digit', minute: '2-digit', hour12: false });

            const weatherMessage = `
            Weather in ${cityName}:
            Currently ${weatherDescription}
            Temperature: ${temperature}°C
            Humidity: ${humidity}%
            Pressure: ${pressure} hPa
            Wind Speed: ${windSpeed} m/s
            Sunrise Time: ${sunrise}
            Sunset Time: ${sunset}
        `;

            bot.sendMessage(chatId, weatherMessage);

        } catch (error) {
            console.error('Error while fetching weather data:', error.message);
        }
    }

    if (message.text.toLowerCase() === 'привет' ) {
        const stickerFileId = 'CAACAgIAAxkBAAEE_vBmKusE0gP8tRlPCLcymj-GjtQ1nwACLDYAAl_dqUgSAAFauJm7kMg0BA';
        bot.sendSticker(chatId, stickerFileId).catch(error => {
          console.error('Error while sending sticker:', error);
        });
    }

    if(message.text.toLowerCase() === '/subscribe'){
        prismaClientModule.subscribers.create({
            data:{
                chat_id: chatId
            }
        }).then(() => {
            bot.sendMessage(chatId, "You have successfully subscribed!");
        })
            .catch((error) => {
                if (error.code === 'P2002') {
                    bot.sendMessage(chatId, "An error occurred during subscription. You might already be subscribed.");
                } else {
                    console.error('Error during subscription:', error);
                    bot.sendMessage(chatId, "An error occurred during subscription.");
                }
            })
    }

    if(message.text.toLowerCase() === '/unsubscribe'){
        prismaClientModule.subscribers.delete({
            where: {
                chat_id: chatId
            }
        })
            .then(() => {
                bot.sendMessage(chatId, "You have successfully unsubscribed.");
            })
            .catch((error) => {
                console.error('Error during unsubscription:', error);
                bot.sendMessage(chatId, "An error occurred during unsubscription. You might not be subscribed.");
            })
    }

  if (message.text.toLowerCase() === '/joke') {

    requestModule.get({
      url: 'https://api.api-ninjas.com/v1/jokes?limit=1',
      headers: {
        'X-Api-Key': ninjaApiKey
      },
    }, function(error, response, body) {
      if(error) {
        bot.sendMessage(chatId, 'Error occurred while fetching joke.');
        return console.error('Request failed:', error);
      } else if(response.statusCode != 200) {
        bot.sendMessage(chatId, 'Failed to fetch joke: ' + response.statusCode);
        return console.error('Error:', response.statusCode, body.toString('utf8'));
      } else {
        
        try {
          const joke = JSON.parse(body);
          let jokeMessage = joke.map(joke => joke.joke).join('nn');
          bot.sendMessage(chatId, jokeMessage);
        } catch (parseError) {
          bot.sendMessage(chatId, 'Error occurred while processing joke.');
          return console.error('Parse failed:', parseError);
        }
      }
    });
  };

    if(message.text.toLowerCase() === '/dog'){

        axiosModule.get('https://api.thedogapi.com/v1/images/search', {
            headers: {
                'x-api-key': dogApiKey
            }
        })
            .then(response => {
                const imageUrl = response.data[0].url;
                bot.sendPhoto(chatId, imageUrl);
            })
            .catch(error => {
                bot.sendMessage(chatId, 'Error occurred while fetching dog image.');
                console.error(error);
            });
    }
    
});

cronModule.schedule('* * * * *', () => {

    prismaClientModule.subscribers.findMany()
        .then((subscribers) => {
            subscribers.forEach((subscriber) => {
                sendFact(subscriber.chat_id);
            });
        })
        .catch((error) => {
            console.error('Error while fetching subscribers:', error);
        })
});

function sendFact(chatId) {
   
    requestModule.get({
      url: 'https://api.api-ninjas.com/v1/facts',
      headers: {
        'X-Api-Key': ninjaApiKey
      },
    }, function(error, response, body) {
      if(error) {
        bot.sendMessage(chatId, 'Error occurred while fetching facts.');
        return console.error('Request failed:', error);
      } else if(response.statusCode != 200) {
        bot.sendMessage(chatId, 'Failed to fetch facts: ' + response.statusCode);
        return console.error('Error:', response.statusCode, body.toString('utf8'));
      } else {

        try {
          const facts = JSON.parse(body);
          let factsMessage = facts.map(fact => fact.fact).join('nn');
          bot.sendMessage(chatId, factsMessage);
        } catch (parseError) {
          bot.sendMessage(chatId, 'Error occurred while processing facts.');
          return console.error('Parse failed:', parseError);
        }
      }
    });
}
