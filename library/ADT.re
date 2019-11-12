/*
 * Lorsque les types de base ne suffisent plus, on peut combiner des types pour en obtenir
 * de nouveaux. Ces types riches permettent de modéliser notre domaine avec précision tout
 * en profitant de la sécurité offerte par la phase de compilation.
 *
 * En Scala, il existe plusieurs manières "d'assembler" les valeurs de différents type
 * en un seul type.
 *
 * Les types qui combinent les valeurs de plusieurs types sont appelés "type produits"
 * en référence au produit cartésien (l'ensemble des couples de valeurs de plusieurs ensembles)
 */

// Les records
type movie = {
  title: string,
  releaseOn: string,
};

// Les tuples
type position = (float, float);

/*
 * Il est aussi possible de combiner des types de manières disjointe, c'est à dire par enumeration des
 * valeurs distinctes de ce type.
 */

type beatles =
  | John
  | Paul
  | George
  | Ringo;

/*
 * Ce type de structure, appellé "type somme", est parfois appelé Enum, ou Union discriminée, ou
 * Union disjointe.
 *
 * Vous en connaissez déjà!
 */

type option('a) =
  | None
  | Some('a);

/*
 * Un type de données algébrique (Algebraic data type ou ADT) est un type qui est une combinaison
 * de types sommes et de types produits
 *
 * Ici, la représentation d'un arbre binaire contenant des entiers
 *
 *        1
 *     +-----+
 *    2|     3
 *  +----+     +----+
 *  4   6      5    7
 */

type tree =
  | Leaf
  | Node(int, tree, tree);

let myTree =
  Node(
    1,
    Node(2, Node(4, Leaf, Leaf), Node(6, Leaf, Leaf)),
    Node(3, Node(5, Leaf, Leaf), Node(7, Leaf, Leaf)),
  );

/*
 * Nous avons aussi la possibilité d'avoir des variant polymorphique ce qui permet  un peu plus de souplesse dans certain cas
 */
type colors = [ | `red | `blue | `yellow];
module BackgroundColor = {
  type backgroundColors = [ | `red];
  let getColor = (color: backgroundColors) => (color :> colors);
};