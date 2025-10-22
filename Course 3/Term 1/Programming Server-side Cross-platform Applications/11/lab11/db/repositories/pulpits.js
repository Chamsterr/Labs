import {Repository} from "./repository.js";
import Sql from 'mssql';

export class Pulpits extends Repository {
  constructor(sql) {
    super(sql);
  }
  
  async getAll() {
    const pulpits = await this.sql.query('select * from pulpit');
    return pulpits.recordsets?.at(0);
  }
  
  async create(data) {
    const insertData = new Sql.Request();
    
    insertData.input('pulpit', Sql.NVarChar, data["PULPIT"]);
    insertData.input('pulpit_name', Sql.NVarChar, data["PULPIT_NAME"]);
    insertData.input('faculty', Sql.NVarChar, data["FACULTY"]);
    
    await insertData.query('insert into pulpit values (@pulpit, @pulpit_name, @faculty)');
  }
  
  async edit(data) {
    const editData = new Sql.Request();
    
    editData.input('pulpit', Sql.NVarChar, data["PULPIT"]);
    editData.input('pulpit_name', Sql.NVarChar, data["PULPIT_NAME"]);
    editData.input('faculty', Sql.NVarChar, data["FACULTY"]);
    
    await editData.query('update pulpit set pulpit_name = @pulpit_name, faculty = @faculty where pulpit = @pulpit');
  }
  
  async delete(pulpit) {
    const deleteData = new Sql.Request();
    deleteData.input("pulpit", pulpit);
    await deleteData.query("delete from subject where pulpit = @pulpit");
    await deleteData.query("delete from pulpit where pulpit = @pulpit");
  }
  
  async getByFaculty(faculty) {
    const query = new Sql.Request();
    query.input("faculty", faculty);
    const pulpits = await query.query('select * from pulpit where faculty = @faculty');
    return pulpits?.recordsets?.at(0);
  }
}