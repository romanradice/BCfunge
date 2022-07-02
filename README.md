# BCfunge

## Project
A simple Befunge interpreter

## About Befunge language
Befunge is a two-dimensional esoteric programming language invented in 1993 by Chris Pressey with the goal of being as difficult to compile as possible. Code is laid out on a two-dimensional grid of instructions, and execution can proceed in any direction of that grid. 

## Instructions
Befunge-93 has the following commands:
| Cmd  | Description  |
|---|---|
| +  | Addition: Pop two values a and b, then push the result of a+b  |
| -  | Subtraction: Pop two values a and b, then push the result of b-a  |
| *  | Multiplication: Pop two values a and b, then push the result of a*b  |
| /  | Integer division: Pop two values a and b, then push the result of  b/a, rounded down. According to the specifications, if a is zero, ask  the user what result they want.  |
| %  | Modulo: Pop two values a and b, then push the remainder of the integer division of b/a.  |
| !  | Logical NOT: Pop a value. If the value is zero, push 1; otherwise, push zero.  |
| `  | Greater than: Pop two values a and b, then push 1 if b>a, otherwise zero.  |
| >  | PC direction right  |
| <  | PC direction left  |
| ^  | PC direction up  |
| v  | PC direction down  |
| ?  | Random PC direction  |
| _  | Horizontal IF: pop a value; set direction to right if value=0, set to left otherwise  |
| \|  | Vertical IF: pop a value; set direction to down if value=0, set to up otherwise  |
| "  | Toggle stringmode (push each character's ASCII value all the way up to the next ")  |
| :  | Duplicate top stack value  |
| \  | Swap top stack values  |
| $  | Pop top of stack and discard  |
| .  | Pop top of stack and output as integer  |
| ,  | Pop top of stack and output as ASCII character  |
| #  | Bridge: jump over next command in the current direction of the current PC  |
| g  | A "get" call (a way to retrieve data in storage). Pop two values y  and x, then push the ASCII value of the character at that position in  the program. If (x,y) is out of bounds, push 0  |
| p  | A "put" call (a way to store a value for later use). Pop three  values y, x and v, then change the character at the position (x,y) in  the program to the character with ASCII value v  |
| &  | Get integer from user and push it  |
| ~  | Get character from user and push it  |
| @  | End program  |
| 0 – 9  | Push corresponding number onto the stack  |

## Example

Hello, World!
```shell
"!dlroW ,olleH">:v
               |,<
               @
```

Factorial
```shell
&>:1-:v v *_$.@ 
 ^    _$>\:^
```
