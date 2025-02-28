# Mini Libc

Mini Libc is a minimal implementation of the standard C library.

## Features
- Standard C library functions implemented with syscalls.
- Minimal overhead and optimized for performance.
- Suitable for embedded systems and minimal operating environments.

## Implementation Details

### Syscalls
The core of Mini Libc's functionality is based on direct syscalls.

- **Syscall Interface:**
  - Each function in Mini Libc directly invokes the syscall using inline assembly or syscall wrapper functions.
  - Syscalls are mapped to function names, for example, the `write` syscall is invoked within the `printf` function to output text to the standard output.

- **Error Handling:**
  - Syscall return values are checked to determine success or failure.
  - If a syscall fails, the appropriate error code is returned, and additional error handling mechanisms are implemented to manage these errors gracefully.

### Standard I/O
Mini Libc provides basic input/output functionalities through syscalls.

- **Formatted Output (`printf`):**
  - The `printf` function formats a string and uses the `write` syscall to output the formatted text.
  - It supports basic format specifiers like `%d`, `%s`, `%x`, etc.

- **Formatted Input (`scanf`):**
  - The `scanf` function reads formatted input from the standard input using the `read` syscall.
  - It parses the input based on specified format specifiers.

- **File Operations (`fopen`, `fread`, `fwrite`, `fclose`):**
  - `fopen` creates a file descriptor using the `open` syscall.
  - `fread` reads data from a file using the `read` syscall.
  - `fwrite` writes data to a file using the `write` syscall.
  - `fclose` closes a file descriptor using the `close` syscall.

### Memory Management
Memory management functions are implemented using syscalls for dynamic memory allocation.

- **Dynamic Memory Allocation (`malloc`, `free`, `realloc`):**
  - `malloc` allocates memory by increasing the program's data space using the `brk` or `mmap` syscall.
  - `free` deallocates memory by releasing it back to the system.
  - `realloc` resizes an allocated memory block, possibly moving it to a new location.

- **Zeroed Memory Allocation (`calloc`):**
  - `calloc` allocates memory and initializes it to zero using `malloc` followed by `memset`.

### String Manipulation
Standard string manipulation functions are included.

- **Basic Functions:**
  - `strcpy`, `strncpy`: Copy strings from source to destination.
  - `strcmp`, `strncmp`: Compare two strings.
  - `strlen`: Calculate the length of a string.
  - `strcat`, `strncat`: Concatenate two strings.

- **Memory Functions:**
  - `memcpy`: Copy memory area.
  - `memset`: Fill memory with a constant byte.
  - `memcmp`: Compare memory areas.

### Additional Functionalities
- **Math Functions:**
  - Basic mathematical functions like `abs`, `sqrt`, and `pow` are implemented.
  - These functions are optimized for performance on minimal operating environments.

- **Time Functions:**
  - Functions to retrieve and manipulate time, such as `time`, `localtime`, and `strftime`.
  - These functions use syscalls to interact with the system clock.
