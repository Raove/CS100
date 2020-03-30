# CS 100 Programming Project
Winter Quarter 2020  
Raoul Larios SID 861229725  
Parker Colline SID 862152580

# Introduction
We will be developing a terminal in C++ called RShell that functions just like any normal terminal. We have to be able to use commonly used commands in our command line interface and have to execute the commands given within our own terminal. Commands will follow a specific format ``$ executable [argumentList] [connector] [executable] ...`` where `||`, `&&` or `;` are the only connectors allowed. We will have to use `fork`, `execvp`, and `waitpid` command to run the executables. We need to run these commands until an exit command is input.

# Diagram
![RShell OMT](images/RShell%20Diagram.png)

# Classes
* main.cpp
  * file that displays `$` input screen and takes in commands in a string that passes it to the Parser.
* Parser.hpp
  * file that parses through string input to know what is being asked to do, it places commands in a vector of strings and passes it to Tokenizer.
* Tokenizer.hpp
  * file that parses through a vector of strings and puts commands into their own class Command, arguments into their own class Argument, and connectors into their own class Connector. Which then passes those classes to ShuntingYard.
* ShuntingYard.hpp
  * file that turns the commands, arguments, and connectors into the executables to run.
* Executable.hpp
  * file that uses `fork`, `execvp`, and `waitpid` command to run the executables.
* Token.hpp
  * file that is the parent class for Command, Argument, and Connectors.
* Command.hpp
  * file that is the Command class that saves the command part of the string. (ex: "echo")
* Argument.hpp
  * file that is the Argument class that saves the argument part of the string for the commands. (ex: "Hello World")
* Paren.hpp
  * file that is used to assign parenthesis `()` as connectors and then delete.
* And.hpp
  * file that has the logic for the `&&` connector and runs commands to the logic.
* Or.hpp
  * file that has the logic for the `||` connector and runs commands to the logic.
* Semicolon.hpp
  * file that has the logic for the `;` connector and runs commands to the logic.

# Prototypes/Research
The parser class and corresponding function takes in the input as a string and reads it character by character and stores it in an array of strings. Execvp executes the command that is passed in as an argument. The fork in main creates a new process and executes it. Waitpid waits for the child process to finish and then returns whether the process has finished.

Unchanged

# Development and Testing Roadmap
Code files and write test cases for every file and commands
* - [x] main.cpp
  * - [x] Display `$` on the screen and take in input
* - [x] Parser.hpp
  * - [x] Parse string input into a vector of strings
* - [x] Tokenizer.hpp
  * - [x] Separate parts of the vector string into Commands, Arguments, and Connectors
* - [x] ShuntingYard.hpp
  * - [x] Run shunting yard algorithm for the executes
  * - [x] Can be Postfix notation
  * - [x] Can be Prefix notation
* - [x] Tree.hpp
    * - [x] Make binary tree from Prefix notation
    * - [x] Make binary tree from Postfix notation
    * - [x] Run commands from tree
* - [x] Token.hpp
    * - [x] Command.hpp
        * - [x] Save Command
    * - [x] Argument.hpp
        * - [x] Save Argument
    * - [x] Or.hpp -- And.hpp -- Semicolon.hpp
      * - [x] Working connector `||`
      * - [x] Working connector `&&`
      * - [x] Working connector `;`
      * - [x] Working connector `(`
      * - [x] Working connector `)`
* - [x] Executable.hpp
  * - [x] Run commands 

