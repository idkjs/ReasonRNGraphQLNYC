type calendarEventPayload = {
  day: int,
  month: int,
  year: int,
  timestamp: string,
  dateString: string,
};

type cgendaEvent = {
  type_: string,
  title: string,
  description: string,
  link: string,
};
// type venue = {
//   name: string,
//   lat: float,
//   lon: float,
// };
type event = {
  time: string,
  name: string,
  // description: string,
  // status: string,
  // link: string,
  venue,
} and venue = {
  name: string,
  lat: float,
  lon: float,
};