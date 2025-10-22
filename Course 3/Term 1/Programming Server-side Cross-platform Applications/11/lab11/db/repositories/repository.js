export class Repository {
  sql = null;
  
  constructor(sql) {
    this.sql = sql;
  }
  
  getAll() {}
  getById() {}
  create(data) {}
  edit(data) {}
  delete(id) {}
}