module Top = {
  [@react.component]
  let make = () =>
    <React.Fragment>
      <header className="header">
        <h1> {ReasonReact.string("todos")} </h1>
        <input
          className="new-todo"
          placeholder="What needs to be done?"
          autoFocus=true
        />
      </header>
      <section className="main">
        <input className="toggle-all" type_="checkbox" />
        <ul className="todo-list">
          <TodoItem
            title="Taste ReasonML"
            checked=false
            className="completed"
          />
          <TodoItem title="Buy an unicorn" checked=true className="" />
        </ul>
      </section>
      <TodoFooter />
    </React.Fragment>;
};

ReactDOMRe.renderToElementWithClassName(<Top />, "todoapp");