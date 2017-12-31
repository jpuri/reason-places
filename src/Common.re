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

type event = {
  state: state
};

type action = ChangePath(string, string);

let addToWindowState: (string, string) => unit = [%bs.raw
  {|
    function (path, placeId) {
      window.history.pushState({path: path, placeId: placeId}, '', path + (placeId ? '/' + placeId : ''));
    }
  |}
];
