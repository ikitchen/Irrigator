const Koa = require('koa');
const Router = require('koa-router');
const views = require('koa-views');
const mainService = require('./mainService');

const app = new Koa();
const router = new Router();

app.use(
    views(__dirname + '/views', {
        extension: 'pug',
        map: {
            pug: 'pug'
        }
    })
);

router.get('/', mainService());
router.get('/debug', mainService({ debug: true }));

app.use(router.routes()).use(router.allowedMethods());

app.listen(process.env.PORT || 7777);
