type t = Js.Date.t;

let addDays = (date, days) => {
  open Js.Date;
  let newDate = fromFloat(valueOf(date));
  setDate(newDate, getDate(newDate) +. days) |> ignore;
  newDate;
};
[@bs.val] [@bs.module "date-fns"]
external dateFormat: (t, string) => string = "format";

[@bs.val] [@bs.module "date-fns"] external dateParse: string => t = "parse";

let parse = s => s |> dateParse;

type format =
  | OnlyDate
  | DateAndTime
  | DDD
  | DateWithYearAndTime;

let format = (f, t) => {
  let formatString =
    switch (f) {
    | OnlyDate => "Do MMM YYYY"
    | DateAndTime => "MMM D HH:mm"
    | DDD => "ddd"
    | DateWithYearAndTime => "Do MMM YYYY HH:mm"
    };
  dateFormat(t, formatString);
};

let stingToFormatedTime = (f, t) => format(f, parse(t));