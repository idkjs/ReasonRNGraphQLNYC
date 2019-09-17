open ReactNative;
let loadFonts =
  Js.Promise.resolve(
    Expo.Font.loadAsync([
      ("dinBold", Packager.require("../assets/fonts/DINPro-Black.ttf")),
      ("dinHeavy", Packager.require("../assets/fonts/DINPro-Bold.ttf")),
      ("dinRegular", Packager.require("../assets/fonts/DINPro-Regular.ttf")),
      ("dinMedium", Packager.require("../assets/fonts/DINPro-Medium.ttf")),
      ("dinLight", Packager.require("../assets/fonts/DINPro-Light.ttf")),
    ]),
  );

  let rec getActiveRoute = route =>
  switch (route##routes) {
  | Some(routes) =>
    let routeCount = routes->Array.length;
    if (routeCount == 0 || route##index >= routeCount) {
      route;
    } else {
      getActiveRoute(routes->Belt.Array.getUnsafe(route##index));
    };
  | None => route
  };