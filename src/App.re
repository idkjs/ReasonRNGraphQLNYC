open ReactNative;
open Types;

open AppStyle.AppStyle;

YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
  "UIManager['getConstants']",
|]);
// let venue = {title: "Somewhere", lat: 37.78825, lon: (-122.4324)};
// let event = {
//   time: Js.Date.now()->Js.Date.fromFloat->Js.Date.toString,
//   name: "Test",
//   venue,
// };
// module TabNavigation = {
//   let routes ={
//     Home: {
//         screen: Schedule,
//       },
//       CFP: {
//         screen: CFP,
//       },
//       Camera: {
//         screen: Camera,
//       },
//       Docs: {
//         screen: Docs,
//       },
//       Support: {
//         screen: SupportUs,
//       },
//   }

//   module HomeStack = {
//   let navigator =
//     StackNavigator.(
//       make({"Home": HomeScreen.make, "Details": DetailsScreen.make})
//     );
// };
// module SettingsStack = {
//   let navigator =
//     StackNavigator.(
//       make({
//         "Profile": ProfileScreen.make,
//         "SettingsScreen": SettingsScreen.make,
//       })
//     );
// };
// let navigator =
//       ReactNavigation.TabNavigator.Bottom.make({
//         "Home": HomeStack.navigator,
//         "Settings": SettingsStack.navigator,
//       });
// }
module Root = {
  [@react.component]
  let make = () => {
    let (fontsLoaded, setFontsLoaded) = React.useState(() => false);
    React.useEffect(() => {
      Utils.loadFonts
      |> Js.Promise.then_(_fontsLoaded =>
           Js.Promise.resolve(setFontsLoaded(_ => true))
         )
      |> ignore;
      None;
    });
    fontsLoaded
      // ? <View style=styles##container> <AgendaCard item=event /> </View>
      ? <View style=styles##container> <SettingHeaderDemo /> </View>
      : <Text> "Loading"->React.string </Text>;
  };
};
let graphqlUrl = "http://localhost:8080/graphiql";

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
      <Root />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>;
};