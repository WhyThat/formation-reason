module Top = {
  open TodoItem;
  type state = {
    todos: list(TodoItem.todo),
    newTodo: string,
  };
  type action =
    | ToggleTodo(TodoItem.todo)
    | Save(string)
    | ClearCompleted
    | Destroy(TodoItem.todo)
    | Filter(bool)
    | Change(string);

  [@react.component]
  let make = () => {
    let (state, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | ToggleTodo(todoToToggle) => {
              ...state,
              todos:
                Belt.List.map(state.todos, todo =>
                  todo === todoToToggle
                    ? {...todoToToggle, completed: !todoToToggle.completed}
                    : todo
                ),
            }
          | Change(newTodo) => {...state, newTodo}
          | Save(content) => {
              newTodo: "",
              todos:
                state.todos
                @ [
                  {
                    content,
                    id: Js.Date.now()->Js.Float.toString,
                    completed: false,
                  },
                ],
            }
          | Destroy(todoToDestroy) => {
              ...state,
              todos:
                Belt.List.keep(state.todos, todo => todo != todoToDestroy),
            }
          | _ => state
          },
        {newTodo: "", todos: []},
      );

    let todos =
      List.map(
        todo =>
          <TodoItem
            todo
            onToggle={_ev => dispatch(ToggleTodo(todo))}
            onDestroy={_ev => dispatch(Destroy(todo))}
          />,
        state.todos,
      )
      ->Array.of_list
      ->React.array;

    <React.Fragment>
      <header className="header">
        <h1> {ReasonReact.string("todos")} </h1>
        <input
          className="new-todo"
          placeholder="What needs to be done?"
          autoFocus=true
          onChange={event => {
            let value = ReactEvent.Form.target(event)##value;
            dispatch(Change(value));
          }}
          onKeyPress={event =>
            switch (ReactEvent.Keyboard.key(event)) {
            | "Enter" => dispatch(Save(state.newTodo))
            | _ => ()
            }
          }
          value={state.newTodo}
        />
      </header>
      <section className="main">
        <input className="toggle-all" type_="checkbox" />
        <ul className="todo-list"> todos </ul>
      </section>
      <TodoFooter />
    </React.Fragment>;
  };
};

ReactDOMRe.renderToElementWithClassName(<Top />, "todoapp");