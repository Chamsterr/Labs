import {Repository} from "./repository.js";
import Sql from "mssql";

export class Subjects extends Repository {
  constructor(sql) {
    super(sql);
  }
  
  async getAll() {
    const subjects = await this.sql.query("select * from subject");
    return subjects.recordsets?.at(0);
  }
  
  async create(data) {
    const insertData = new Sql.Request();
    
    insertData.input("subject", Sql.NVarChar, data["SUBJECT"]);
    insertData.input("subject_name", Sql.NVarChar, data["SUBJECT_NAME"]);
    insertData.input("pulpit", Sql.NVarChar, data["PULPIT"]);
    
    await insertData.query("insert into subject values (@subject, @subject_name, @pulpit)");
  }
  
  async edit(data) {
    const editData = new Sql.Request();
    
    editData.input("subject", Sql.NVarChar, data["SUBJECT"]);
    editData.input("subject_name", Sql.NVarChar, data["SUBJECT_NAME"]);
    editData.input("pulpit", Sql.NVarChar, data["PULPIT"]);
    
    await editData.query("update subject set subject_name = @subject_name, pulpit = @pulpit where subject = @subject");
  }
  
  async delete(subject) {
    const deleteData = new Sql.Request();
    deleteData.input("subject", subject);
    await deleteData.query("delete from subject where subject = @subject");
  }
}