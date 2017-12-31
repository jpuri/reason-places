include Common;
let gotoHome = (reduce) => {
  reduce((_) => ChangePath("/", ""))();
  addToWindowState("/", "");
};

let component = ReasonReact.statelessComponent("PlaceList");

let make = (~placeId, ~reduce, _) => {
  ...component,
  render: (_) => {
    let placeRecord = List.find(place => place.id === placeId, PlaceData.placeList);
    <div className="place-details-wrapper">
      <div className="back-nav">
        <a onClick=((_) => gotoHome(reduce)) className="home-link">
          (str("<<  Back"))
        </a>
      </div>
      <h1>(str(placeRecord.name))</h1>
      <img src=("/img/" ++ placeRecord.img)/>
      <div>
        (str(placeRecord.details))
      </div>
    </div>
  }
};
