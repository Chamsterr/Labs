import express from "express";
import {checkDataParamMiddleware} from "../middlewares/index.js";
import ejs from 'ejs';

const routes = new express();

routes.set('view engine', 'ejs');

routes.get('/', (req, res) => {
  res.render('index');
});

routes.get('/api/faculties', async (req, res) => {
  try {
    const facs = await req.db.faculties.getAll();
    res.json(facs);
  } catch (e) {
    res.status(500).json(e);
  }
});

routes.post('/api/faculties', async (req, res) => {
  try {
    const fac = req.body;
    await req.db.faculties.create(fac);
    res.status(201).json(fac);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.put('/api/faculties', async (req, res) => {
  try {
    const fac = req.body;
    await req.db.faculties.edit(fac);
    res.json(fac);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.delete('/api/faculties/:faculty', checkDataParamMiddleware('faculty', 'faculties'), async (req, res) => {
  const {faculty} = req.params;
  await req.db.faculties.delete(faculty);
  res.json(req.deletedObject);
});

routes.get('/api/pulpits', async (req, res) => {
  const pulpits = await req.db.pulpits.getAll();
  res.json(pulpits);
})

routes.post('/api/pulpits', async (req, res) => {
  try {
    const pulpit = req.body;
    await req.db.pulpits.create(pulpit);
    res.status(201).json(pulpit);
  } catch (e) {
    res.status(500).json(e);
  }
});

routes.put('/api/pulpits', async (req, res) => {
  try {
    const pulpit = req.body;
    await req.db.pulpits.edit(pulpit);
    res.json(pulpit);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.delete('/api/pulpits/:pulpit', checkDataParamMiddleware('pulpit', 'pulpits'), async (req, res) => {
  const {pulpit} = req.params;
  await req.db.pulpits.delete(pulpit);
  res.json(req.deletedObject);
});

routes.get('/api/auditoriums', async (req, res) => {
  const auditoriums = await req.db.auditoriums.getAll();
  res.json(auditoriums);
})

routes.post('/api/auditoriums', async (req, res) => {
  try {
    const auditorium = req.body;
    await req.db.auditoriums.create(auditorium);
    res.status(201).json(auditorium);
  } catch (e) {
    res.status(500).json(e);
  }
})

routes.put('/api/auditoriums', async (req, res) => {
  try {
    const auditorium = req.body;
    await req.db.auditoriums.edit(auditorium);
    res.json(auditorium);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.delete('/api/auditoriums/:auditorium', checkDataParamMiddleware('auditorium', 'auditoriums'), async (req, res) => {
  const {auditorium} = req.params;
  await req.db.auditoriums.delete(auditorium);
  res.json(req.deletedObject);
});

routes.get('/api/subjects', async (req, res) => {
  const subjects = await req.db.subjects.getAll();
  res.json(subjects);
})

routes.post('/api/subjects', async (req, res) => {
  try {
    const pulpit = req.body;
    await req.db.subjects.create(pulpit);
    res.status(201).json(pulpit);
  } catch (e) {
    res.status(500).json(e);
  }
});

routes.put('/api/subjects', async (req, res) => {
  try {
    const pulpit = req.body;
    await req.db.subjects.edit(pulpit);
    res.json(pulpit);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.delete('/api/subjects/:subject', checkDataParamMiddleware('subject', 'subjects'), async (req, res) => {
  const {subject} = req.params;
  await req.db.subjects.delete(subject);
  res.send();
});

routes.get('/api/auditoriumstypes', async (req, res) => {
  const atypes = await req.db.auditoriumTypes.getAll();
  res.json(atypes);
})

routes.post('/api/auditoriumstypes', async (req, res) => {
  try {
    const atype = req.body;
    await req.db.auditoriumTypes.create(atype);
    res.status(201).json(atype);
  } catch (e) {
    res.status(500).json(e);
  }
})

routes.put('/api/auditoriumstypes', async (req, res) => {
  try {
    const atype = req.body;
    await req.db.auditoriumTypes.edit(atype);
    res.json(atype);
  } catch (e) {
    res.status(400).json(e);
  }
});

routes.delete('/api/auditoriumstypes/:atype', checkDataParamMiddleware('atype', 'auditoriumTypes'), async (req, res) => {
  const {atype} = req.params;
  await req.db.auditoriumTypes.delete(atype);
  res.send();
});

routes.get('/api/faculty/:code/pulpits', async (req, res) => {
  const {code} = req.params;
  const pulpits = await req.db.pulpits.getByFaculty(code);
  res.json(pulpits);
})

routes.get('/api/auditoriumtypes/:type/auditoriums', async (req, res) => {
  const {type} = req.params;
  const auditoriums = await req.db.auditoriums.getByType(type);
  res.json(auditoriums);
});

export const Routes = routes;