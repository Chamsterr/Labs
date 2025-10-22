const EventEmitter = require('events');


class DB extends EventEmitter {
    db_data = [
        { id: 1, name: 'Иванов И.И.', bday: '12-12-1999' },
        { id: 2, name: 'Петров И.С.', bday: '13-11-1999' },
        { id: 3, name: 'Сидоров М.Ф.', bday: '11-11-1999' },
        { id: 4, name: 'Васильев В.В.', bday: '12-11-1999' },
    ]

    db_actions = {
        "insert": this.insert.bind(this),
        "update": this.update.bind(this),
        "delete": this.delete.bind(this)
    }

    async select() {
        return new Promise((resolve, reject) => {
            resolve(this.db_data);
        });
    };

    async insert(person) {
        return new Promise((resolve, reject) => {
            let personIndex = this.db_data.findIndex(el => el.id == person.id);
            if (personIndex === -1) {
                this.db_data.push(person);
                resolve(person);
            } else {
                reject(createError("Найден человек с id " + person.id));
            }
        })
    };

    async update(person) {
        return new Promise((resolve, reject) => {
            let personIndex = this.db_data.findIndex(el => el.id == person.id);
            if (personIndex !== -1) {
                this.db_data[personIndex] = person;
                resolve(person);
            } else {
                reject(createError("Нет человека с id " + person.id));
            }
        });
    };

    async delete(person) {
        let personIndex = this.db_data.findIndex(el => el.id == person.id);
        console.log(personIndex)
        return new Promise((resolve, reject) => {
            if (personIndex !== -1) {
                this.db_data.splice(personIndex, 1);
                resolve(id);
            } else {
                console.log("check")
                reject(createError("Нет человека с id " + person.id));
            }
        });
    }
}

const createError = (message) => {
    return {
        error: message
    }
}

module.exports.DB = DB;