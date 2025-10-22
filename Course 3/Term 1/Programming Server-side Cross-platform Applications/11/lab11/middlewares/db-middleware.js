import {DB} from "../db/index.js";

export function dbMiddleware(req, resp, next) {
  req.db = DB.getConnection();
  next();
}