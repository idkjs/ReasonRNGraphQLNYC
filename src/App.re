let graphqlUrl = "http://localhost:4000/";

let makeClient = () => {
  let httpLink = ApolloLinks.createHttpLink(~uri=graphqlUrl, ());

  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|httpLink|]),
    ~cache=ApolloInMemoryCache.createInMemoryCache(),
    (),
  );
};

let client = makeClient();

let app = () => {
  <ReasonApollo.Provider client>
    <ReasonApolloHooks.ApolloProvider client>
      <Main />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>;
};