// type event = {
//   time: string,
//   name: string,
//   venue,
// }
// and venue = {
//   name: string,
//   lat: float,
//   lon: float,
// };
// let venue = {name: "Somewhere", lat: 37.78825, lon: (-122.4324)};
// let event = {
//   time: Js.Date.now()->Js.Date.fromFloat->Js.Date.toString,
//   name: "Test",
//   venue,
// };
// let buildMapLink = (lat: float, lon: float) => {j|https://www.google.com/maps/search/?api=1&query=$lat,$lon|j};

// Js.log2("test", buildMapLink(venue.lat, venue.lon));
// Js.log2("venue", venue);
// module Test = {
//   [@react.component]
//   let make = (~item: option(event)) => {
//     <div>

//         {item
//          ->Belt.Option.map(venue =>
//              <p> {"Hosted by: " ++ venue.name |> React.string} </p>
//            )
//          ->Belt.Option.getWithDefault(React.null)}
//         {item
//          ->Belt.Option.map(venue => event.venue)
//          ->Belt.Option.map(venue =>
//              <button
//                onClick={_ => Js.log(buildMapLink(venue.lat, venue.lon))}>
//                {"Build Link" |> React.string}
//              </button>
//            )
//          ->Belt.Option.getWithDefault(React.null)}
//       </div>;
//   };
// };
open ReactNative;
open Types;
open AppStyle.AgendaStyle;

let buildMapLink = (lat: float, lon: float) => {j|https://www.google.com/maps/search/?api=1&query=$lat,$lon|j};
[@react.component]
let make = (~item: event) => {
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
  <TouchableOpacity style=styles##container>
    <Text style=styles##location>
      {"Hosted by: " ++ item.venue.name |> React.string}
    </Text>
    <TouchableOpacity
      onPress={_ =>
        handlePromise(buildMapLink(item.venue.lat, item.venue.lon))
      }>
      <Text style=styles##location>
        {"Hosted by: " ++ item.venue.name |> React.string}
      </Text>
    </TouchableOpacity>
  </TouchableOpacity>;
};