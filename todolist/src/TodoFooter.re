[@react.component]
let make = () => {
  <footer className="footer">
    <span className="todo-count">
      <strong> {React.string("0 ")} </strong>
      {React.string("item left")}
    </span>
    <ul className="filters">
      <li> <a className="selected" href="#/"> {React.string("All")} </a> </li>
      <li> <a href="#/active"> {React.string("Active")} </a> </li>
      <li> <a href="#/completed"> {React.string("Completed")} </a> </li>
    </ul>
    <button className="clear-completed">
      {React.string("Clear completed")}
    </button>
  </footer>;
};