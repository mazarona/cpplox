# cpplox
`cpplox` is a tree-walking interpreter of the lox programming language.

# Build
The build uses cmake and make and produces a binary `cpplox` in `build/src` folder

```bash
$ git clone https://github.com/mazarona/cpplox.git
$ cd cpplox
$ cmake -S . -B build
$ cmake --build build
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
