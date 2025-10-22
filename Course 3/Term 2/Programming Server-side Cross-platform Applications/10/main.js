import express from 'express';
import bodyParser from "body-parser";
import * as fileSystem from "fs";
import { createClient } from 'webdav';


const app = express();
const webdavClient = createClient(
    'https://webdav.yandex.ru',
    {
      username: 'koeto',
      password: 'upoagwgyjcycmk'
    }
);

const filePath = './files/1.txt';
const downloadPath = './download/';

app.use(bodyParser.json()); 
app.use(bodyParser.urlencoded({ extended: true }));
app.use((request, response, next) => {
    console.log(request.method, decodeURI(request.url));
    next();
});

app.post('/md/:path', async (request, response) => {
    const path = '/' + request.params.path;
    try {
        console.log(path);
        if (await webdavClient.exists(path)) {
            response.status(408).send('Directory already exists');
        }
        else {
            await webdavClient.createDirectory(path);
            response.status(200).send('Directory created successfully');
        }
    }
    catch (error) {
        console.log(error);
        response.status(500).send(error);
    }
});

app.post('/rd/:path', async (request, response) => {
    const path = '/' + request.params.path;
    try {
        if (await webdavClient.exists(path)) {
            await webdavClient.deleteFile(path);
            response.status(200).send('Directory deleted successfully');
        }
        else {
            response.status(404).send('Directory not found');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});

app.post('/up/:name', async (request, response) => {
    const fileName = request.params.name;
    try {
        if (await webdavClient.exists(fileName)) {
            await webdavClient.deleteFile(fileName);
        }
        console.log('before readStream')
        const readStream = fileSystem.createReadStream(filePath);
        console.log('after readStream')
        if (await webdavClient.putFileContents(request.params.name, readStream)) {
            response.status(200).send('File uploaded successfully');
        }
        else {
            response.status(408).send('File upload not accepted');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});

app.post('/down/:name', async (request, response) => {
    const fileName = '/' + request.params.name;
    try {
        if (await webdavClient.exists(fileName)) {
            const downloadFilePath = downloadPath + fileName;
            const readStream = webdavClient.createReadStream(fileName);
            const writeStream = fileSystem.createWriteStream(downloadFilePath);
            readStream.pipe(writeStream);
            response.status(200).send('File downloaded successfully');
        }
        else {
            response.status(404).send('File not found');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});

app.post('/del/:name', async (request, response) => {
    const fileName = '/' + request.params.name;
    try {
        if (await webdavClient.exists(fileName)) {
            await webdavClient.deleteFile(fileName);
            response.status(200).send('File deleted successfully');
        }
        else {
            response.status(404).send('File not found');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});


app.post('/copy/:source/:destination', async (request, response) => {
    const sourcePath = '/' + request.params.source;
    const destinationPath = '/' + request.params.destination;
    try {
        if (await webdavClient.exists(sourcePath)) {
            await webdavClient.copyFile(sourcePath, destinationPath);
            response.status(200).send('File copied successfully');
        }
        else {
            response.status(404).send('Source file not found');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});

app.post('/move/:source/:destination', async (request, response) => {
    const sourcePath = '/' + request.params.source;
    const destinationPath = '/' + request.params.destination;
    try {
        if (await webdavClient.exists(sourcePath)) {
            await webdavClient.moveFile(sourcePath, destinationPath);
            response.status(200).send('File moved successfully');
        }
        else {
            response.status(404).send('Source file not found');
        }
    }
    catch (error) {
        response.status(500).send(error);
    }
});

app.listen(3000, () => {
    console.log("Server is running on port 3000");
});