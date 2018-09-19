# Basic Compiler

This is a basic compiler created in C++ which parses through code of my custom language. The code must be written and saved in a separate file to be opened and parsed. The program must be given a flag along with the filename as a command line argument to analyze the file.

## The Current Behavior of the Program

The program can check to see if the code written in a file is syntactically correct through a **lexographical analyzer** and throw any errors if found.

If none are found, the program will output all lexemes found in the code file

### Example

One example of the basic code can be found under **sample.txt**
A sample command line argument would then be something like:
```-v sample.txt```
The output of that sample would look something like this:

