type MakeRule = {
  target: string;
  prerequisites: Array<string>;
  commands: Array<string>;
};

type Makefile = {
  rules: Array<MakeRule>;
};

let makefile_run = (self: Makefile) => {
  if (self.rules.length === 0)
    throw new Error("No rules found in the makefile");
  let first_rule = self.rules[0];
};

let eval_rule = (current_rule: MakeRule, rules: Array<MakeRule>) => {};
