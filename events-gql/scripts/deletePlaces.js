import { prisma } from '../generated/prisma-client';
// const fs = require('fs');
// var data = require('./db-fresh.json');
// var data = require('./dbshort.json');
// var data = JSON.parse(fs.readFileSync('./db-fresh.json', 'utf8'));
async function main() {
	const deletedPlace = await prisma.deleteManyPlaces({
		where: {
			published: false
		}
	})
};

main().catch((e) => console.error(e));