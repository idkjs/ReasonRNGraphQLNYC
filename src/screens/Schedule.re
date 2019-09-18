open ReactNative;
open RNCalendars;
let styles =
  Style.(
    StyleSheet.create({
      "container": style(~flex=1., ()),
      "icon": style(~width=26.->dp, ~height=26.->dp, ()),
    })
  );
let agendaTheme = {
  "textSectionTitleColor": AppStyle.Colors.graphql,
  "selectedDayBackgroundColor": AppStyle.Colors.graphql,
  "selectedDayTextColor": AppStyle.Colors.white,
  "todayTextColor": AppStyle.Colors.graphql,
  "dayTextColor": AppStyle.Colors.text,
  "textDisabledColor": AppStyle.Colors.textDisabled,
  "dotColor": AppStyle.Colors.graphql,
  "selectedDotColor": AppStyle.Colors.white,
  "arrowColor": AppStyle.Colors.graphql,
  "monthTextColor": AppStyle.Colors.graphql,
  "agendaDayTextColor": AppStyle.Colors.graphql,
  "agendaDayNumColor": AppStyle.Colors.graphql,
  "agendaTodayColor": AppStyle.Colors.graphql,
  "textDayFontFamily": "dinRegular",
  "textMonthFontFamily": "dinHeavy",
  "textDayHeaderFontFamily": "dinMedium",
};
module EventsQueryConfig = [%graphql
  {|
      query Events {
        events {
          time
          name
          description
          status
          link
          venue {
            name
            lat
            lon
          }
        }
  }
  |}
];

module EventsQuery = ReasonApolloHooks.Query.Make(EventsQueryConfig);

type state = {
  selectedDate: string,
  items: array(Js.t({.})),
};
type action =
  | SelectDate(Js.Date.t)
  | SetItems(array(Js.t({.})));
let initialState = {selectedDate: "", items: [||]};

let reducer = (state, action) => {
  switch (action) {
  | SelectDate(date) => {
      ...state,
      selectedDate: Js.Date.toLocaleTimeString(date),
    }
  | SetItems(items) => {...state, items}
  };
};
[@react.component]
let make = () => {
  let query = EventsQueryConfig.make();

  let (response, _) = EventsQuery.use(~variables=query##variables, ());
    let (state, dispatch) = React.useReducer(reducer, initialState);
  let {items, selectedDate} = state;

  switch (response) {
  | NoData => <Text> {React.string("You haven't searched yet")} </Text>
  | Loading => <Text> {React.string("Loading...")} </Text>
  | Error(_) => <Text> {React.string("Not found")} </Text>
  | Data(data) =>
    data##events->Js.log;
    <View style=styles##container>
<AgendaCard items renderItem={
  (item, firstItemInDay) =>
    <AgendaCard
      item
      firstItemInDay
      onPress={() => Linking.openURL(item.link)}
    />;
}/>
    <Screen name="Testing" /> </View>;
  };
};

// open ReactNavigation;

module TabIcon = {
  [@react.component]
  let make = () => {
    <Image
      source={Image.Source.fromRequired(
        Packager.require("../assets/graphql-logo.png"),
      )}
    />;
  };
} /* )*/ /*     ()*/ /*   )*/;

// type state ={
//   selectedDate:string,
//   items:
// }
// [@react.component]
// let make = () => {
//   <Screen name="Schedule Screen" />;
// };
// make->NavigationOptions.setNavigationOptions(
//   NavigationOptions.t(
//     ~tabBarLabel=NavigationOptions.TabBarLabel.string("Schedule"),
//     ~tabBarIcon=Utils.tabBarIcon(~name=`map),
//     // ~title="Profile",