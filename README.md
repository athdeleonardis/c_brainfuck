# C_BRAINFUCK

Source code for a Brainfuck interpreter, written in c.

Brainfuck is a minimalist esoteric programming language which only
allows for incrementing and decrementing an integer pointer and it's value.

The original syntax has been slightly adapted to make the language more useable.

": Start and end comments.
>: Move pointer right.
<: Move pointer left.
+: Increment the pointer's value.
-: Decrement the pointer's value.
,: Read an integer from the command line.
.: Write an integer to the command line,
r: Read a character from the command line.
w: Write a character to the command line.
[: Start a while loop.
]: End the while loop if the pointer's value is zero.

## Requirements

Requires gcc, make and a linux terminal because.

## Build

Run make in the base directory. This will output the file 'bf_interpreter' in the build folder.

## License

[MIT](https://choosealicense.com/licenses/mit/)
