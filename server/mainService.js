const { getForecast } = require('./weatherClient');

const FLAG_RAINY = 0x01;

const encode = ({ isRainy, currentTime }) => {
    const buff = new ArrayBuffer(
        Uint8Array.BYTES_PER_ELEMENT + Uint32Array.BYTES_PER_ELEMENT
    );

    const view = new DataView(buff);

    const flags = 0;
    if (isRainy) {
        flags |= FLAG_RAINY;
    }

    view.setUint8(0, flags);
    view.setUint32(1, currentTime);

    return new Buffer(buff);
};

const isItemRainy = singleForecast =>
    singleForecast.weather.some(weather => weather.main === 'rain');

const mainService = async (ctx, next) => {
    const forecast = await getForecast('kharkiv');
    const forecastsList = forecast.list;
    const isRainy =
        isItemRainy(forecastsList[0]) || isItemRainy(forecastsList[1]);
    const currentTime = Math.round(Date.now() / 1000);

    // ctx.set('Content-Type', 'text/html');
    ctx.body = encode({ currentTime, isRainy });
};

module.exports = mainService;
