include Common;

let path: string = [%bs.raw {| unescape(window.location.pathname) |}];
let match: array(string) = [%bs.raw {| /^(\/*[A-Za-z0-9_]*)(\/([A-Za-z0-9\s]+))*/.exec(path) |}];

let component = ReasonReact.reducerComponent("App");

let make = (_) => {
  ...component,
  initialState: () => {
    let match: array(string) = [%bs.raw {| /^(\/*[A-Za-z0-9_]*)(\/([A-Za-z0-9\s]+))*/.exec(window.location.pathname) |}];
    {
      path: match[1],
      placeId: match[3],
    }
  },
  reducer: (action, _) => switch action {
    | ChangePath(placeId) => {
      ReasonReact.Update({path:"/place",placeId}) }
  },
  render: ({state: {path,placeId}, reduce}) => {
    <div>
      (switch (path,placeId) {
        | ("/", str) when str === "" => <PlaceList reduce/>
        | ("/place", placeId) => <PlaceDetail placeId=(int_of_string(placeId)) />
        | _ => <PlaceList reduce/>
      })
    </div>
  }
};
