open TestFramework;

describe("TestFramework", ({test}) => {
  test("runs simple tests", ({expect}) => {
    expect.int(1 + 1).toBe(2);
    expect.int(1 + 1 + 1).toBe(3);
    expect.bool(true).toBe(true);
    expect.float(1.0).toBeCloseTo(1.0);
    expect.string("hello").not.toEqual("goodbye");
    expect.string("").toBeEmpty();
    expect.arrayOf(Int, [|1, 2, 3|]).toEqual([|1, 2, 3|]);
    expect.listOf(String, ["a", "b"]).toEqual(["a", "b"]);
    expect.value(Ok(1)).toEqual(Ok(1));
  });

  test("produces snapshots", ({expect}) => {
    expect.string("hello").toMatchSnapshot();
    expect.value({"id": 1}).toMatchSnapshot();
  });
});
