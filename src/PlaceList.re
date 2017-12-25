include Common;

let component = ReasonReact.statelessComponent("PlaceList");

let make = (~reduce, _) => {
  ...component,
  render: (_) => {
    let placeList = Array.of_list(List.map(place => <Place place reduce />, PlaceData.placeList));
    <div>
      <h1>(str("My Places"))</h1>
      (ReasonReact.createDomElement("div", ~props={"className": "place-list"}, placeList))
    </div>
  }
};
