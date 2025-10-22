const { PrismaClient } = require("@prisma/client");
const prisma = new PrismaClient();

async function updateAndRollback() {
	const auditoriums = await prisma.auditorium.findMany();

	const updatePromises = auditoriums.map((auditorium) =>
		prisma.auditorium.update({
			where: { AUDITORIUM: auditorium.AUDITORIUM },
			data: { AUDITORIUM_CAPACITY: { increment: 100 } },
		})
	);

	try {
		await prisma.$transaction(updatePromises);
		console.log("Capacity increased by 100 for all auditoriums");

		const updatedAuditoriums = await prisma.auditorium.findMany();
		console.log(updatedAuditoriums);
	} catch (err) {
		console.error("Error updating auditoriums:", err);
	}

	const rollbackPromises = auditoriums.map((auditorium) =>
		prisma.auditorium.update({
			where: { AUDITORIUM: auditorium.AUDITORIUM },
			data: { AUDITORIUM_CAPACITY: auditorium.AUDITORIUM_CAPACITY },
		})
	);

	try {
		await prisma.$transaction(rollbackPromises);
		console.log("Changes rolled back");
		const rolledBackAuditoriums = await prisma.auditorium.findMany();
		console.log(rolledBackAuditoriums);
	} catch (err) {
		console.error("Error rolling back changes:", err);
	}
}

updateAndRollback();
