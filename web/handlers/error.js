var url = require('url');

function handle(request, response) {
    console.log("No request handler found for " +
		url.parse(request.url).pathname);
    response.writeHead(404, {"Content-Type": "text/plain"});
    response.write("404 Not found");
    response.end(); 
}

exports.handle = handle;
