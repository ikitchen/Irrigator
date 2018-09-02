const { getForecast } = require('./weatherClient');

const isItemRainy = singleForecast =>
    singleForecast.weather.some(weather => weather.main === 'rain');

const mainService = async (ctx, next) => {
    const forecast = await getForecast('kharkiv');
    const forecastsList = forecast.list;
    const isRainy =
        isItemRainy(forecastsList[0]) || isItemRainy(forecastsList[1]);
    const curentTime = Date.now();
    ctx.body = `r${isRainy ? 1 : 0}t${curentTime}`;
};

module.exports = mainService;
