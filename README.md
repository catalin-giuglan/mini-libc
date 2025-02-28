# Mini Libc

Mini Libc is a minimal implementation of the standard C library.

## Features
- Standard C library functions implemented with syscalls.
- Minimal overhead and optimized for performance.
- Suitable for embedded systems and minimal operating environments.

## Implementation Details

### Syscalls
The core of Mini Libc's functionality is based on direct syscalls.

- **Syscall Interface:** Each function in Mini Libc directly invokes the syscall.
- **Error Handling:** Syscall return values are checked, and appropriate error handling is implemented.

### Standard I/O
Mini Libc provides basic input/output functionalities through syscalls.

- `printf`: Formatted output to standard output.
- `scanf`: Formatted input from standard input.
- `fopen`, `fread`, `fwrite`, `fclose`: Basic file operations using syscalls.

### Memory Management
Memory management functions are implemented using syscalls for dynamic memory allocation.

- `malloc`, `free`, `realloc`: Memory allocation functions use the `brk` or `mmap` syscalls.
- `calloc`: Allocates and zeroes memory using `malloc` and `memset`.

### String Manipulation
Standard string manipulation functions are included.
