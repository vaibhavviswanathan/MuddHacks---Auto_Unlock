var subproc = require('child_process');

function handle(request, response) {
    console.log("Request handler 'get_state' was called.");

    response.writeHead(200, {"Content-Type": "text/html"});

    var child = subproc.spawn('./python/test.py');

    /*
    child.stdout.on('data', function(data){
	response.write(data);
	response.end();
    });
    */

    child.stdout.on('data', function (data) {
	console.log('stdout: ' + data);
    });

    child.stderr.on('data', function (data) {
	console.log('stderr: ' + data);
    });

    child.on('close', function (code) {
	console.log('child process exited with code ' + code);
    });
}

exports.handle = handle;