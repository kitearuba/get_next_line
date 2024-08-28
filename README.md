---

# 📝 **Get Next Line** - _42 School Project_

![Get Next Line](https://img.shields.io/badge/42-Project-blue?style=flat-square) ![C Programming](https://img.shields.io/badge/Language-C-brightgreen?style=flat-square) ![File I/O](https://img.shields.io/badge/Topic-File%20I/O-orange?style=flat-square)

## 📖 **Overview**

The **Get Next Line** project challenges you to create a function that reads from a file descriptor or standard input one line at a time. This project is essential for mastering file I/O in C, static variables, and efficient memory management. The function processes input line-by-line, enabling modular, scalable file handling across various contexts.

---

## 🚀 **Mandatory Part**

### 🛠️ **Function Prototype**

```c
char *get_next_line(int fd);
```

### 📝 **Description**

The `get_next_line` function reads and returns the next line from the given file descriptor `fd`. It continues to return subsequent lines until the end of the file is reached or an error occurs. If a newline character (`\n`) is present, it will be included in the returned string. When no more lines are available, or an error occurs, the function returns `NULL`.

---

### ⚙️ **Features**

- **Single Line Reading**: Efficiently reads one line at a time, perfect for handling text file inputs or streams that require line-by-line processing.
- **Adjustable Buffer Size**: The buffer size can be set dynamically by defining the `BUFFER_SIZE` macro during compilation, making the function adaptable to different file types and system environments.
- **Memory Safety**: Ensures dynamically allocated memory is managed effectively, preventing memory leaks and ensuring that each line is freed after use.

---

### 📂 **Files**

- **`get_next_line.c`**: Contains the core logic for reading a single line from the file descriptor.
- **`get_next_line_utils.c`**: Implements helper functions that assist the main logic in `get_next_line.c`.
- **`get_next_line.h`**: Header file that declares the prototypes for `get_next_line` and utility functions.

---

### 🛠️ **Usage**

To compile the `get_next_line` function, use the following command. You can define the buffer size using the `BUFFER_SIZE` macro at compile time:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

Once compiled, you can use `get_next_line` in your code to read from a file or standard input line-by-line:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    // Process the line
    free(line);  // Don't forget to free the line after processing
}

close(fd);  // Always close the file descriptor when done
```

---

### ⚠️ **Constraints**

- **Prohibited Functions**: You cannot use `libft`, `lseek`, or global variables.
- **Text Files Only**: The function is designed for text files. Using `get_next_line` with binary files may produce undefined behavior and should be avoided.
- **Static Variables**: Use static variables to maintain the state of the function across multiple calls. This is crucial for the proper handling of input that spans across multiple function calls.

---

## 🎉 **Bonus Part**

### 🔥 **Additional Features**

The bonus part of the **Get Next Line** project extends the functionality to support **multiple file descriptors**. This means you can call `get_next_line` on multiple files or streams concurrently, and the function will correctly manage the state of each file descriptor independently.

---

### 📂 **Bonus Files**

- **`get_next_line_bonus.c`**: Implements the logic for handling multiple file descriptors simultaneously.
- **`get_next_line_utils_bonus.c`**: Helper functions that support the bonus functionality.
- **`get_next_line_bonus.h`**: Header file with the prototypes for the bonus functions.

---

### 🛠️ **Bonus Compilation**

To compile the bonus version of `get_next_line`, use the following command:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

---

### 🧪 **Testing with Multiple File Descriptors**

Here’s an example of how you can test the bonus functionality by reading from multiple files at the same time:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);

// Alternate between file descriptors
free(line1);
free(line2);

close(fd1);
close(fd2);
```

---

### 🧠 **Key Considerations**

- **Edge Cases**: Make sure to test your implementation with various buffer sizes and file types to ensure robustness. For example, test with empty files, very large files, and files without newline characters.
- **Multiple File Descriptors**: When dealing with multiple file descriptors, ensure that each file descriptor's state is independently maintained by static variables within the function.

---

## 🏆 **Conclusion**

The **Get Next Line** project offers a unique opportunity to strengthen your skills in file handling, memory management, and modular programming in C. Upon completion, you’ll have developed a versatile and efficient function that can be applied to numerous situations requiring line-by-line file reading. This project is also a great way to improve your proficiency with static variables and dynamic memory management.

---

## 📜 **License**

This project is part of the 42 School curriculum and is intended for educational purposes.

---

### 🎨 **Final Notes**

The **Get Next Line** project pushes you to master efficient memory usage and the management of function states across multiple calls using static variables. Be sure to test edge cases, experiment with different buffer sizes, and, most importantly, have fun coding! 🚀

---

## 👨‍💻 **Author**

**chrrodri**  
_42 Barcelona_

[GitHub Profile](https://github.com/kitearuba)

---
