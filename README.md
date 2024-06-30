# Get_next_line

The 42 school's get_next_line project is where we learn to read from a file descriptor, as well as the use of static variables.

This function returns a single line from a given file descriptor. If called in a loop, get_next_line returns the entire contents of a file, line by line until it reaches the end of the file. It can be compiled specifying any buffer size.

---

## Status

Finished: 16/05/2024.
Grade: 125/100.

## Usage
This function is not a stand-alone program, its files must be included and compiled within another project.


Compilation:
```bash
cc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can be specified at compilation to override the default ``BUFFER_SIZE``:
```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
Execution:
```bash
./a.out [file]
```
Output should show the entire contents of the given file.

```
Program will wait for input, then once the enter key is pressed, print out the input as well as get_next_line's output. The process can be killed with ``ctrl-c``.
