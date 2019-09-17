  module Calendar = {
    [@bs.module "react-native-calendars"]
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
          ~markedDates:
             Js.Dict.t(
               {
                 .
                 "startingDay": bool,
                 "endingDay": bool,
                 "color": string,
                 "textColor": string,
               },
             ),
          ~style: option(ReactNative.Style.t)=?,
          ~markingType: option(string)=?,
          ~children,
        )=> React.element = "Calendar";
  };