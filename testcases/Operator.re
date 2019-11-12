open Setup;
open ReasonFormation.Operator;

Setup.describe("Operators", ({test}) => {
  test(">>| operator", ({expect}) => {
    let double = value => value * 2;
    expect.option(Some(12) >>| double).toBe(Some(24));
    expect.option(double12).toBe(Some(24));
  })
});