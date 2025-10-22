import {Repository} from "./repository.js";
import Sql from "mssql";

export class Auditoriums extends Repository {
  constructor(sql) {
    super(sql);
  }
  
  async getAll() {
    const auditoriums = await this.sql.query('select * from auditorium');
    return auditoriums.recordsets?.at(0);
  }
  
  async create(data) {
    const insertData = new Sql.Request();
    
    insertData.input('auditorium', Sql.NVarChar, data["AUDITORIUM"]);
    insertData.input('auditorium_type', Sql.NVarChar, data["AUDITORIUM_TYPE"]);
    insertData.input('auditorium_capacity', Sql.Int, data["AUDITORIUM_CAPACITY"]);
    insertData.input('auditorium_name', Sql.NVarChar, data["AUDITORIUM_NAME"]);
    
    await insertData.query('insert into auditorium values (@auditorium, @auditorium_type, @auditorium_capacity, @auditorium_name)');
  }
  
  async edit(data) {
    const editData = new Sql.Request();
    
    editData.input('auditorium', Sql.NVarChar, data["AUDITORIUM"]);
    editData.input('auditorium_type', Sql.NVarChar, data["AUDITORIUM_TYPE"]);
    editData.input('auditorium_capacity', Sql.Int, data["AUDITORIUM_CAPACITY"]);
    editData.input('auditorium_name', Sql.NVarChar, data["AUDITORIUM_NAME"]);
    
    await editData.query('update auditorium set auditorium_type = @auditorium_type, auditorium_capacity = @auditorium_capacity, auditorium_name = @auditorium_name where auditorium = @auditorium');
  }
  
  async delete(auditorium) {
    const deleteData = new Sql.Request();
    deleteData.input("auditorium", auditorium);
    await deleteData.query("delete from auditorium where auditorium = @auditorium");
  }
  
  async getByType(type) {
    const query = new Sql.Request();
    query.input("type", type);
    const auditoriums = await query.query("select * from auditorium where AUDITORIUM_TYPE = @type");
    return auditoriums.recordsets.at(0);
  }
}