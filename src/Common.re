let str = ReasonReact.stringToElement;

type place = {
  id: int,
  img: string,
  name: string,
  desc: string,
  details: string
};

type location = {
  mutable pathname: string
};

type window = {
  mutable location: location
};

type state = {
  path: string,
  placeId: string
};

type action = ChangePath(string);
