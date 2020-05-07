# Reason Test Framework

![Node.js CI](https://github.com/bloodyowl/reason-test-framework/workflows/Node.js%20CI/badge.svg?branch=master)

> A test framework for Reason compiled to JS with BuckleScript

**Reason Test Framework** aims to give a simple API for your tests, making them readable. It produces code that [Jest](https://jestjs.io) can consume.

## Installation

Run the following in your console:

```console
$ yarn add --dev reason-test-framework
$ yarn add --dev jest # if you don't have it already
```

Then add `reason-test-framework` to your `bsconfig.json`'s `bs-dependencies`:

```diff
 {
   "bs-dependencies": [
+    "reason-test-framework"
   ]
 }
```

## Usage

```reason
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
```

## ES Modules

If you use the `es6` or `es6-global` configurations in BuckleScript, you'll need to install `babel-jest` for your tests to run.

## Aknowledgments

These bindings, which look like [Rely](https://reason-native.com/docs/rely/), were originally shared from the [Reason Native](https://github.com/facebookexperimental/reason-native) repo by [Ben Anderson](https://github.com/bandersongit) 🙏
