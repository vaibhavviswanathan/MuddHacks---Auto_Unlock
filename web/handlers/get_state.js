var subproc = require('child_process');

function handle(request, response) {
    console.log("Request handler 'exec' was called.");

    response.writeHead(200, {"Content-Type": "text/html"});

    var child = subproc.spawn('./python/test.py');

    child.stdout.on('data', function(data){
	response.write(data);
	response.end();
    });
}

exports.handle = handle;