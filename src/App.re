include Common;

let path: string = [%bs.raw {| window.location.pathname |}];
let match = [%bs.raw {| /(\/[A-Za-z0-9_]*)(\/([A-Za-z0-9_]+))*/.exec(path) |}];

let component = ReasonReact.statelessComponent("App");

let make = (_) => {
  ...component,
  render: (_) => {
    <div>
      (switch (match[1],match[3]) {
        | ("/", None) => <PlaceList />
        | ("/place", None) => <PlaceList />
        | ("/place", _) => <PlaceDetail place=match[3]/>
        | _ => <PlaceList />
      })
    </div>
  }
};
