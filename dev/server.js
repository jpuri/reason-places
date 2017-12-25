const express = require('express')
const path = require('path')
const port = process.env.PORT || 5000
const app = express()

// serve static assets normally
app.use(express.static('public'))

app.get('*/styles.css', function (request, response){
  response.sendFile(path.resolve('public', 'styles.css'))
})

app.get('*/bundle.js', function (request, response){
  response.sendFile(path.resolve('public', 'bundle.js'))
})

app.get('/*', function (request, response){
  response.sendFile(path.resolve('public', 'index.html'))
})

app.listen(port);
console.log("server started on port " + port);
