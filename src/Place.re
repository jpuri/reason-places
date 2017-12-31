include Common;
let component = ReasonReact.statelessComponent("Place");

let gotoRoute = (placeId, reduce) => {
  reduce((_) => ChangePath("/place", placeId))();
  addToWindowState("/place", placeId);
};

let make = (~place, ~reduce, _) => {
  ...component,
  render: (_) => {
    <div className="place">
      <img src=("/img/" ++ place.img)/>
      <span>
        <h3>(str(place.name))</h3>
        (str(place.desc)) 
        <a onClick=((_) => gotoRoute(string_of_int(place.id), reduce)) className="place_link">
          (str("Details"))
        </a>
      </span>
    </div>
  }
};
