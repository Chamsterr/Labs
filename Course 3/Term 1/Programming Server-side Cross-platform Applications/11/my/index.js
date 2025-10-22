const express = require('express');
const sql = require('mssql');
const path = require('path');
const app = express();
const port = 3000;

const config = {
    user: 'sa',
    password: '789775QWE+',
    server: 'localhost',
    database: 'master',
    port: 1431,
    options: {
        encrypt: false
    },
    pool: {
        min: 4,
        max: 10,
        idleTimeoutMillis: 30000
    }
};

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname + '/index.html'));
});


sql.connect(config).then(pool => {
    app.get('/api/faculties', (req, res) => {
        pool.request().query('SELECT * FROM FACULTY', (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/pulpits', (req, res) => {
        pool.request().query('SELECT * FROM PULPIT', (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/subjects', (req, res) => {
        pool.request().query('SELECT * FROM SUBJECT', (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/auditoriumstypes', (req, res) => {
        pool.request().query('SELECT * FROM AUDITORIUM_TYPE', (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/auditoriums', (req, res) => {
        pool.request().query('SELECT * FROM AUDITORIUM', (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/faculty/:id/pulpits', (req, res) => {
        pool.request().query(`SELECT * FROM PULPIT WHERE FACULTY = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.get('/api/auditoriumtypes/:id/auditoriums', (req, res) => {
        pool.request().query(`SELECT * FROM AUDITORIUM WHERE AUDITORIUM_TYPE = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result.recordset);
            }
        });
    });

    app.post('/api/pulpits', (req, res) => {
        const { PULPIT, PULPIT_NAME, FACULTY } = req.body;
        pool.request().query(`INSERT INTO PULPIT VALUES (N'${PULPIT}', N'${PULPIT_NAME}', N'${FACULTY}')`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.post('/api/subjects', (req, res) => {
        const { SUBJECT, SUBJECT_NAME, PULPIT } = req.body;
        pool.request().query(`INSERT INTO SUBJECT VALUES (N'${SUBJECT}', N'${SUBJECT_NAME}', N'${PULPIT}')`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.post('/api/auditoriumstypes', (req, res) => {
        const { AUDITORIUM_TYPE, AUDITORIUM_TYPENAME } = req.body;
        pool.request().query(`INSERT INTO AUDITORIUM_TYPE VALUES (N'${AUDITORIUM_TYPE}', N'${AUDITORIUM_TYPENAME}')`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.post('/api/auditoriums', (req, res) => {
        const { AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE } = req.body;
        pool.request().query(`INSERT INTO AUDITORIUM VALUES (N'${AUDITORIUM}', N'${AUDITORIUM_NAME}', ${AUDITORIUM_CAPACITY}, N'${AUDITORIUM_TYPE}')`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.put('/api/faculties', (req, res) => {
        const { FACULTY, FACULTY_NAME } = req.body;
        pool.request().query(`UPDATE FACULTY SET FACULTY_NAME = N'${FACULTY_NAME}' WHERE FACULTY = N'${FACULTY}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.put('/api/pulpits', (req, res) => {
        const { PULPIT, PULPIT_NAME, FACULTY } = req.body;
        pool.request().query(`UPDATE PULPIT SET PULPIT_NAME = N'${PULPIT_NAME}', FACULTY = N'${FACULTY}' WHERE PULPIT = N'${PULPIT}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.put('/api/subjects', (req, res) => {
        const { SUBJECT, SUBJECT_NAME, PULPIT } = req.body;
        pool.request().query(`UPDATE SUBJECT SET SUBJECT_NAME = N'${SUBJECT_NAME}', PULPIT = N'${PULPIT}' WHERE SUBJECT = N'${SUBJECT}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.put('/api/auditoriumstypes', (req, res) => {
        let { AUDITORIUM_TYPE, AUDITORIUM_TYPENAME } = req.body;

        pool.request().query(`UPDATE AUDITORIUM_TYPE SET AUDITORIUM_TYPENAME = N'${AUDITORIUM_TYPENAME}' WHERE AUDITORIUM_TYPE = N'${AUDITORIUM_TYPE}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.put('/api/auditoriums', (req, res) => {
        const { AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE } = req.body;
        pool.request().query(`UPDATE AUDITORIUM SET AUDITORIUM_NAME = N'${AUDITORIUM_NAME}', AUDITORIUM_CAPACITY = ${AUDITORIUM_CAPACITY}, AUDITORIUM_TYPE = N'${AUDITORIUM_TYPE}' WHERE AUDITORIUM = N'${AUDITORIUM}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.delete('/api/faculties/:id', (req, res) => {
        pool.request().query(`DELETE FROM FACULTY WHERE FACULTY = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.delete('/api/pulpits/:id', (req, res) => {
        pool.request().query(`DELETE FROM PULPIT WHERE PULPIT = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.delete('/api/subjects/:id', (req, res) => {
        pool.request().query(`DELETE FROM SUBJECT WHERE SUBJECT = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.delete('/api/auditoriumtypes/:id', (req, res) => {
        pool.request().query(`DELETE FROM AUDITORIUM_TYPE WHERE AUDITORIUM_TYPE = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });

    app.delete('/api/auditoriums/:id', (req, res) => {
        pool.request().query(`DELETE FROM AUDITORIUM WHERE AUDITORIUM = N'${req.params.id}'`, (err, result) => {
            if (err) {
                console.error(err);
                res.status(500).send(err);
            } else {
                res.json(result);
            }
        });
    });
}).catch(err => {
    console.error(err);
});

app.listen(port, () => {
    console.log(`App listening at http://localhost:${port}`);
});