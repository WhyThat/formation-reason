# reason-formation


[![CircleCI](https://circleci.com/gh/yourgithubhandle/reason-formation/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/reason-formation/tree/master)


**Contains the following libraries and executables:**

```
reason-formation@0.0.0
│
├─test/
│   name:    TestReasonFormation2.exe
│   main:    TestReasonFormation2
│   require: reason-formation.lib
│
├─library/
│   library name: reason-formation.lib
│   namespace:    ReasonFormation2
│   require:
│
└─executable/
    name:    ReasonFormation2App.exe
    main:    ReasonFormation2App
    require: reason-formation.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x ReasonFormation2App.exe
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
