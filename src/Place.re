include Common;
let component = ReasonReact.statelessComponent("Place");
let make = (~place, _) => {
  ...component,
  render: (_) => {
    <div className="place">
      <img src=(place.img)/>
      <span>
        (str(place.desc))
      </span>
    </div>
  }
};
