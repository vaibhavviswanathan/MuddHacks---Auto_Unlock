var fs = require('fs');

function handle(request, response) {
    console.log("Request handler 'start' was called.");
    fs.readFile('./handlers/start.html', function(err, data) {
        if (err){
            console.log(err);
        } else {
            response.writeHead(200, {"Content-Type": "text/html"});
            response.write(data);
            response.end();
        }
    });
}

exports.handle = handle;
