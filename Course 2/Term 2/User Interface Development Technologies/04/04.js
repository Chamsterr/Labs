var group = {
    students: [
        {
            id: 1,
            name: "John",
            group: 10,
            marks: [
                { subject: "Math", mark: 7, done: true },
                { subject: "English", mark: 9, done: true },
            ]
        },
        {
            id: 2,
            name: "Alice",
            group: 11,
            marks: [
                { subject: "Math", mark: 10, done: true },
                { subject: "English", mark: 8, done: true },
            ]
        },
        {
            id: 3,
            name: "Bob",
            group: 12,
            marks: [
                { subject: "Math", mark: 4, done: true },
                { subject: "English", mark: 6, done: true },
            ]
        },
        {
            id: 4,
            name: "Kate",
            group: 10,
            marks: [
                { subject: "Math", mark: 8, done: true },
                { subject: "English", mark: 9, done: true },
            ]
        },
        {
            id: 5,
            name: "Mike",
            group: 11,
            marks: [
                { subject: "Math", mark: 7, done: true },
                { subject: "English", mark: 10, done: true },
            ]
        },
    ],
    studentsFilter: function (group) {
        return this.students.filter(function (student) { return student.group === group; });
    },
    marksFilter: function (mark) {
        return this.students.filter(function (student) {
            return student.marks.some(function (m) { return m.mark === mark; });
        });
    },
    deleteStudent: function (id) {
        var index = this.students.findIndex(function (student) { return student.id === id; });
        if (index !== -1) {
            this.students.splice(index, 1);
        }
    }
};
console.log(group.studentsFilter(10));
console.log(group.marksFilter(9));
group.deleteStudent(3);
console.log(group.students);
