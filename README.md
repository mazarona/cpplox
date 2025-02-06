# cpplox
`cpplox` is a tree-walking interpreter of the lox programming language.

# Build
The build uses cmake. It produces a binary `cpplox` in `build/cpplox` directory.

```bash
git clone https://github.com/mazarona/cpplox.git
cd cpplox
cmake -S . -B build
cmake --build build
```

# Grammar

```
expression     → literal
               | unary
               | binary
               | grouping ;

literal        → NUMBER | STRING | "true" | "false" | "nil" ;
grouping       → "(" expression ")" ;
unary          → ( "-" | "!" ) expression ;
binary         → expression operator expression ;
operator       → "==" | "!=" | "<" | "<=" | ">" | ">="
               | "+"  | "-"  | "*" | "/" ;
```
