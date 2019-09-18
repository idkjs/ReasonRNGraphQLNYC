import { prisma } from '../generated/prisma-client'
const fs = require('fs');
var data = require('./db-fresh.json');
// var data = require('./dbshort.json');
async function main() {

  let places = data.places;
	console.log(JSON.stringify(places));

	// places.forEach(function(item) {
	// console.log(item.name);
	// });
	places.forEach(async function(place: { name: any; city: any; published: boolean,address: any; phone1: any; phone2: any; email: any; url: any; lat: any; lng: any; category: any; }) {
		let newItem = {
			name: place.name,
      city: place.city,
      published: false,
			address: place.address,
			phone1: place.phone1,
			phone2: place.phone2,
			email: place.email,
			url: place.url,
			lat: place.lat,
			lng: place.lng,
			category: place.category
    };
    const newPlace = await prisma.createPlace(newItem);
		console.log(newPlace);
		// await prisma.createPlace(newItem);
	});
}

main().catch(e => console.error(e))
