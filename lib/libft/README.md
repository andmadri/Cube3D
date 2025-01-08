# Libft - Your Very First Own Library

## Summary
This project involves coding a C library, `libft`, which will contain a variety of general-purpose functions that your programs can rely upon.

## Mandatory Part

### Technical Considerations
- Declaring global variables is forbidden.
- Helper functions must be defined as `static`.
- All files must be placed at the root of the repository.
- Only necessary files should be turned in.
- Every `.c` file must compile with `-Wall -Wextra -Werror` flags.
- The library must be created using the `ar` command, not `libtool`.
- The resulting `libft.a` must be created at the root of the repository.

### Part 1 - Libc Functions
Re-implement the following standard library functions with the same behavior but prefixed with `ft_`:
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_toupper`
- `ft_tolower`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_atoi`

Additional functions using `malloc()`:
- `ft_calloc`
- `ft_strdup`

### Part 2 - Additional Functions
Implement the following functions:
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

## Bonus Part
To be evaluated, the mandatory part must be perfect. If achieved, the following list manipulation functions can be implemented for bonus points:

### List Structure
```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

### List Functions
- `ft_lstnew`: Allocates and returns a new node.
- `ft_lstadd_front`: Adds the node `new` at the beginning of the list.
- `ft_lstsize`: Counts the number of nodes in the list.
- `ft_lstlast`: Returns the last node of the list.
- `ft_lstadd_back`: Adds the node `new` at the end of the list.
- `ft_lstdelone`: Frees the memory of a node’s content using the `del` function given as a parameter and frees the node. The memory of `next` must not be freed.
- `ft_lstclear`: Deletes and frees the given node and every successor of that node, using the `del` function and `free(3)`. Finally, the pointer to the list must be set to `NULL`.
- `ft_lstiter`: Iterates the list `lst` and applies the function `f` on the content of each node.
- `ft_lstmap`: Iterates the list `lst` and applies the function `f` on the content of each node, creating a new list resulting from the successive applications of `f`. The `del` function is used to delete the content of a node if needed.

## Submission and Peer-Evaluation
Submit your assignment in your Git repository. Only the work inside your repository will be evaluated. Double-check file names to ensure they are correct. Place all files at the root of the repository.
