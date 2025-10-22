async function createPulpit(data) {
  const response = await axios.post('/api/pulpits', pulpitJsonMapper(data));
  return pulpitMapper(response.data);
}

async function getPulpits() {
  const response = await axios.get('/api/pulpits');
  return response.data.map(pulpitMapper);
}

async function editPulpit(data) {
  const response = await axios.put('/api/pulpits', pulpitJsonMapper(data));
  return pulpitMapper(response.data);
}

async function deletePulpit(pulpit) {
  const response = await axios.delete(`/api/pulpits/${pulpit}`);
  return pulpitMapper(response.data);
}

function pulpitMapper(data) {
  return {
    pulpit: data.PULPIT,
    pulpit_name: data.PULPIT_NAME,
    faculty: data.FACULTY
  }
}

function pulpitJsonMapper(data) {
  return {
    "PULPIT": data.pulpit,
    "PULPIT_NAME": data.pulpit_name,
    "FACULTY": data.faculty
  }
}