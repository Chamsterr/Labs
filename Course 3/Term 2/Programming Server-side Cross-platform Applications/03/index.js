const express = require("express");
const { PrismaClient } = require("@prisma/client");
const path = require("path");
const app = express();
const port = 3000;

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
	res.sendFile(path.join(__dirname + "/index.html"));
});

const prisma = new PrismaClient();

app.get("/api/auditoriumsWithComp1", async (req, res) => {
	try {
		const auditoriums = await prisma.auditorium.findMany({
			where: {
				AUDITORIUM_NAME: {
					contains: '-1'
				}
			}
		});
		res.json(auditoriums);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});


app.get("/api/pulpitsWithoutTeachers", async (req, res) => {
	try {
		const pulpits = await prisma.pulpit.findMany({
			where: {
				Teacher: {
					none: {}
				}
			}
		});
		res.json(pulpits);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/pulpitsWithVladimir", async (req, res) => {
	try {
		const pulpits = await prisma.pulpit.findMany({
			where: {
				Teacher: {
					some: {
						TEACHER_NAME: {
							contains: 'Vladimir'
						}
					}
				}
			}
		});
		res.json(pulpits);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/auditoriumsSameCount", async (req, res) => {
	try {
		const auditoriums = await prisma.auditorium.groupBy({
			by: ['AUDITORIUM_TYPE', 'AUDITORIUM_CAPACITY'],
			_count: true
		});
		res.json(auditoriums);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});


app.get("/api/faculties", async (req, res) => {
	try {
		const faculties = await prisma.faculty.findMany();
		res.json(faculties);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

// app.get("/api/pulpits", async (req, res) => {
// 	try {
// 		const pulpits = await prisma.pulpit.findMany();
// 		res.json(pulpits);
// 	} catch (err) {
// 		console.error(err);
// 		res.status(500).send(err);
// 	}
// });

app.get("/api/pulpits", async (req, res) => {
	const page = parseInt(req.query.page) || 1;
	const limit = parseInt(req.query.limit) || 10;
	const skip = (page - 1) * limit;

	try {
		const pulpits = await prisma.pulpit.findMany({
			skip: skip, 
			take: limit,
			include: {
				Teacher: true,
			},
		});

		const pulpitsWithTeacherCount = pulpits.map((pulpit) => ({
			...pulpit,
			teacherCount: pulpit.Teacher.length,
		}));

		res.json(pulpitsWithTeacherCount);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/subjects", async (req, res) => {
	try {
		const subjects = await prisma.subject.findMany();
		res.json(subjects);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/auditoriumstypes", async (req, res) => {
	try {
		const auditoriumTypes = await prisma.auditoriumType.findMany();
		res.json(auditoriumTypes);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/teachers", async (req, res) => {
	try {
		const teachers = await prisma.teacher.findMany();
		res.json(teachers);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.get("/api/faculty/:id/subjects", async (req, res) => {
	try {
		const result = await prisma.subject.findMany({
			where: { Pulpit: { FACULTY: req.params.id } },
			include: {
				Pulpit: true,
			},
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});


app.get("/api/auditoriumtypes/:id/auditoriums", async (req, res) => {
	try {
		const auditoriums = await prisma.auditorium.findMany({
			where: { AUDITORIUM_TYPE: req.params.id },
			include: {
				AuditoriumType: true,
			},
		});
		const result = {
			auditorium_type: req.params.id,
			Auditorium: auditoriums
		};
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});


app.get("/api/auditoriums", async (req, res) => {
	const { minCapacity, maxCapacity } = req.body;

	try {
		const result = await prisma.auditorium.findMany({
			where: {
				AUDITORIUM_CAPACITY: {
					gte: minCapacity,
					lte: maxCapacity,
				},
			},
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

//

// POST
app.post("/api/pulpits", async (req, res) => {
	const { PULPIT, PULPIT_NAME, FACULTY } = req.body;
	try {
		const result = await prisma.pulpit.create({
			data: { PULPIT, PULPIT_NAME, FACULTY },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.post("/api/subjects", async (req, res) => {
	const { SUBJECT, SUBJECT_NAME, PULPIT } = req.body;
	try {
		const result = await prisma.subject.create({
			data: { SUBJECT, SUBJECT_NAME, PULPIT },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.post("/api/auditoriumstypes", async (req, res) => {
	const { AUDITORIUM_TYPE, AUDITORIUM_TYPENAME } = req.body;
	try {
		const result = await prisma.auditoriumType.create({
			data: { AUDITORIUM_TYPE, AUDITORIUM_TYPENAME },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.post("/api/auditoriums", async (req, res) => {
	const { AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE } =
		req.body;
	try {
		const result = await prisma.auditorium.create({
			data: {
				AUDITORIUM,
				AUDITORIUM_NAME,
				AUDITORIUM_CAPACITY,
				AUDITORIUM_TYPE,
			},
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.post("/api/teachers", async (req, res) => {
	const { TEACHER, TEACHER_NAME, PULPIT } = req.body;
	try {
		const result = await prisma.teacher.create({
			data: { TEACHER, TEACHER_NAME, PULPIT },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.post("/api/faculties", async (req, res) => {
	const { FACULTY, FACULTY_NAME } = req.body;
	try {
		const result = await prisma.faculty.create({
			data: { FACULTY, FACULTY_NAME },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

//

//PUT
app.put("/api/faculties", async (req, res) => {
	const { FACULTY, FACULTY_NAME } = req.body;
	try {
		const result = await prisma.faculty.update({
			where: { FACULTY },
			data: { FACULTY_NAME },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.put("/api/pulpits", async (req, res) => {
	const { PULPIT, PULPIT_NAME, FACULTY } = req.body;
	try {
		const result = await prisma.pulpit.update({
			where: { PULPIT },
			data: { PULPIT_NAME, FACULTY },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.put("/api/subjects", async (req, res) => {
	const { SUBJECT, SUBJECT_NAME, PULPIT } = req.body;
	try {
		const result = await prisma.subject.update({
			where: { SUBJECT },
			data: { SUBJECT_NAME, PULPIT },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.put("/api/auditoriumstypes", async (req, res) => {
	const { AUDITORIUM_TYPE, AUDITORIUM_TYPENAME } = req.body;
	try {
		const result = await prisma.auditoriumType.update({
			where: { AUDITORIUM_TYPE },
			data: { AUDITORIUM_TYPENAME },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.put("/api/auditoriums", async (req, res) => {
	const { AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE } =
		req.body;
	try {
		const result = await prisma.auditorium.update({
			where: { AUDITORIUM },
			data: {
				AUDITORIUM_NAME,
				AUDITORIUM_CAPACITY,
				AUDITORIUM_TYPE,
			},
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.put("/api/teachers/:id", async (req, res) => {
	const { TEACHER_NAME, PULPIT } = req.body;
	try {
		const result = await prisma.teacher.update({
			where: { TEACHER: req.params.id },
			data: { TEACHER_NAME, PULPIT },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});
//

// DELETE
app.delete("/api/faculties/:id", async (req, res) => {
	try {
		const result = await prisma.faculty.delete({
			where: { FACULTY: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.delete("/api/pulpits/:id", async (req, res) => {
	try {
		const result = await prisma.pulpit.delete({
			where: { PULPIT: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.delete("/api/subjects/:id", async (req, res) => {
	try {
		const result = await prisma.subject.delete({
			where: { SUBJECT: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.delete("/api/auditoriumtypes/:id", async (req, res) => {
	try {
		const result = await prisma.auditoriumType.delete({
			where: { AUDITORIUM_TYPE: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.delete("/api/auditoriums/:id", async (req, res) => {
	try {
		const result = await prisma.auditorium.delete({
			where: { AUDITORIUM: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.delete("/api/teachers/:id", async (req, res) => {
	try {
		const result = await prisma.teacher.delete({
			where: { TEACHER: req.params.id },
		});
		res.json(result);
	} catch (err) {
		console.error(err);
		res.status(500).send(err);
	}
});

app.route('/book')
  .get((req, res) => {
    res.send('Get a random book');
  })
  .post((req, res) => {
    res.send('Add a book');
  })
  .put((req, res) => {
    res.send('Update the book');
  });

app.listen(port, () => {
	console.log(`Server is running at http://localhost:${port}`);
});