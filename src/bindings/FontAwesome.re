[@bs.module ("@expo/vector-icons", "FontAwesome")] [@react.component]
external make:
  (~name: [@bs.string][ | `calendar | `map | `user ], ~size: int, ~color: string, ~style: ReactNative.Style.t=?) =>
  React.element =
  "FontAwesome";

// type name = [@bs.string][ | `calendar | `map | `user ];
// [@bs.inline]
// ~name: string,
//   [@bs.string] [
//     | `utf8
//     | [@bs.as "ascii"] `useAscii
//   ])
// type name = [@bs.string][
//     | [@bs.as "glass"] `glass
//     | [@bs.as "music"] `music
//     | [@bs.as "search"] `search
//     | [@bs.as "envelope-o"] `envelopeO
//     | [@bs.as "heart"] `heart
//     | [@bs.as "calendar"] `calendar
//     | [@bs.as "map"] `map
//     | [@bs.as "user"] `user
//     ];
// [@bs.module ("@expo/vector-icons", "FontAwesome")] [@react.component]
// external make:
//   (~name:name, ~size: int, ~color: string, ~style: ReactNative.Style.t=?,
//   ~allowFontScaling:bool=?,
//   ) =>
//   React.element =
//   "FontAwesome";
