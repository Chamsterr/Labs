export class ExceptionManager {
  generateException(status, message) {
    return {
      status,
      message
    };
  }
  
  generateNotFoundException(res) {
    const err = this.generateException(404, 'Данные не найдены');
    res.status(err.status).json(err);
    return err;
  }
}

export const exceptionManager = new ExceptionManager();