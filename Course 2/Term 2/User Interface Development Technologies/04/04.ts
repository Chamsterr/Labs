type MarkFilterType = 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10;
type DoneType = boolean;
type GroupFilterType = 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12;

type MarkType = {
  subject: string;
  mark: MarkFilterType;
  done: DoneType;
};

type StudentType = {
  id: number;
  name: string;
  group: GroupFilterType;
  marks: MarkType[];
};

type GroupType = {
  students: StudentType[];
  studentsFilter: (group: GroupFilterType) => StudentType[];
  marksFilter: (mark: MarkFilterType) => StudentType[];
  deleteStudent: (id: number) => void;
};

const group: GroupType = {
  students: [
    {
      id: 1,
      name: "John",
      group: 10,
      marks: [
        { subject: "Math", mark: 7, done: true },
        { subject: "English", mark: 9, done: true },
      ],
    },
    {
      id: 2,
      name: "Alice",
      group: 11,
      marks: [
        { subject: "Math", mark: 10, done: true },
        { subject: "English", mark: 8, done: true },
      ],
    },
    {
      id: 3,
      name: "Bob",
      group: 12,
      marks: [
        { subject: "Math", mark: 4, done: true },
        { subject: "English", mark: 6, done: true },
      ],
    },
    {
      id: 4,
      name: "Kate",
      group: 10,
      marks: [
        { subject: "Math", mark: 8, done: true },
        { subject: "English", mark: 9, done: true },
      ],
    },
    {
      id: 5,
      name: "Mike",
      group: 11,
      marks: [
        { subject: "Math", mark: 7, done: true },
        { subject: "English", mark: 10, done: true },
      ],
    },
  ],

  studentsFilter: function (group: GroupFilterType) {
    return this.students.filter((student) => student.group === group);
  },

  marksFilter: function (mark: MarkFilterType) {
    return this.students.filter((student) => {
      return student.marks.some((m) => m.mark === mark);
    });
  },

  deleteStudent: function (id: number) {
    const index = this.students.findIndex((student) => student.id === id);
    if (index !== -1) {
      this.students.splice(index, 1);
    }
  }
};

console.log(group.studentsFilter(10));
console.log(group.marksFilter(9));
group.deleteStudent(3);
console.log(group.students);