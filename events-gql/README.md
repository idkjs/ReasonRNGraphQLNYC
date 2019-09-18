# GraphQL Server Example

## Workflow Notes

⭐️ See sample queries: <http://pris.ly/e/js/graphql#6-using-the-graphql-api>
⭐️ This is cool too: <https://codesandbox.io/s/github/jorissparla/prisma3demo>

To make changes to your schema. Make them in `prisma/schema.prisma` then add any new queries you want in to show up in `schema.graphql` by editing `src/index.js`.

The error will walk you through it but generally, define the types for any `graphql` objects you are using in that file like so:

```js
const Venue = objectType({
  name: 'Venue',
  definition(t) {
    t.model.id();
    t.model.createdAt();
    t.model.updatedAt();
    t.model.name();
    t.model.lat();
    t.model.lon();
  }
});
const Event = objectType({
  name: 'Event',
  definition(t) {
    t.model.id();
    t.model.time();
    t.model.name();
    t.model.description();
    t.model.status();
    t.model.link();
    t.model.venue();
  }
});
```

Then show them on your `Query` or `Mutation` object:

```js
const Query = objectType({
  name: 'Query',
  definition(t) {
    t.crud.post({
      alias: 'post'
    });

  t.list.field('events', {
    type: 'Event',
    resolve: (_, args, ctx) => {
      return ctx.photon.events();
    }
  });
```

Add them to your `schema` types:

```js
const schema = makeSchema({
    types: [
    Query,
    Mutation,
    Post,
    User,
    Event,
    Venue,
    nexusPrisma
  ]
})
```

Then export them at the bottom of the file:

```js
module.exports = { User, Post, Event, Venue };
```
