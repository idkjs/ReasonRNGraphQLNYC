// open ReasonDateFns;
let tstamp = Js.Date.make();
open Js.Date;

let addDays = (date, days) => {
  let newDate = fromFloat(valueOf(date));
  setDate(newDate, getDate(newDate) +. days) |> ignore;
  newDate;
};
addDays(tstamp, 1.)->Js.log;
let tstamp = Js.Date.now()->int_of_float;
tstamp->Js.log;
let tstamp = Js.Date.now()->Js.Date.fromFloat;
tstamp->Js.log2("tstamp");
addDays(tstamp, 1.)->Js.log /* Js.log2("Test", "TEst")*/ /* |> Js.log*/ /* |> DateFns.addMilliseconds(1000*/;
// DateFns.(addDays(1)|>toDate(tstamp))|>Js.log2("tstamp");
// DateFns.addDays(tstamp,1)|>Js.log2("tstamp")
let tstamp = Js.Date.make()->Js.Date.toString;
tstamp->Js.log;
let _ = DateTime.stingToFormatedTime(OnlyDate, tstamp)->Js.log;
let _ = DateTime.stingToFormatedTime(DateAndTime, tstamp)->Js.log;
let _ = DateTime.stingToFormatedTime(DDD, tstamp)->Js.log;
let _ = DateTime.stingToFormatedTime(DateWithYearAndTime, tstamp)->Js.log;

let addFormat = time => {
    Js.log2("time_start", time);

  let time = addDays(time, 1.);
  Js.log2("addDays", time);
  let time = time->Js.Date.toString;
  let format = time |> DateTime.stingToFormatedTime(DDD);
  Js.log2("formatted", format);
};
let tstamp = Js.Date.make();

addFormat(tstamp) /* Js.Date.make(*/ /* |>


let
DateFns.addSeconds(10.*/ /* |> DateFns.addMinutes(10.*/;

// Js.Date.make()
// |> DateFns.addDays(1)
// |> DateFns.startOfDay
// |> DateFns.setHours(7.)
// |>Js.log2("test");
// |>toDate(tstamp))|>Js.log2("tstamp");

// Js.Date.make()
// |> DateFns.addDays(2)
// |> DateFns.addDays(-2)
// |> DateFns.closestTo([|
//      DateFns.parseISO("2019-08-21T13:00:03.058Z"),
//      Js.Date.make(),
//    |])
// |> DateFns.lightFormat("YYYY-MM-DD")
// |> Js.log;

// Js.Date.make()
// |> DateFns.formatWithOptions(
//      DateFns.formatOptions(~locale=DateFns.Locales.ru, ()),
//      "YYYY-MM-DD",
//    )
// |> Js.log;