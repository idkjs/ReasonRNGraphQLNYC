module Calendar = {
  [@bs.module "react-native-calendars"] [@react.component]
  external make:
    (
      ~minDate: option(string)=?,
      ~onDayPress: option(Js.t({..}) => unit)=?,
      ~hideArrows: option(bool)=?,
      ~monthFormat: option(string)=?,
      ~current: option(string)=?,
      ~onMonthChange: option(string => unit)=?,
      ~hideExtraDays: option(bool)=?,
      ~disableMonthChange: option(bool)=?,
      ~firstDay: option(int)=?,
      ~hideDayNames: option(bool)=?,
      ~markedDates: Js.Dict.t({
                      .
                      "startingDay": bool,
                      "endingDay": bool,
                      "color": string,
                      "textColor": string,
                    }),
      // ~style: option(ReactNative.Style.t)=?,
      ~markingType: option(string)=?,
      ~children: 'b
    ) =>
    React.element =
    "Calendar";
};

module Agenda = {
  [@bs.module "react-native-calendars"] [@bs.scope "Agenda"] [@react.component]
  external make:
    (
      ~items: Js.t({.}),
      ~renderItem: option(unit => React.element),
      ~renderDay: option(unit => React.element),
      ~renderEmptyData: option(unit => React.element),
      ~loadItemsForMonth: option(Js.t({..}) => unit)=?,
      ~rowHasChanged: option(unit => unit),
      ~selected: option(Js.t({..})),
      ~onDayPress: option(Js.t({..}) => unit)=?,
      // ~onDayPress: option(unit),
      ~theme: Js.t({..}),
      ~children: 'b
    ) =>
    React.element =
    "Agenda";
};
