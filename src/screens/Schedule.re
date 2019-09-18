open ReactNative;
open ReactNavigation;
let styles =
  Style.(
    StyleSheet.create({
      "container": style(~flex=1., ()),
      "icon": style(~width=26.->dp, ~height=26.->dp, ()),
    })
  );

module EventsQueryConfig = [%graphql
  {|
      query Events {
    events {
      # time
      # name
      description
      # status
      link
      # venue {
      #   name
      #   lat
      #   lon
      # }
    }
  }
  |}
];

module EventsQuery =
  ReasonApolloHooks.Query.Make(EventsQueryConfig);

[@react.component]
let make = () => {
  let query = EventsQueryConfig.make(());

  let (response, _) = EventsQuery.use(~variables=query##variables, ());

  switch (response) {
  | NoData => React.string("You haven't searched yet")
  | Loading => React.string("Loading...")
  | Error(_) => React.string("Not found")
  | Data(data) =>
    data##events
    ->Belt.Option.mapWithDefault(React.null, event =>
             <View style=styles##container>
        {!loading &&
          events &&
          <Agenda
            items={items}
            renderItem={(item, firstItemInDay) =>
              <AgendaCard
                item={item}
                // firstItemInDay={firstItemInDay}
                onPress={_ => Linking.openURL(item.link)}
              />}
            renderDay={(day, item) => <AgendaDate day={day} item={item} />}
            // renderEmptyDate={() => <AgendaNoData />}
            // loadItemsForMonth={this.loadItemsForMonth}
            // rowHasChanged={(r1, r2) => r1 !== r2}
            // selected={selectedDate}
            // onDayPress={this.onDayPress}
            // theme={agendaTheme}
          />}
      </View>
      )
  };
};
module TabIcon = {
  [@react.component]
  let make = () => {
    <Image
      source={Image.Source.fromRequired(
        Packager.require("../assets/graphql-logo.png"),
      )}
    />;
  };
};


type state ={
  selectedDate:string,
  items:
}
[@react.component]
let make = () => {
  <Screen name="Schedule Screen" />;
};
make->NavigationOptions.setNavigationOptions(
  NavigationOptions.t(
    ~tabBarLabel=NavigationOptions.TabBarLabel.string("Schedule"),
    ~tabBarIcon=Utils.tabBarIcon(~name=`map),
    // ~title="Profile",
    (),
  ),
);