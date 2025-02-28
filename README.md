Mini Libc
Mini Libc is a minimal implementation of the standard C library, designed to provide essential functionalities using direct syscalls. This library is tailored for environments where a full-fledged libc is unnecessary or unavailable, such as embedded systems or minimal operating systems.

Features
Standard C library functions implemented with syscalls.
Minimal overhead and optimized for performance.
Suitable for embedded systems and minimal operating environments.
Table of Contents
Installation
Usage
Implementation Details
Syscalls
Standard I/O
Memory Management
String Manipulation
Mathematical Functions
Contributing
License
Installation
To build and install Mini Libc, follow these steps:

sh
git clone https://github.com/catalin-giuglan/mini-libc.git
cd mini-libc
make
sudo make install
Usage
Include Mini Libc headers in your C code:

C
#include <mini-libc.h>
Link against Mini Libc during compilation:

sh
gcc -o my_program my_program.c -lminic
Implementation Details
Syscalls
The core of Mini Libc's functionality is based on direct syscalls to the underlying operating system. This approach minimizes the overhead and ensures that the library remains lightweight.

Syscall Interface: Each function in Mini Libc directly invokes the appropriate syscall using inline assembly or dedicated syscall wrappers.
Error Handling: Syscall return values are checked, and appropriate error codes are set using errno.
Standard I/O
Mini Libc provides basic input/output functionalities through syscalls.

printf: Formatted output to standard output.
scanf: Formatted input from standard input.
fopen, fread, fwrite, fclose: Basic file operations using syscalls like open, read, write, and close.
Memory Management
Memory management functions are implemented using syscalls for dynamic memory allocation.

malloc, free, realloc: Memory allocation functions use the brk or mmap syscalls.
calloc: Allocates and zeroes memory using malloc and memset.
String Manipulation
Standard string manipulation functions are included.

strcpy, strncpy: Copy strings.
strlen: Calculate the length of a string.
strcmp, strncmp: Compare strings.
strcat, strncat: Concatenate strings.
Mathematical Functions
Basic mathematical functions are provided.

abs, fabs: Absolute value functions.
sin, cos, tan: Trigonometric functions.
sqrt: Square root function.
Contributing
Contributions are welcome! Please submit pull requests or open issues on the GitHub repository.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Implementation Details
Syscalls
The core functionality of Mini Libc relies on direct syscalls to the underlying operating system to provide efficient and minimalistic implementations of standard C library functions.

Syscall Interface: Each function directly invokes the appropriate syscall using inline assembly or syscall wrappers. This ensures minimal overhead and direct interaction with the kernel.
Error Handling: Syscall return values are checked rigorously, and appropriate error codes are set using errno to maintain compatibility with standard error handling practices.
Standard I/O
The standard input/output functions are implemented using syscalls to handle file descriptors and data streams.

printf: Utilizes the write syscall to output formatted strings to the standard output.
scanf: Uses the read syscall to read formatted input from the standard input.
fopen, fread, fwrite, fclose: Implement basic file operations using open, read, write, and close syscalls. Buffering and file stream management are handled manually to ensure efficiency.
Memory Management
Memory allocation functions are implemented using syscalls for dynamic memory management.

malloc, free, realloc: Utilize the brk or mmap syscalls to allocate and manage memory. The implementation manages a memory pool and handles fragmentation and resizing.
calloc: Allocates memory using malloc and initializes it to zero using memset.
String Manipulation
Standard string manipulation functions are implemented to provide essential operations on character arrays.

strcpy, strncpy: Copy strings from source to destination, ensuring proper null-termination.
strlen: Computes the length of a string by iterating through the character array until the null terminator is encountered.
strcmp, strncmp: Compare two strings lexicographically, returning a value indicating their relative order.
strcat, strncat: Concatenate strings by appending the source string to the destination string.
Mathematical Functions
Basic mathematical functions are provided to perform common mathematical operations.

abs, fabs: Compute the absolute value of integer and floating-point numbers, respectively.
sin, cos, tan: Implement trigonometric functions using polynomial approximations or lookup tables for efficiency.
sqrt: Calculate the square root of a number using iterative approximation methods.
