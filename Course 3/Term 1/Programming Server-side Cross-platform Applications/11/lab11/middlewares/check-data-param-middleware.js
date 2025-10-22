import {exceptionManager} from "../utils/exception-mngr.js";

export function checkDataParamMiddleware(field, repository) {
  return async (req, res, next) => {
    const id = req.params[field];
    const allData = await req.db[repository].getAll();
    
    const deleteObject = allData.find(item => Object.values(item)?.at(0).trim() === id.trim());
    
    if (!deleteObject) {
      exceptionManager.generateNotFoundException(res);
      return;
    }
    
    req.deletedObject = deleteObject;
    next?.();
  }
}