open ReactNative;
// open Expo;
open AppStyle.AgendaStyle;

// type venue = {
//   name: string,
//   lat: float,
//   lon: float,
// };
// type event = {
//   time: string,
//   name: string,
//   description: string,
//   status: string,
//   link: string,
//   venue,
// }
// and venue = {
//   name: string,
//   lat: float,
//   lon: float,
// };
open Types;
let buildMapLink = (lat: float, lon: float) => {j|https://www.google.com/maps/search/?api=1&query=$lat,$lon|j};
[@react.component]
let make = (~item: option(event), ~firstItemInDay, ~onPress) => {
  let (url, setURL) = React.useState(() => None);
  let handler = s => {
    s##url->Js.Console.warn;
  };
  let handlePromise = url =>
    Js.Promise.(
      Linking.openURL(url)
      |> then_(() => resolve(setURL(_ => Some(url))))
      |> catch(err => resolve(err->Js.Console.warn))
      |> ignore
    );
  <TouchableOpacity onPress style=styles##container>
    {item
     ->Belt.Option.map(venue =>
         <Text style=styles##location>
           {"Hosted by: " ++ venue.name |> React.string}
         </Text>
       )
     ->Belt.Option.getWithDefault(React.null)}
    //  {item
    //  ->Belt.Option.map(name =>
    //      <Text style=styles##title>
    //        {name |>React.string}
    //      </Text>
    //      )
    //  ->Belt.Option.getWithDefault(React.null)}
    // <Text style=styles##title> {item.name} </Text>
    // {item
    //  ->Belt.Option.map(venue => event.venue)
    //  ->Belt.Option.map(venue =>
    //      <TouchableOpacity
    //        onPress={_ =>
    //          Linking.openURL(buildMapLink(venue.lat, venue.lon))
    //        }>
    //        {"Hosted by: " ++ item.venue.name->React.string}
    //      </TouchableOpacity>
    //    )
    //  ->Belt.Option.getWithDefault(React.null)}
    {item
     ->Belt.Option.map(item => item.venue)
     ->Belt.Option.map(venue =>
         <TouchableOpacity
           onPress={_ => handlePromise(buildMapLink(venue.lat, venue.lon))}>
           {"Hosted by: " ++ venue.name |> React.string}
         </TouchableOpacity>
       )
     ->Belt.Option.getWithDefault(React.null)}
  </TouchableOpacity>;
  //  {item
  //  ->Belt.Option.map(venue =>
  //     <TouchableOpacity
  //       onPress={_ =>
  //         Linking.openURL(buildMapLink(venue.lat, venue.lon))
  //       }>
  //       <MapView
  //       // style=Style.(style(~padding=dp(12.), ~borderRadius=12., ()))
  //         style=Style.(~style(~flex=1., ~height=150.,()))
  //         initialRegion={
  //           latitude: parseFloat(venue.lat),
  //           longitude: parseFloat(venue.lon),
  //           latitudeDelta: 0.0222,
  //           longitudeDelta: 0.0421,
  //         }>
  //         <MapView.Marker
  //           coordinate={
  //             latitude: parseFloat(venue.lat),
  //             longitude: parseFloat(venue.lon),
  //           }
  //           title={venue.name}
  //         />
  //       </MapView>
  //     </TouchableOpacity>)
  //     ->Belt.Option.getWithDefault(React.null)
  //    }
};