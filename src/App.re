include Common;

let path: string = [%bs.raw {| window.location.pathname |}];
let match = [%bs.raw {| /((^\/[A-Za-z0-9]*)\/([A-Za-z0-9_]+)?)/.exec(path) |}];

let component = ReasonReact.statelessComponent("App");

let make = (_) => {
  ...component,
  render: (_) => {
    <div>
      (switch match[2] {
        | "/" => <PlaceList />
        | "/place" => match[3] ? <PlaceDetail /> : <PlaceList />
      })
    </div>
  }
};
