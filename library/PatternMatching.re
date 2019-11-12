/*
 * Le pattern matching est une des fonctionnalités les plus puissantes et les plus utilisés du langage.
 * Il s'agit d'associer une expression, à gauche, à une autre, à droite. L'expression de gauche peut
 * être déstructurée et associée selon des conditions arbitraires.
 *
 * Voyez le comme un switch sous stéroïdes.
 *
 * Voilà une implémentation de FizzBuzz en Reason :
 */
let fizzbuzz = value =>
  switch (value mod 3, value mod 5) {
  | (0, 0) => "fizzbuzz"
  | (0, _) => "fizz"
  | (_, 0) => "buzz"
  | _ => string_of_int(value)
  };

/*
 * ReasonML a une syntaxe qui permet de faire un switch directement sur
 * l'argument passé à une fonction
 * voyez l'équivalence ci dessous
 */
type t =
  | One
  | Two;

let getValue = value =>
  switch (value) {
  | One => "One"
  | Two => "two"
  };
let getValueWithFun =
  fun
  | One => "One"
  | Two => "two";
/*
 * Le pattern matching est particulièrement utile avec les types somme
 *
 * --------------------------------
 * EXERCICE :
 * Compléter la fonction ci-dessous pour renvoyer le nom de famille de tous
 * les Beatles.
 * (Les résultats attendus sont dans les tests)
 */

let getBeatleLastName: ADT.beatles => string =
  fun
  | John => "Lennon"
  | Paul => "McCartney"
  | George => "Harrisson"
  | Ringo => "Starr";
