/*
 * Pour définir une valeur nommée, on utilise val
 *
 * Les valeurs sont immuables par défaut
 */
let a = 10;

/*
 * Le type d'une valeur peut géneralement être inféré. Il peut
 * toutefois être précisé explicitement.
 */
let b: string = "Lorem ipsum dolor sit amet.";

/*
 * Les méthodes en Scala sont définies avec le mot-clé `def`. Le type de chaque argument
 * doit être précisé avec `:`. Le type de retour de la fonction peut géneralement être inféré.
 */
let add = (a: int, b: int) => a + b;

/*
 * Pour spécifier une fonction récursive on utilise le mot clé `rec` entre `let` et le nom de la fonction
 */
let rec factorial = n => n <= 0 ? 1 : n * factorial(n - 1);
/*
 * Les fonctions en Reason renvoient toujours quelque chose. Cerains language font la distinction
 * entre les epxressions (je signifie quelque chose) et les statements (je fais
 * quelque chose), pas Reason.
 *
 * En Reason, toutes les expressions peuvent être réduites à une valeur et toutes les valeurs ont un type.
 * Lorsqu'une epxression n'est utilisée que pour ses effets (e.g. écrire dans la console),
 * son type sera Unit.
 */
let sayHello = (name: string) => print_string("Hello" ++ name ++ "!");

/*
 * Unit est le type contenant une seule valeur `()`
 */
let unit: unit = ();

/*
 * Comme Reason est un langage orienté expression, les structures de contrôle aussi sont
 * des expressions, et peuvent être assignés à des valeurs.
 */
let abs = (x: int) =>
  if (x >= 0) {
    x;
  } else {
    - x;
  };

/*
 * Les accolades délimitemt une epxression sur plusieurs lignes.
 * La valeur effective de l'expression sera celle de la dernière ligne
 *
 * Dans des conditions ...
 */
let isYay = true;
let yayOrNay = if (isYay) {"Yay!"} else {"Nay!"};

/*
 * Mais aussi dans des valeurs nommées
 */
let result = {
  let a = 10;
  let b = 15;
  a + b;
};

/*
 *  En reason, on peut également avoir des arguments avec des labels
 */
let displayName = (~firstName: string, ~lastName: string) =>
  firstName ++ lastName;
let name = displayName(~firstName="Harry", ~lastName="Potter");

/*
 * On peut également définir des arguments optionnel, qui seront traité comme
 * des options, en règle générale on ajoutera un dernier argument de type unit
 * qui permettra de lancer l'execution de la fonction
 */
let run =
    (
      files: list(string),
      ~prefix: option(string),
      ~format: option(string => string)=?,
      (),
    ) =>
  switch (format) {
  | None => List.iter(file => print_string(file), files)
  | Some(format) => List.iter(file => file |> format |> print_string, files)
  };

let runner = run(["file1"]);
// => ( ~prefix: option(string), ~format: option(string => string), unit) => unit
run(["file1"], ()); // => unit
// ou
runner();