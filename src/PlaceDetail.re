include Common;

let component = ReasonReact.statelessComponent("PlaceList");

let make = (_) => {
  ...component,
  render: (_) => {
    <div>
      <h1>(str("My Place"))</h1>
      <div>
        (str("This will be details."))
      </div>
    </div>
  }
};
