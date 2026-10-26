*This project has been created as part of the 42 curriculum by abenabda.*

# Libft

## About

Libft is my first C library, built as part of the 42 curriculum. In this project, I recreated many functions from the standard C library and implemented additional utilities that I will reuse throughout future 42 projects.

The main objective was to better understand how these functions work internally while improving my skills in memory management, pointers, strings, and data structures.

## What I implemented

### Libc functions

I reimplemented the following standard C functions using the `ft_` prefix:

- Character functions: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Character conversion: `ft_toupper`, `ft_tolower`
- Memory functions: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- String functions: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Conversion and allocation: `ft_atoi`, `ft_calloc`

### Additional functions

I also implemented several utility functions that are not part of the standard libc:

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Linked list

For this part, I implemented a complete singly linked-list API using the `t_list` structure:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Building the library

I compile the library with the provided Makefile.

```bash
make
```

Useful commands:

```bash
make clean
make fclean
make re
```

The library is generated as `libft.a`.

## Example

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, 42!", 1);
    return (0);
}
```

## What I learned

This project helped me develop a much deeper understanding of C fundamentals. While implementing each function, I practiced:

- Manual memory management with `malloc` and `free`
- Pointer arithmetic
- String and memory manipulation
- Defensive programming and edge-case handling
- Building and using a static library
- Implementing and manipulating linked lists

## Resources

During this project, I mainly relied on:

- `man` pages
- The official 42 Libft subject
- Standard C documentation

### AI usage

I used AI as a learning assistant to improve the project's documentation and clarify concepts while keeping the implementation and understanding of the functions my own.