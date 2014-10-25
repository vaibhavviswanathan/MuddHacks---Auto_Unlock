var http = require('http');
var rh = require('./requestHandler');

function start(port) {
    var server = http.createServer(rh.handle);
    server.listen(port);
    console.log("Server listening on port " + String(port));
}

exports.start = start;