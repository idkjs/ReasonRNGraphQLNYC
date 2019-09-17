open ReactNative;
open ReactNavigation;

open AppStyle;

YellowBox.ignoreWarnings([|
  "Possible Unhandled Promise Rejection",
  "Remote debugger",
  "UIManager['getConstants']",
|]);

module TabsConfig = {
  let tabBarStyle =
    Style.(
      style(
        ~backgroundColor=Colors.white,
        ~borderTopColor=Colors.border,
        ~paddingBottom=2.->dp,
        ~paddingTop=2.->dp,
        ~marginBottom=0.->dp,
        (),
      )
    );
  let tabBarOptions: TabNavigator.tabBarOptions =
    TabNavigator.tabBarOptions(
      ~activeTintColor=Colors.graphql,
      ~style=NavStyle.styles##tabBar,
      ~inactiveTintColor=Colors.textDisabled,
      ~showIcon=true,
      ~scrollEnabled=true,
      ~labelStyle=NavStyle.styles##label,
      ~indicatorStyle=NavStyle.styles##indicator,
      (),
    );

  let routes = {
    "Home": {
      screen: Schedule.make,
    },
    "Camera": {
      screen: Camera.make,
    },
    "Docs": {
      screen: Docs.make,
    },
    "Support": {
      screen: Support.make,
    },
  };
  let config = TabNavigator.config(~tabBarOptions, ());
  let navigator = TabNavigator.Bottom.(makeWithConfig(routes, config));

  navigator->NavigationOptions.setDynamicNavigationOptions(params => {
    let navigation = params##navigation;
    let routeName =
      navigation->Navigation.state->Utils.getActiveRoute##routeName;
    Js.log2("routeName", routeName);

    NavigationOptions.t(~headerTintColor=Colors.graphql, ());
  });
};
module Tabs =
  AppContainer.Make({
    type screenProps = {. "someProp": int};
    let navigator = TabsConfig.navigator;
  });

open AppStyle;
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
    ? <View style=styles##container>
        <StatusBar
          barStyle={
            switch (Platform.os) {
            | os when os == Platform.android => `lightContent
            | _ => `default
            }
          }
          backgroundColor=Colors.graphql
        />
        <Tabs />
      </View>
    : <Text> "Loading"->React.string </Text>;
};