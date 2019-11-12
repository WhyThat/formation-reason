open Setup;

Setup.describe("Options", ({test}) => {
  test("toUpperCase : Capitalize first letter", ({expect}) =>
    expect.option(ReasonFormation.Options.toUpperCase(Some("mathieu"))).toBe(
      Some("Mathieu"),
    )
  );
  test("toUpperCase :Returns None", ({expect}) =>
    expect.option(ReasonFormation.Options.toUpperCase(None)).toBe(None)
  );
  test("getUsername: Returns username", ({expect}) =>
    expect.string(
      ReasonFormation.Options.getUsername("jean", "reno", Some("JeanReno")),
    ).
      toEqual(
      "JeanReno",
    )
  );
  test("getUsername : Return firstname.lastname", ({expect}) =>
    expect.string(
      ReasonFormation.Options.getUsername("mathieu", "tudisco", None),
    ).
      toEqual(
      "mathieu.tudisco",
    )
  );
});