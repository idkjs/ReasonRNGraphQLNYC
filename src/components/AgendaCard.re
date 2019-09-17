open ReactNative;
// open Expo;
open AppStyle.AgendaStyle;
open ReactNativeMaps;
let dimensions = Dimensions.get(`window);

let mapStyle =
  StyleSheet.create(
    Style.{
      "mapStyle":
        style(
          ~width=(dimensions##width -. 40.)->dp,
          ~height=400.->dp,
          ~borderRadius=5.,
          (),
        ),

      "rocketView": style(~fontSize=24., ()),
      "mapContainer": style(~flex=1., ()),
      "mapView": style(~padding=20.->dp, ()),
    },
  );
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
let make = (~item: event,
//  ~firstItemInDay,
  // ~onPress
  ) => {
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
  let rocketIcon = {js|🚀|js};

  <TouchableOpacity style=styles##container>
    <Text style=styles##location>
      {"Hosted by: " ++ item.venue.name |> React.string}
    </Text>
    <TouchableOpacity
      onPress={_ =>
        handlePromise(buildMapLink(item.venue.lat, item.venue.lon))
      }>
      <View style=mapStyle##mapView>
        <MapView
          style=mapStyle##mapStyle
          region={
            "latitude": 37.78825,
            "longitude": (-122.4324),
            "latitudeDelta": 0.0922,
            "longitudeDelta": 0.0421,
          }
          initialRegion={
            "latitude": 37.78825,
            "longitude": (-122.4324),
            "latitudeDelta": 0.0922,
            "longitudeDelta": 0.0421,
          }>
          <Marker coordinate={"latitude": 37.78825, "longitude": (-122.4324)}>
            <View>
              <Text style=mapStyle##rocketView>
                {rocketIcon |> React.string}
              </Text>
            </View>
          </Marker>
        </MapView>
      </View>
    </TouchableOpacity>
  </TouchableOpacity>;
  //  {item
  //  ->Belt.Option.map(venue =>
  //     <TouchableOpacity
  //       onPress={_ =>
  //         Linking.openURL(buildMapLink(venue.lat, venue.lon))
  //       }>
  // <Expo.MapView
  // // style=Style.(style(~padding=dp(12.), ~borderRadius=12., ()))
  //   style=Style.(~style(~flex=1., ~height=150.,()))
  //   initialRegion={
  //     latitude: parseFloat(venue.lat),
  //     longitude: parseFloat(venue.lon),
  //     latitudeDelta: 0.0222,
  //     longitudeDelta: 0.0421,
  //   }>
  //   <MapView.Marker
  //     coordinate={
  //       latitude: parseFloat(venue.lat),
  //       longitude: parseFloat(venue.lon),
  //     }
  //     title={venue.name}
  //   />
  // </MapView>
  //     </TouchableOpacity>)
  //     ->Belt.Option.getWithDefault(React.null)
  //    }
};