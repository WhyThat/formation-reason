/*
 * Module crée pour éviter d'utiliser une lib externe
 */
module Option = {
  let map = f =>
    fun
    | Some(x) => Some(f(x))
    | None => None;

  let getOrElse = (a: 'a, b: option('a)) =>
    switch (b) {
    | Some(x) => x
    | None => a
    };
};
/*
 * Reason utilise un type spécial pour encoder l'absence de valeur.
 * Le type Option est un type générique, qui peut prendre deux valeurs possibles:
 *   - Some(T) : encapsule une valeur de type T
 *   - None : encode l'absence de valeur
 */
// Alias de type!
type parent = string;

let batmanDad: option(parent) = None;
let batgirlDad: option(parent) = Some("Jim Gordon");

/*
 * Ainsi, une fonction qui peut renvoyer ou non une valeur est modelisée comme
 * une fonction renvoyant une Option. Techniquement parlant, une fonction renvoie donc
 * toujours une valeur.
 */
let divide: (float, float) => option(float) =
  (a, b) =>
    if (b == 0.) {
      None;
    } else {
      Some(a /. b);
    };

let t = divide(0., 10.);
/*
 * Il est possible d'appliquer une transformation à une option en utilisant `map`.
 *
 * Si vous avez une Option de A
 * et une fonction de A vers B
 * alors `map` vous donne une Option de B
 *
 * Exemple :
 */
let double: option(int) => option(int) = Option.map(value => value * 2);

let double12 = double(Some(12));
// => Some(24)
let doubleNone = double(None);
// => None

/**
    * `getOrElse` permet de récupérer la valeur de l'option si c'est un Some,
    * ou une valuer par défaut le cas échéant.
    */
let getName: option(string) => string = Option.getOrElse("No Name");

let name1 = getName(Some("Greg"));
// => "Greg"
let name2 = getName(None);
// => "No name"

/*
 * --------------------------------
 * EXERCICE :
 *
 * Écrire une fonction qui prend une option(string) en paramètre et renvoie
 * une option( String ) dont la première lettre texte est en majuscules.
 */
let toUpperCase = _ev => None;

/*
 * ---------------------
 * EXERCICE :
 *
 * Écrire une fonction qui prend en paramètres un nom de famille (String),
 * un prénom (String), et un nom d'utilisateur optionnel (Option[String]) et
 * renvoie soit le nom d'utilisateur défini par l'utilisateur, soit un nom
 * d'utilisateur sous la forme "firstName.lastName"
 *
 */
let getUsername: (string, string, option(string)) => string =
  (firstName, lastName, username) => "";