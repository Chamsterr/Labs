import { Faculty, Pulpits, AuditoriumTypes, Subjects, Auditoriums } from "./repositories/index.js";
import Sql from 'mssql';

export class DB {
  static db = new DB();

  static getConnection() {
    return DB.db;
  }

  sql = null;

  constructor() {
    const config = {
        user: 'sa',
        password: '789775QWE+',
        server: 'localhost',
        port: 1432,
        database: 'master',
        options: {
          encrypt: false
        },
        pool: {
          min: 4,
          max: 10,
          idleTimeoutMillis: 30000
        }
    }
    this.connect(config);
  }


  async connect(config) {
    await Sql.connect(config);
    this.sql = Sql;
    this.initializeRepositories();
  }

  initializeRepositories() {
    this.faculties = new Faculty(this.sql);
    this.pulpits = new Pulpits(this.sql);
    this.subjects = new Subjects(this.sql);
    this.auditoriumTypes = new AuditoriumTypes(this.sql);
    this.auditoriums = new Auditoriums(this.sql);
  }
}
