include Common;

let component = ReasonReact.statelessComponent("PlaceList");

let make = (~placeId, _) => {
  ...component,
  render: (_) => {
    let placeRecord = List.find(place => place.id === placeId, PlaceData.placeList);
    <div className="place-details-wrapper">
      <h1>(str(placeRecord.name))</h1>
      <img src=("/img/" ++ placeRecord.img)/>
      <div>
        (str(placeRecord.details))
      </div>
    </div>
  }
};
