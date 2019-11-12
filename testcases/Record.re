open Setup;
open ReasonFormation.Record;

let users = [
  // remove 10
  ({lastName: "firstname", age: 60}, 50),
  ({lastName: "firstname", age: 65}, 55),
  // remove 5
  ({lastName: "firstname", age: 50}, 45),
  ({lastName: "firstname", age: 51}, 46),
  // remove 2
  ({lastName: "firstname", age: 30}, 28),
  ({lastName: "firstname", age: 49}, 47),
  // do nothing
  ({lastName: "firstname", age: 29}, 29),
  ({lastName: "firstname", age: 0}, 0),
];

Setup.describe("MagicCream", ({test}) =>
  List.iter(
    ((user, result)) => {
      test(
        string_of_int(user.age)
        ++ " years old user should now looks like "
        ++ string_of_int(result),
        ({expect}) =>
        expect.int(ReasonFormation.Record.magicCream(user).age).toBe(result)
      )
    },
    users,
  )
);