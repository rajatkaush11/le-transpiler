<br />
<p align ="center">
  <a href="https://github.com/VedantParanjape/simpPRU">
    <img src="/images/PYLOX-1(1).png" alt="Logo" width="400" height="400">
  </a>
</p>

# **LE TRANSPILER**
- Basic aim of our project is to convert a custom synatx to a c code using a toy compiler what is flex token generation
## What is a **TRANSPILER** ?
- Transpiler is basically a source to source translator.
------------
### Q) what is difference between a compiler and a transpiler ?
- Basically a compiler converts a high level language to low level language whereas in a transpiler , it converts a high level language to another high level language 
----------


---
## Table of contents 
---
- [About our project](#about-the-project)
- [Implementation details of pylox](#implementation-details-of-pylox)
  - [Lexical analyser](#lexical-analyser)
  - [Parser](#parser)
  - [Code printer](#code-printer)
  - [Language Reference](#language-reference)
  - [Third party apps used](#third-party-apps-used)
- [Examples](#examples)


- [Contributors](con)
 [Acknowledgements and Resources](#acknowledgements-and-resources)
- [Detail documentation](#detail-documentation)

-----
## About the Project
>Converts custom code (PYLOX) to C code, using flex and bison, 

To put it down simply, a transpiler has the following phases
- Lexal Analysis (Lexing)
- Syntax Analysis (Parsing)
- Code generation
----
## implementation details of transpiler
-Lexal Analysis by using flex (process known as lexing)
- syntax analysis by using bison (process known as parsing )
- AST(Abstract  Syntax Tree)
- code generation


------
---
### 1) **LEXING**
- Also known as tokenization , it converts a sequence of characters (string) to lexemes 
- These lexemes passes through lexer and it gives us tokens
- These tokens are then send forward to use in parsing 
- These tokens are defined in [lexer.l](https://github.com/Khushi-Balia/le-transpiler/blob/main/src/lexer.l),

![LEXER](https://qph.cf2.quoracdn.net/main-qimg-bd68eda594e9d8d081b4deafe9b9e092-lq)
----


---

### 2) **Parsing**


- The tokens we get after lexing, are passed through the parser
- On receiving the tokens, it forms a parse tree using it[parse tree ](https://en.wikipedia.org/wiki/Parse_tree  " parse tree ")
- This parse tree is simplified, removing all the extra, syntactic stuff, to give the AST (Abstract Synatx tree)
- Thus, we can say, AST is a compact version of the parse tree
- The grammar of the code is set using bison

- In parse tree , after getting rid of extra comment or other syntactic stuff is present it is passed through AST
- >So the conversion of the tokens to AST is called parsing
- The language grammar is defined in a bison file named [parser.y](https://github.com/Khushi-Balia/le-transpiler/blob/main/src/parser.y).
----
>After this step, we do semantic parsing whose result is an abstract syntax tree, AST is a tree data structure which stores various token as it nodes, such that it can represent the code in an abstract way in memory. 
>
>AST is what represents our language in memory, AST related functions are defined in [ast.c](https://github.com/Khushi-Balia/le-transpiler/blob/main/src/ast.c)
![AST](https://vinaytech.files.wordpress.com/2008/10/img21.png " AST " )

----
### Code printer
The next step in a compiler is to naturally take this AST and turn it into code. This means converting each semantic node into equivalent C code in this case. This code printer is defined in   [code_printer.c](https://github.com/Khushi-Balia/le-transpiler/blob/main/src/code_printer.c)

## Language Reference
Please refer to this language reference [PYLOX](https://github.com/Khushi-Balia/le-transpiler/blob/main/Inspired%20by%20Python%20%2B%20Lox%20%2B%20JS%20language%20-%20PYLOX%20-%20Inspired%20by%20Python%20%2B%20Lox%20.pdf)
## Third party apps used 
- klib
- vex 
>More details on third party apps are present in the resources section 
----
## Contributors

* [Khushi balia](https://github.com/Khushi-Balia)  [Rajat kaushik](https://github.com/rajatkaush11)


---
## Acknowledgements and Resources
* [SRA-VJTI for providing this wonderful opportunity](https://sravjti.in/) Eklavya 2021 
* Special thanks to [Krishna Narayanan](https://github.com/Krishna-13-cyber)
- https://github.com/VedantParanjape/simpPRU/tree/master/src
- [flex and bison theory](https://aquamentus.com/flex_bison.html)
- [third party apps]()
    - [vex](https://github.com/rxi/vec)
    - [ klib](https://github.com/attractivechaos/klib)
    - 
- [Khushi's notes](https://github.com/rajatkaush11/le-transpiler/tree/develop-khushi)

- [Rajat's notes](https://github.com/rajatkaush11/le-transpiler/tree/develop-rajat)
---
## Detail documentation

----


