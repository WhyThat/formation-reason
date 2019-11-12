[@react.component]
let make = (~checked, ~title, ~className) =>
  <li className>
    <div className="view">
      <input className="toggle" type_="checkbox" checked />
      <label> {ReasonReact.string(title)} </label>
      <button className="destroy" />
    </div>
  </li> /*   value={state.editText*/;

// <input
//   className="edit"