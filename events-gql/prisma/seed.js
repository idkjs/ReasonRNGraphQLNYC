const Photon = require('@generated/photon')
const photon = new Photon.default()

async function main() {
    	const event1 = await photon.events.create({
		data: {
			time: '2020-08-12T08:28:42.112Z',
			name: 'ipsum',
			description: 'esse-omnis-vel',
			status: 'ordered',
			link: 'https://mateo.net',
			venue: {
				create: {
					name: 'Feil and Sons',
					lat: -18.8485,
					lon: -77.5664
				}
			}
		},
		include: {
			venue: true
		}
	});
	const event2 = await photon.events.create({
		data: {
			time: '2020-02-16T16:06:09.006Z',
			name: 'veniam',
			description: 'aliquam-eum-illum',
			status: 'ordered',
			link: 'http://destiny.biz',
			venue: {
				create: {
					name: 'Hartmann Inc',
					lat: 53.2535,
					lon: 6.267
				}
			}
		},
		include: {
			venue: true
		}
	});

	console.log(`Created events: ${event1.name} (${event1.venue} venue) and (${event2.venue} venue) `);
	// Retrieve all published posts
	const allEvents = await photon.events();
	console.log(`Retrieved all published posts: `, allEvents);
  const user1 = await photon.users.create({
    data: {
      email: 'alice2@prisma.io',
      name: 'Alice',
      posts: {
        create: {
          title: 'Watch the talks from Prisma Day 2019',
          content: 'https://www.prisma.io/blog/z11sg6ipb3i1/',
          published: true,
        },
      },
    },
  })
  const user2 = await photon.users.create({
    data: {
      email: 'bob2@prisma.io',
      name: 'Bob',
      posts: {
        create: [
          {
            title: 'Subscribe to GraphQL Weekly for community news',
            content: 'https://graphqlweekly.com/',
            published: true,
          },
          {
            title: 'Follow Prisma on Twitter',
            content: 'https://twitter.com/prisma/',
            published: false,
          },
        ],
      },
    },
  })
  console.log({ user1, user2 })
}

main()
  .catch(e => console.error(e))
  .finally(async () => {
    await photon.disconnect()
  })
