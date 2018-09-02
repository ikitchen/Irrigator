const axios = require('axios');

const weather = axios.create({
    baseURL: 'http://api.openweathermap.org/data/2.5/',
    timeout: 1000,
    params: {
        apiKey: '0535e24aa935ed754ad31116bffecd4c'
    }
});

const getForecast = async city => {
    const response = await weather.get('/forecast', {
        params: { q: city }
    });
    return response.data;
};

exports.getForecast = getForecast;
