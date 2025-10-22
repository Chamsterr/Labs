const expressLibrary = require('express');
const fileSystemLibrary = require('fs');
const swaggerUserInterfaceLibrary = require('swagger-ui-express');
const swaggerJavaScriptDocumentationLibrary = require('swagger-jsdoc');

const application = expressLibrary();
application.use(expressLibrary.json());

const phonebookFilePath = './db.json';

const swaggerOptions = {
  definition: {
    openapi: "3.0.0",
    info: {
      title: "Телефонный справочник API",
      version: "1.0.0",
      description: "REST API"
    },
    servers: [
      {
        url: "http://localhost:3000"
      }
    ]
  },
  apis: ["./23-01.js"] 
};



const openapiSpecification = swaggerJavaScriptDocumentationLibrary(swaggerOptions);
application.use('/api-docs', swaggerUserInterfaceLibrary.serve, swaggerUserInterfaceLibrary.setup(openapiSpecification));  

// application.use('/api-docs', swaggerUserInterfaceLibrary.serve, (req, res) => {
//     res.setHeader('Content-Type', 'text/html');
//     res.write(swaggerUserInterfaceLibrary.generateHTML(openapiSpecification));
//     res.write('<style>\n');
//     res.write('body { background-color: #282828; color: #FFFFFF; }\n');
//     res.write('.models { background-color: #282828; color: #FFFFFF; }\n');
//     res.write('.swagger-ui .opblock-tag-section { background-color: #282828; color: #FFFFFF; }\n');
//     res.write('.swagger-ui .opblock { background-color: #282828; color: #FFFFFF; }\n');
//     res.write('.swagger-ui .opblock-description-wrapper p, .swagger-ui .opblock-external-docs-wrapper p, .swagger-ui .opblock-title_normal p { color: #FFFFFF; }\n'); // Полностью белый текст
//     res.write('.swagger-ui  { color: #FFFFFF; color: #FFFFFF; }\n');
//     res.write('.swagger-ui .model-container { background-color: #282828; color: #FFFFFF; }\n');
//     res.write('</style>\n');

//     res.end();
// });


console.log('openapiSpecification: '+ JSON.stringify(openapiSpecification, null, 2));

function handleFileInputOutput(operation, phonebook) {
    try {
        if (operation === 'read') {
            const data = fileSystemLibrary.readFileSync(phonebookFilePath, 'utf-8');
            return JSON.parse(data);
        } else if (operation === 'write') {
            const data = JSON.stringify(phonebook);
            fileSystemLibrary.writeFileSync(phonebookFilePath, data, 'utf-8');
        }
    } catch (error) {
        console.error(`Failed to ${operation} phonebook:`, error);
        return operation === 'read' ? [] : null;
    }
}

application.route('/TS')
    .get((request, response) => {
        const phonebook = handleFileInputOutput('read');
        response.json(phonebook);
    })
    .post((request, response) => {
        const { id, name, phoneNumber } = request.body;
        const newPhone = { id, name, phoneNumber };
        const phonebook = handleFileInputOutput('read');
        
        const existingPhoneIndex = phonebook.findIndex((phone) => phone.id === id);
        if (existingPhoneIndex !== -1) {
            response.status(400).send('A phone entry with this ID already exists.');
        } else {
            phonebook.push(newPhone);
            handleFileInputOutput('write', phonebook);
            response.sendStatus(201);
        }
    })
    .put((request, response) => {
        const { id, name, phoneNumber } = request.body;
        const phonebook = handleFileInputOutput('read');
        const phoneIndex = phonebook.findIndex((phone) => phone.id === id);
        if (phoneIndex === -1) {
            response.sendStatus(404);
        } else {
            phonebook[phoneIndex] = { id, name, phoneNumber };
            handleFileInputOutput('write', phonebook);
            response.sendStatus(200);
        }
    })
    .delete((request, response) => {
        const { id } = request.body;
        const phonebook = handleFileInputOutput('read');
        const phoneIndex = phonebook.findIndex((phone) => phone.id === id);
        if (phoneIndex === -1) {
            response.sendStatus(404);
        } else {
            phonebook.splice(phoneIndex, 1);
            handleFileInputOutput('write', phonebook);
            response.sendStatus(200);
        }
    });

application.listen(3000, () => {
    console.log('Server is running on port 3000');
});

/**
 * @swagger
 * components:
 *   schemas:
 *     PhoneEntry:
 *       type: object
 *       required:
 *         - id
 *         - name
 *         - phoneNumber
 *       properties:
 *         id:
 *           type: number
 *           description: id владельца телефона
 *         name:
 *           type: string
 *           description: Имя владельца телефона
 *         phoneNumber:
 *           type: string
 *           description: Телефонный номер
 */

/**
 * @swagger
 * /TS:
 *   get:
 *     summary: Получить полный список телефонов
 *     responses:
 *       200:
 *         description: Список телефонов получен
 *         content:
 *           application/json:
 *             schema:
 *               type: array
 *               items:
 *                 $ref: '#/components/schemas/PhoneEntry'
 *   post:
 *     summary: Добавить новый телефон в справочник
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             $ref: '#/components/schemas/PhoneEntry'
 *     responses:
 *       201:
 *         description: Телефон добавлен в справочник
 *   put:
 *     summary: Обновить телефон в справочнике
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             $ref: '#/components/schemas/PhoneEntry'
 *     responses:
 *       201:
 *         description: Телефон обновлен в справочнике
 *   delete:
 *     summary: Удалить телефон из справочника
 *     requestBody:
 *       required: true
 *       content:
 *         application/json:
 *           schema:
 *             type: object
 *             properties:
 *               id:
 *                 type: number
 *                 description: Айди владельца телефона
 *     responses:
 *       200:
 *         description: Телефон удален из справочника
 *       404:
 *         description: Телефон не найден в справочнике
 */