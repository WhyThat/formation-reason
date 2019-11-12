type todo = {
  completed: bool,
  content: string,
  id: string,
};

type state;

[@react.component]
let make = (~todo, ~onDestroy, ~onToggle) =>
  <li className={todo.completed ? "completed" : ""}>
    <div className="view">
      <input
        onChange=onToggle
        className="toggle"
        type_="checkbox"
        checked={todo.completed}
      />
      <label> {ReasonReact.string(todo.content)} </label>
      <button onClick=onDestroy className="destroy" />
    </div>
  </li>;