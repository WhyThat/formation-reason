/*
 * Les types permette de définir structurellemeent les choses
 * Ci dessous, un type `record`
 */
type user = {
  lastName: string,
  age: int,
};

/* Type variant */
type animal =
  | Cat
  | Dog;

/*
 * EXERCICE : vous programmez un anti-âge. Écrivez une fonction qui prend un User
 * et réduit son âge
 *   - de 10 ans si la personne a 60 ans ou plus
 *   - 5 ans si la personne a 50 ans ou plus
 *   - 2 ans si la personne a 30 ans ou plus
 *   - 0 si la personne a moins de 30 ans
 */

let magicCream: user => user =
  user =>
    switch (user) {
    | {age} when age >= 60 => {...user, age: age - 10}
    | {age} when age >= 50 => {...user, age: age - 5}
    | {age} when age >= 30 => {...user, age: age - 2}
    | _ => user
    };