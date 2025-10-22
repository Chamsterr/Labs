import {Repository} from "./repository.js";
import Sql from "mssql";

export class AuditoriumTypes extends Repository {
  constructor(sql) {
    super(sql);
  }
  
  async getAll() {
    const atypes = await this.sql.query('select * from auditorium_type');
    return atypes.recordsets?.at(0);
  }
  
  async create(data) {
    const insertData = new Sql.Request();
    
    insertData.input('atype', Sql.NVarChar, data["AUDITORIUM_TYPE"]);
    insertData.input('atype_name', Sql.NVarChar, data["AUDITORIUM_TYPENAME"]);
    
    await insertData.query('insert into auditorium_type values (@atype, @atype_name)');
  }
  
  async edit(data) {
    const editData = new Sql.Request();
    
    editData.input('atype', Sql.NVarChar, data["AUDITORIUM_TYPE"]);
    editData.input('atype_name', Sql.NVarChar, data["AUDITORIUM_TYPENAME"]);
    
    await editData.query('update auditorium_type set auditorium_typename = @atype_name where auditorium_type = @atype');
  }
  
  async delete(atype) {
    const deleteData = new Sql.Request();
    deleteData.input("atype", atype);
    await deleteData.query("delete from auditorium where auditorium_type = @atype");
    await deleteData.query("delete from auditorium_type where auditorium_type = @atype");
  }
}