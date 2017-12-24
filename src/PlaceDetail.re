include Common;

let component = ReasonReact.statelessComponent("PlaceList");

let make = (~place, _) => {
  ...component,
  render: (_) => {
    <div>
      <h1>(str(place))</h1>
      <div>
        (str("This will be details."))
      </div>
    </div>
  }
};
