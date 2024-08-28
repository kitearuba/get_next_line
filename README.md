---

# 🖨️ **ft_printf** - _42 School Project_

![ft_printf](https://img.shields.io/badge/42-Project-blue?style=flat-square)

## 📖 **Overview**

The **ft_printf** project challenges you to re-implement the standard `printf()` function in C, focusing on handling **variadic functions**, **memory management**, and **formatted output**. This project helps you master low-level C programming concepts, which are critical for writing efficient, custom functions.

---

## 🚀 **Mandatory Part**

### 🛠️ **Function Prototype**
```c
int ft_printf(const char *format, ...);
```

### 📝 **Description**
`ft_printf` mimics the functionality of the standard `printf()` function, which prints formatted output to the standard output. It supports several format specifiers to display various types of data, such as characters, strings, and numbers, using **variadic arguments**.

---

### ⚙️ **Supported Format Specifiers**

- **Character & String Conversion**:
  - `%c`: Print a single character.
  - `%s`: Print a string of characters.
- **Pointer Conversion**:
  - `%p`: Print a pointer address in hexadecimal format.
- **Integer Conversion**:
  - `%d` / `%i`: Print a signed decimal integer.
  - `%u`: Print an unsigned decimal integer.
  - `%x` / `%X`: Print a number in hexadecimal format (lowercase/uppercase).
- **Special Conversion**:
  - `%%`: Print a literal percentage sign.

---

### 📂 **Files**

- **`ft_printf.c`**: Contains the core logic of the `ft_printf()` function.
- **`ft_printf_utils.c`**: Helper functions to support various formatting operations.
- **`ft_printf.h`**: Header file with function prototypes and necessary includes.
- **`libft` directory**: Contains the standard `libft` library used in conjunction with `ft_printf`.

---

### 🛠️ **Makefile Usage**

The Makefile simplifies the compilation process and provides several useful commands:

| Command       | Description                              |
|---------------|------------------------------------------|
| `make`        | Compiles the `libftprintf.a` library.    |
| `make clean`  | Removes object files generated during compilation. |
| `make fclean` | Removes all object files and the compiled library (`libftprintf.a`). |
| `make re`     | Cleans and recompiles everything from scratch. |

After running `make`, you will generate `libftprintf.a`, a static library that can be used in your own projects.

---

## 🛠️ **Usage**

1. **Include the Header**

   To use `ft_printf` in your project, include the `ft_printf.h` header file:
   ```c
   #include "ft_printf.h"
   ```

2. **Compile Your Project**

   You can compile your project and link it with the `ft_printf` library:
   ```bash
   gcc your_program.c -L. -lftprintf -o your_program
   ```

3. **Example**

   Here’s an example of how to use `ft_printf`:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       ft_printf("Hello, %s!\n", "42");
       return 0;
   }
   ```

---

### 🔄 **Relinking and Dependencies**

The Makefile is designed to prevent **unnecessary relinking**. If any source or header file in the `libft` or `ft_printf` directories changes, the Makefile will detect the changes and recompile only the affected files, ensuring an efficient build process.

---

## 🎯 **Bonus Part**

The bonus part of the **ft_printf** project extends the function's capabilities by adding support for extra formatting options, such as:
- **Field Width & Precision**: Manage the minimum number of characters to print and control the precision for floating-point numbers.
- **Flags**: Handle flags such as `-`, `0`, `+`, `#`, and `' '` (space).

This part adds more depth to your implementation and demonstrates your understanding of advanced formatting techniques.

---

### ⚙️ **Bonus Features**

In the bonus section, you'll implement additional format specifiers and flags to further enhance `ft_printf`:
- `-`: Left-align the output within the specified field width.
- `0`: Pad the output with zeros instead of spaces.
- `+`: Precede the output with a plus or minus sign for numeric conversions.
- `#`: Add a prefix for octal (`0`) or hexadecimal (`0x`, `0X`) values.
- `' '` (space): Insert a space before positive numbers in numeric conversions.

---

## 🏆 **Conclusion**

The **ft_printf** project is a fantastic opportunity to deepen your understanding of C, particularly in the areas of variadic functions, formatted output, and memory management. By implementing such a widely used function from scratch, you’ll gain valuable experience that will be beneficial in future projects.

Good luck, and happy coding! 🚀

---

## 👨‍💻 **Author**

**chrrodri**  
_42 Barcelona_

[GitHub Profile](https://github.com/kitearuba)

---
