include Common;

let windowEventListener = [%bs.raw {| window.addEventListener |}];
let initWindowListener = (reduce): unit => {
  windowEventListener("popstate", (_evt) => {
    let path = _evt##state##path;
    let placeId = _evt##state##placeId;
    reduce((_) => ChangePath(path,placeId))();
  });
};

let component = ReasonReact.reducerComponent("App");

let make = (_) => {
  ...component,
  initialState: () => {
    path: "",
    placeId: "",
  },
  didMount: ({reduce}) => {
    let match: array(string) = [%bs.raw {| /^(\/*[A-Za-z0-9_]*)(\/([A-Za-z0-9\s]+))*/.exec(window.location.pathname) |}];
    addToWindowState(match[1],match[3]);
    initWindowListener(reduce);
    ReasonReact.Update({
      path: match[1],
      placeId: match[3],
    });
  },
  reducer: (action, _) => switch action {
    | ChangePath(path, placeId) => {
      ReasonReact.Update({path,placeId}) }
  },
  render: ({state: {path,placeId}, reduce}) => {
    <div>
      (switch (path,placeId) {
        | ("/", str) when str === "" => <PlaceList reduce />
        | ("/place", placeId) => <PlaceDetail placeId=(int_of_string(placeId)) />
        | _ => <PlaceList reduce />
      })
    </div>
  }
};
