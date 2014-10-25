var url = require('url');
var home = require('./handlers/home');
var get_state = require('./handlers/get_state');
var set_state  = require('./handlers/set_state');
var error = require('./handlers/error');

function handle(request, response) {
    var handlers = {};

    handlers["/"] = home.handle;
    handlers["/state"] = get_state.handle;
    handlers["/lock"] = set_state.handle
    handlers["/unlock"] = set_state.handle;
    handlers["error"] = error.handle;

    var path = url.parse(request.url).pathname;
    if (typeof handlers[path] === 'function') {
	handlers[path](request, response);
    } else {
	handlers["error"](request, response);
    }
}

exports.handle = handle