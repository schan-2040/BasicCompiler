# Basic Compiler

This is a basic compiler written in C++ which parses through code of my custom language. The code must be written and saved in a separate file to be opened and parsed. The program must be given a flag along with the filename as a command line argument to analyze the file.

## The Current Behavior of the Program

The program can check to see if the code written in the file is syntactically correct through a **lexographical analyzer** and throws any errors if found.

If none are found, the program will output all lexemes found in the code file using the ```-v``` flag, or will display the most common lexeme found using the ```-mci``` flag

### Example

One example of the basic code can be found under **sample.txt**

A sample command line argument would then be something like:

```-v sample.txt```

The output of that sample would look like this:

![screenshot 6](https://user-images.githubusercontent.com/38062430/45729606-39de6000-bb9b-11e8-8f45-a68e1ee4334e.png)


## Future Plans

In the near future, my plans are to:
- Make the compiler actually carry out the commands written in the code file
- Expand upon the language with loops, data structures, and more keywords
- Refine the code
