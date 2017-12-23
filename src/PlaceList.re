include Common;

let component = ReasonReact.statelessComponent("PlaceList");

let make = (_) => {
  ...component,
  render: (_) => {
    <div>
      <h1>(str("My Places"))</h1>
      <div className="place-list">
        <Place place=List.nth(PlaceData.placeList, 0) />
        <Place place=List.nth(PlaceData.placeList, 1) />
        <Place place=List.nth(PlaceData.placeList, 2) />
        <Place place=List.nth(PlaceData.placeList, 3) />
        <Place place=List.nth(PlaceData.placeList, 4) />
      </div>
    </div>
  }
};
