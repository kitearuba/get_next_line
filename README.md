---

# 📝 **Get Next Line** - _42 School Project_

![Get Next Line](https://img.shields.io/badge/42-Project-blue?style=flat-square)

## 📖 **Overview**

The **Get Next Line** project challenges you to create a function that reads a file or standard input one line at a time. This project is all about mastering file I/O, efficient memory management, and static variables. With this function, you can process files line-by-line, allowing for modular and scalable file handling in C.

---

## 🚀 **Mandatory Part**

### 🛠️ **Function Prototype**
```c
char *get_next_line(int fd);
```

### 📝 **Description**
`get_next_line` reads and returns the next line from a file descriptor `fd`. Successive calls to the function will return the next line until the end of the file is reached or an error occurs. If a newline character (`\n`) is present, it will be included in the returned string. When no more lines are available, the function returns `NULL`.

---

### ⚙️ **Features**

- **Single Line Reading**: Efficiently reads one line at a time, which is perfect for processing text files or handling input.
- **Adjustable Buffer Size**: You can adjust the reading buffer size using the `BUFFER_SIZE` macro at compilation. This makes the function adaptable to different file sizes and system environments.
- **Memory Safety**: Dynamically allocated memory is properly managed, preventing leaks and ensuring that memory is freed appropriately.

---

### 📂 **Files**

- **`get_next_line.c`**: Contains the core logic for reading a single line.
- **`get_next_line_utils.c`**: Implements utility functions to support the main logic.
- **`get_next_line.h`**: Header file with function prototypes and necessary includes.

---

### 🛠️ **Usage**

To compile the `get_next_line` function, you can define the buffer size during compilation using the `BUFFER_SIZE` macro:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

Once compiled, you can use `get_next_line` in your code to read each line from a file or standard input:

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    // Process the line
    free(line);  // Don't forget to free the line after processing
}

close(fd);  // Always close the file descriptor when you're done
```

---

### ⚠️ **Constraints**

- **Prohibited Functions**: You cannot use `libft`, `lseek`, or global variables.
- **Intended Use**: This function is designed for reading text files. The behavior with binary files is undefined and should be avoided.
- **Static Variables**: You’ll need to use static variables to maintain the function’s state across multiple calls.

---

## 🎉 **Bonus Part**

### 🔥 **Additional Features**

The bonus part of **Get Next Line** extends its functionality to handle **multiple file descriptors** simultaneously. This means you can have multiple calls to `get_next_line` on different file descriptors at the same time, and the function will independently manage the state for each.

---

### 📂 **Bonus Files**

- **`get_next_line_bonus.c`**: Contains the logic for handling multiple file descriptors.
- **`get_next_line_utils_bonus.c`**: Helper functions supporting the bonus logic.
- **`get_next_line_bonus.h`**: Header file with the bonus function prototypes.

---

### 🛠️ **Bonus Compilation**

To compile the bonus version of `get_next_line`, use the following command:

```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

---

### 🧪 **Testing with Multiple File Descriptors**

You can test the bonus functionality by reading from multiple files at the same time:

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

- **Edge Cases**: Test with different buffer sizes and file types to ensure your implementation is robust.
- **Multiple FD Handling**: The static variable in the function must maintain separate states for each file descriptor, which is critical for correct functionality in the bonus part.

---

## 🏆 **Conclusion**

The **Get Next Line** project enhances your skills in file handling, memory management, and modular programming in C. Upon completion, you'll have developed a versatile and efficient function that can be applied to many scenarios requiring line-by-line file reading. It's a great opportunity to hone your C programming abilities!

---

## 📜 **License**
This project is part of the 42 School curriculum and is intended for educational purposes.

---

### 🎨 **Final Notes**
The project not only helps you practice efficient memory usage but also pushes your understanding of managing function state across multiple calls using static variables. Keep testing with different edge cases, and have fun coding! ✨

---

## 👨‍💻 **Author**

**chrrodri**  
_42 Barcelona_

[GitHub Profile](https://github.com/kitearuba)

---
