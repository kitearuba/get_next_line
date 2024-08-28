# Get Next Line - README

## Overview

The **Get Next Line** project is an exercise in file reading in C, focusing on static variables, memory management, and efficient I/O. The objective is to implement a function that reads one line at a time from a file descriptor, making it possible to process files line-by-line or interact with standard input. This project emphasizes memory safety, modularity, and the efficient handling of multiple file descriptors.

## Mandatory Part

### Function Prototype

```c
char *get_next_line(int fd);
```

### Description

`get_next_line` reads and returns the next line from the file associated with the provided file descriptor `fd`. It will continue returning successive lines on subsequent calls until the end of the file is reached or an error occurs. Each line returned includes the newline character (`\n`) if it is present in the file. When no more lines are available or an error occurs, the function returns `NULL`.

### Features

- **Single Line Reading**: Efficiently reads and returns one line at a time, making it ideal for file processing or input handling that requires line-based reading.
- **Customizable Buffer Size**: Uses a user-defined buffer size for reading. This buffer size can be adjusted using the `BUFFER_SIZE` macro during compilation, allowing for optimization based on specific use cases.
- **Memory Safety**: All dynamically allocated memory is properly managed to avoid memory leaks and ensure smooth program operation.

### Files

- **`get_next_line.c`**: Contains the core logic of the `get_next_line` function.
- **`get_next_line_utils.c`**: Implements helper functions that support the main logic.
- **`get_next_line.h`**: Header file with function prototypes and necessary includes.

### Usage

To use `get_next_line`, compile the program with your desired buffer size by defining the `BUFFER_SIZE` macro:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

Once compiled, you can call `get_next_line` in a loop to read and process each line from a file:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    // Process the line
    free(line);  // Don't forget to free the allocated memory after processing the line
}

close(fd);  // Always close the file descriptor when done
```

### Constraints

- **Prohibited Functions**: You cannot use the `libft` library, `lseek`, or global variables.
- **Indeterminate Behavior**: The function’s behavior is undefined if the file descriptor is changed during execution or if it is applied to binary files. It is designed for use with text files.

## Bonus Part

### Additional Features

The bonus part extends the functionality of `get_next_line` by adding support for handling multiple file descriptors simultaneously. This means that you can call `get_next_line` on different file descriptors concurrently, and the function will maintain the state of each one independently.

### Bonus Files

- **`get_next_line_bonus.c`**: Contains the extended logic to handle multiple file descriptors.
- **`get_next_line_utils_bonus.c`**: Helper functions supporting the extended logic.
- **`get_next_line_bonus.h`**: Header file with function prototypes for the bonus part.

### Compilation

To compile the bonus part, use the following command:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

### Testing with Multiple File Descriptors

You can test the bonus functionality by reading from multiple file descriptors simultaneously:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);

// Alternate between file descriptors as needed
free(line1);
free(line2);

close(fd1);
close(fd2);
```

### Key Considerations

- **Static Variables**: The use of static variables is required to maintain the state of the function between successive calls. This allows the function to continue reading where it left off in the previous call.
- **Edge Cases**: Be sure to test your implementation with various buffer sizes and input types (e.g., text files, stdin). Additionally, stress test the program with simultaneous access to multiple file descriptors to ensure robustness.

## Conclusion

The **Get Next Line** project strengthens your understanding of file handling, memory management, and modular programming in C. Upon completion, you'll have a versatile and reusable function that can be used in various scenarios requiring line-by-line file processing. This project is an excellent opportunity to practice efficient memory usage and develop your ability to manage complex state across function calls.

## License
This project is part of the 42 School curriculum and is intended for educational purposes.

