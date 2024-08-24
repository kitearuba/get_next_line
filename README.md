# Get Next Line - README

## Overview
The **Get Next Line** project is an exercise in reading a line of text from a file descriptor in C. It emphasizes the use of static variables and memory management. The goal is to create a function that reads one line at a time from a file, allowing it to work seamlessly with various file descriptors, including standard input.

## Mandatory Part

### Function Prototype
```c
char *get_next_line(int fd);
```

### Description
The `get_next_line` function reads and returns a line from the file descriptor `fd`. Each call to the function returns the next line in the file. The line returned will include the newline character `\n` if one was found. If there are no more lines to read or an error occurs, the function returns `NULL`.

### Features
- **Single Line Reading**: Reads one line at a time, ideal for processing files line-by-line.
- **Buffer Management**: The function uses a user-defined buffer size for reading, which can be adjusted using the `BUFFER_SIZE` macro during compilation.
- **Memory Handling**: All allocated memory is carefully managed to prevent leaks.
  
### Files
- `get_next_line.c`: Contains the main function logic.
- `get_next_line_utils.c`: Includes helper functions used by `get_next_line`.
- `get_next_line.h`: Header file with necessary includes and function prototypes.

### Usage
Compile the program with the desired buffer size:
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```
Call the function repeatedly to read each line:
```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL) {
    // Process the line
    free(line);
}
close(fd);
```

### Constraints
- **Prohibited Functions**: You are not allowed to use `libft`, `lseek`, or global variables.
- **Indeterminate Behavior**: The function's behavior is undefined if the file descriptor changes during execution or if the file is binary.

## Bonus Part

### Additional Features
- **Multiple File Descriptors**: The bonus part extends the functionality to handle multiple file descriptors simultaneously. This means you can call `get_next_line` on different file descriptors without losing the state of each one.
  
### Files for Bonus
- `get_next_line_bonus.c`: Extended logic to manage multiple file descriptors.
- `get_next_line_utils_bonus.c`: Utility functions supporting the bonus features.
- `get_next_line_bonus.h`: Header for the bonus part.

### Compilation
To compile the bonus part:
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

### Testing Multiple FDs
```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);
char *line1, *line2;

line1 = get_next_line(fd1);
line2 = get_next_line(fd2);

// Alternate between file descriptors
free(line1);
free(line2);
close(fd1);
close(fd2);
```

## Notes
- **Static Variables**: The project requires the use of static variables, which persist between function calls. This allows the function to retain state between invocations.
- **Edge Cases**: Consider varying buffer sizes, different file types (e.g., text files, stdin), and simultaneous file descriptors to test the robustness of your implementation.

## Conclusion
This project not only sharpens your skills in file handling and memory management in C but also teaches you to handle more complex scenarios, such as managing multiple file descriptors. Once completed, the `get_next_line` function becomes a useful tool in your C programming arsenal.
