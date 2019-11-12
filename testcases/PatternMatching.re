open Setup;
open ReasonFormation.Util;

Setup.describe("Beatles", ({test}) => {
  test("Lennon", ({expect}) =>
    expect.string(ReasonFormation.PatternMatching.getBeatleLastName(John)).
      toEqual(
      "Lennon",
    )
  );
  test("McCartney", ({expect}) =>
    expect.string(ReasonFormation.PatternMatching.getBeatleLastName(Paul)).
      toEqual(
      "McCartney",
    )
  );
  test("Harrisson", ({expect}) =>
    expect.string(ReasonFormation.PatternMatching.getBeatleLastName(George)).
      toEqual(
      "Harrisson",
    )
  );
  test("Starr", ({expect}) =>
    expect.string(ReasonFormation.PatternMatching.getBeatleLastName(Ringo)).
      toEqual(
      "Starr",
    )
  );
});
