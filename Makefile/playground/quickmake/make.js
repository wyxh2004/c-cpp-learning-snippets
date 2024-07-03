let makefile_run = (self) => {
    if (self.rules.length === 0)
        throw new Error("No rules found in the makefile");
    // 从第一条规则开始递归执行
    let first_rule = self.rules[0];
    eval_rule(first_rule, self.rules);
};
// make 的核心算法
let eval_rule = (current_rule, rules) => {
    for (let p of current_rule.prerequisites) {
        let next_rule = rules.find(({ target }) => target === p);
        if (next_rule === undefined) {
            continue;
        }
        eval_rule(next_rule, rules); // recursive call
    }
    console.log(`running command "${current_rule.commands.join(" ")}"`);
};
let sample_makefile = {
    rules: [
        {
            target: "build/main.hex",
            prerequisites: ["build/main.elf"],
            commands: ["objcopy -O ihex build/main.hex build/main.elf"],
        },
        {
            target: "build/main.elf",
            prerequisites: ["main.o", "blah.o"],
            commands: ["cc main.o blah.o build/main.elf"],
        },
        {
            target: "main.o",
            prerequisites: ["main.c", "blah.h"],
            commands: ["cc main.c -o main.o"],
        },
        {
            target: "blah.o",
            prerequisites: ["blah.c", "blah.h"],
            commands: ["cc -c blah.c -o blah.o"],
        },
    ],
};
makefile_run(sample_makefile);
