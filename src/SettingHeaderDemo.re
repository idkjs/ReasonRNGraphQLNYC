
open ReactNative;

open ReactNavigation;

module SettingsScreen = {
  [@react.component]
  let make = () => {
    <Screen name="Settings Screen" />;
  };
};
module ProfileScreen = {
  [@react.component]
  let make = () => {
    <Screen name="Profile Screen" />;
  };
};

module HomeStack = {
  let navigator =
    StackNavigator.(
      make({"Home": Schedule.make, "Camera": Camera.make,
      "Docs": Docs.make,
      "Support": Support.make
      })
    );
};
module SettingsStack = {
  let navigator =
    StackNavigator.(
      make({
        "Profile": ProfileScreen.make,
        "SettingsScreen": SettingsScreen.make,
      })
    );
};

module AppContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};
  let navigator =
    ReactNavigation.TabNavigator.Bottom.make({"Home": Schedule.make, "Camera": Camera.make,
      "Docs": Docs.make,
      "Support": Support.make
      });
  });

[@react.component]
let make = () =>
  // had to wrap the whole project in Unstated to get the on demo to work. How do you use a container per route?
  <AppContainer />;