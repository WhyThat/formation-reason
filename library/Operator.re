/*
 * On peut aussi définir des opérateurs, afin d'aller plus vite sur certaine
 * opération. par exemple nous allons redéfinir le symbole `/` (l'opérateur
 * permettant la division entre int ne pourra donc plus etre utilisée dans ce
 * module) afin qu'il fasse
 * une concaténation de string comme le ferai `++``
 */
let (/) = (str1, str2) => str1 ++ "/" ++ str2;
let prefixedStr = "Hello " / " word"; // =>
let (or) = (a, b) =>
  switch (a) {
  | Some(a') => a'
  | None => b
  };

let stringOrSomething = Some("test") or "something"; // => "test"

/*
 * Ecrire un opérateur (>>|) qui permet de faire un map sur une option
 * let double12 = Some(12) >>| double // => Some(24)
 */
let (>>|) = (v, f) => v;

let double = value => value * 2;
let double12 = Some(12) >>| double;