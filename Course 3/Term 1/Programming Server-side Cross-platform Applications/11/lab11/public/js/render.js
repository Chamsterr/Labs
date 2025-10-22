const global = {
  pulpits: null
};

(async function onLoadTable() {
  const table = document.querySelector('.table');
  const pulpits = await getPulpits();
  
  global.pulpits = pulpits;
  
  const addedRow = document.createElement('tr');
  addedRow.classList.add('add-row');
  addedRow.innerHTML = `
    <td contenteditable="true" class="bg-success bg-opacity-10"></td>
    <td contenteditable="true" class="bg-success bg-opacity-10"></td>
    <td contenteditable="true" class="bg-success bg-opacity-10"></td>
    <td>
      <button class="btn btn-success btn-sm" onclick="addHandler()">Add</button>
    </td>
   `;
  
  table.appendChild(addedRow);
  pulpits.forEach(addRow);
})();

async function editHandler(pulpit) {
  const row = document.querySelector(`.p${pulpit}`);
  
  const pulpitInfo = {
    pulpit: pulpit,
    pulpit_name: row.children[1].textContent,
    faculty: row.children[2].textContent
  }
  
  try {
    await editPulpit(pulpitInfo);
    alert('Pulpit was edited');
  } catch (e) {
    alert(e.message);
  }
}

async function deleteHandler(pulpit) {
  try {
    await deletePulpit(pulpit);
  } catch (e) {
    alert(e.message);
  }
  const row = document.querySelector(`.p${pulpit}`);
  row.remove();
}

async function addHandler() {
  const row = document.querySelector('.add-row');
  
  const pulpitInfo = {
    pulpit: row.children[0].textContent,
    pulpit_name: row.children[1].textContent,
    faculty: row.children[2].textContent
  }
  
  try {
    const p = await createPulpit(pulpitInfo);
    addRow(p)
    alert('Pulpit was created');
  } catch (e) {
    alert(e.message);
  }
}

function addRow(p) {
  const table = document.querySelector('.table');
  const row = document.createElement('tr');
  row.classList.add('p' + p.pulpit);
  row.innerHTML = `
      <td>${p.pulpit}</td>
      <td contenteditable="true">${p.pulpit_name}</td>
      <td contenteditable="true">${p.faculty}</td>
      <td>
        <button class="btn btn-primary btn-sm" data-edit="${p.pulpit}" onclick="editHandler('${p.pulpit}')">Edit</button>
        <button class="btn btn-danger btn-sm" data-delete="${p.pulpit}" onclick="deleteHandler('${p.pulpit}')">Delete</button>
      </td>
    `;
  table.appendChild(row);
}