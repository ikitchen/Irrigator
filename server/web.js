const Koa = require('koa');
const Router = require('koa-router');
const mainService = require('./mainService');

const app = new Koa();
const router = new Router();

router.get('/', mainService);

app.use(router.routes()).use(router.allowedMethods());

app.listen(7777);
