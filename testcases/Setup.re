include Rely.Make({
  let re = Str.regexp_string("_esy");
  let executedPath =
    Filename.dirname(Sys.argv[0]);
  let projectPath =
    String.sub(
      executedPath,
      0,
      Str.search_forward(
        re,
        executedPath,
        0
      )
    );

  let config =
    Rely.TestFrameworkConfig.initialize({
      snapshotDir:
        projectPath ++ "/__snapshots__",
      projectDir: projectPath,
    });
});
