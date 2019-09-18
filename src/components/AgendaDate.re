open ReactNative;
open AppStyle.AgendaDate;
open Types;
let addFormat = time => {
  Js.log2("time_start", time);

  let time = DateTime.addDays(time, 1.);
  Js.log2("addDays", time);
  let time = time->Js.Date.toString;
  let format = time |> DateTime.stingToFormatedTime(DDD);
  Js.log2("formatted", format);
  format;
};
let tstamp = Js.Date.make();

addFormat(tstamp);
[@react.component]
let make = (~day: calendarEventPayload, ~item: agendaEvent) => {
  let tstamp = day.timestamp->Js.Date.fromString;
  <View style=styles##container>
    <Text style=styles##date> {day.day->string_of_int->React.string} </Text>
    <Text style=styles##day> {addFormat(tstamp)->React.string} </Text>
  </View>;
};