import {Repository} from "./repository.js";
import Sql from "mssql";

export class Faculty extends Repository {
  constructor(sql) {
    super(sql);
  }
  
  async getAll() {
    const faculties = await this.sql.query('select * from faculty');
    return faculties.recordsets?.at(0);
  }
 
  async create(data) {
    const insertData = new Sql.Request();
    
    insertData.input('faculty', Sql.NVarChar, data["FACULTY"]);
    insertData.input('faculty_name', Sql.NVarChar, data["FACULTY_NAME"]);
    
    await insertData.query('insert into faculty values (@faculty, @faculty_name)');
  }
  
  async edit(data) {
    const editData = new Sql.Request();
    
    editData.input('faculty', Sql.NVarChar, data["FACULTY"]);
    editData.input('faculty_name', Sql.NVarChar, data["FACULTY_NAME"]);
    
    await editData.query('update faculty set faculty_name = @faculty_name where faculty = @faculty');
  }
  
  async delete(faculty) {
    const deleteData = new Sql.Request();
    deleteData.input("faculty", faculty);
    await deleteData.query("delete from pulpit where faculty = @faculty");
    await deleteData.query("delete from faculty where faculty = @faculty");
  }
}