const { getForecast } = require('./weatherClient');
const { encode: mpEncode } = require('msgpack5')();

const FLAG_RAINY = 0x01;

const encode = ({ isRainy, currentTime }) => {
    let flags = 0;
    if (isRainy) {
        flags |= FLAG_RAINY;
    }

    return mpEncode([flags, currentTime]);
};

const isItemRainy = singleForecast =>
    singleForecast.weather.some(weather => weather.main === 'Rain');

const mainService = async (ctx, next) => {
    const forecast = await getForecast('kharkiv');
    const forecastsList = forecast.list;
    const isRainy =
        isItemRainy(forecastsList[0]) || isItemRainy(forecastsList[1]);
    const currentTime = Math.round(Date.now() / 1000);

    ctx.body = encode({ currentTime, isRainy });
};

module.exports = mainService;
