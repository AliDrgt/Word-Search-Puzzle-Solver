# Word-Search-Puzzle-Solver
This project is a C program that searches for a specified word within a predefined or user-input word search puzzle.


## Features

- Prints the puzzle in a readable format.
- Searches for a given word in four directions: right, left, down, and up.
- Allows the user to either use a built-in puzzle or input a new one.
- Returns the starting index of the word if found.

## Usage

### Compiling the Code

To compile the code, use the following command:

```sh
gcc -o word_search word_search.c
```

### Running the Program

Run the compiled program using:

```sh
./word_search
```

### Program Flow

1. The program will prompt you to choose between using a built-in puzzle or inputting a new one.
2. If you choose to input a new puzzle, you will need to provide each line of the puzzle.
3. The puzzle will be printed to the console.
4. You can then enter a string to search for in the puzzle.
5. The program will return the starting index of the word if found, or -1 if not found.

## Example

Here's an example of how the program works:

1. When prompted, choose whether to use the built-in puzzle or input a new one.
2. If you choose to input a new puzzle, enter each line of the puzzle when prompted.
3. The program will print the puzzle.
4. Enter a string to search for in the puzzle.
5. The program will output the starting index of the word if found.
