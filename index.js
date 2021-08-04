const express = require("express");
const app = express();
const http = require('http');
const server = http.createServer( app );

const HOST = 'localhost';
const PORT = 3000;
const OK = 200;

instance_algorithms = [];

app.use( express.json() );

app.get("/", (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

app.post("/", (req,res) =>{
    console.log( req.body );
    // var seed = req.body.seed;
    // var log_level = req.body.loglevel;
    // var message = req.body.message;
    // var time = req.body.time;
    // console.log( seed + " " + log_level + " " + message + " " + time );
    res.end( "ok" );
});

server.listen(PORT, ()=> {
    console.log( "listening on "+ HOST + ":" + PORT )
})