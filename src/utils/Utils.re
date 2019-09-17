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