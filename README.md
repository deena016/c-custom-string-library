# c-custom-string-library
C implementation of a custom string ADT using dynamic memory allocation, supporting append, trim, and safe memory management.

This project implements a custom string Abstract Data Type (ADT) in C using dynamic memory allocation.
The MY_STRING object stores characters in a heap-allocated array and provides functions for modifying and managing string data safely.

## Features
- Create strings from C-style input
- Append characters dynamically
- Trim characters from a specified index
- Print string contents and size
- Safely free all allocated memory

## How It Works
The MY_STRING struct stores:
- A pointer to a dynamically allocated character array (`strData`)
- The current size of the string (`size`)

Unlike standard C strings, this implementation:
- Does **not use a null terminator**
- Tracks string length manually
- Resizes memory using `realloc` when needed

## Example Operations
- Append characters to grow the string
- Trim characters to shrink the string
- Completely erase and rebuild strings

## Project Structure
- `main.c` – Demonstrates and tests all MY_STRING functionality
- `my_string.c` – Implementation of string operations
- `my_string.h` – Interface and struct definition
- `analysis.txt` – Explanation of memory usage and design decisions

## Concepts Demonstrated
- Dynamic memory allocation (`malloc`, `realloc`, `free`)
- Pointer manipulation
- Abstract Data Type (ADT) design
- Manual memory management
- Error handling for allocation failures
- Modular programming in C

