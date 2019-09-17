open ReactNative;
open Expo;
open Types;
open AppStyle.AppStyle;
let venue = {name: "Somewhere", lat: 37.78825, lon: (-122.4324)};
let event = {
  time: Js.Date.now()->Js.Date.fromFloat->Js.Date.toString,
  name: "Test",
  venue,
};

[@react.component]
let app = () => {
    let (fontsLoaded, setFontsLoaded) = React.useState(() => false);
    React.useEffect(() => {
      Utils.loadFonts
      |> Js.Promise.then_(_fontsLoaded =>
           Js.Promise.resolve(setFontsLoaded(_ => true))
         )
      |> ignore;
      None;
    });
    fontsLoaded ?
  <View style=styles##container>
      <AgendaCard item=event />
  </View>:  <Text> "Loading" ->React.string</Text>;
};