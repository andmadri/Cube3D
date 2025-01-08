/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:23:23 by crasche       #+#    #+#                 */
/*   Updated: 2024/08/04 15:36:04 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

// LIBFT BONUS STRUCT
typedef struct s_libft
{
	void			*content;
	struct s_libft	*next;
}	t_libft;

// GET_NEXT_LINE STRUCT
typedef struct s_gnl
{
	char			*buffer;
	struct s_gnl	*next;
}	t_gnl;

// FT_PRINTF STRUCT
typedef struct s_flags
{
	int	spec;
	int	width;
	int	star;
	int	zero;
	int	minus;
	int	dot;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

// GET_NEXT_LINE DEFINE BUFFER_SIZE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50000
# endif

// LIBFT FUNCTIONS
/**
 * @brief
 * This function splits a string into an array of substrings
 * based on a delimiter character.
 * @param char const *s
 * The input string to be split.
 * @param char c
 * The delimiter character used to split the string.
 * @note
 * The function returns a NULL-terminated array of substrings.
 * @return
 * A pointer to an array of substrings.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief
 * This function converts a string to an integer.
 * @param const char *nptr
 * The string to be converted to an integer.
 * @note
 * The function skips any leading whitespace characters and
 * interprets the subsequent characters as an integer.
 * @return
 * The converted integer value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief
 * This function converts an integer to a string.
 * @param int n
 * The integer to be converted to a string.
 * @note
 * The function dynamically allocates memory for the resulting
 * string. The caller is responsible for freeing the allocated
 * memory.
 * @return
 * A pointer to the resulting string.
 */
char	*ft_itoa(int n);

/**
 * @brief
 * This function converts an uppercase letter to a lowercase
 * letter.
 * @param int c
 * The character to be converted.
 * @note
 * If the character is an uppercase letter, it is converted to
 * its corresponding lowercase letter. Otherwise, the character
 * is returned unchanged.
 * @return
 * The converted character, or the original character if no
 * conversion was needed.
 */
int		ft_tolower(int c);

/**
 * @brief
 * This function converts a lowercase letter to an uppercase
 * letter.
 * @param int c
 * The character to be converted.
 * @note
 * If the character is a lowercase letter, it is converted to
 * its corresponding uppercase letter. Otherwise, the character
 * is returned unchanged.
 * @return
 * The converted character, or the original character if no
 * conversion was needed.
 */
int		ft_toupper(int c);

/**
 * @brief
 * This function checks if a character is a digit.
 * @param int c
 * The character to be checked.
 * @note
 * A digit character is any character between '0' and '9'.
 * @return
 * 1 if the character is a digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief
 * This function checks if a character is a whitespace
 * character.
 * @param int c
 * The character to be checked.
 * @note
 * Whitespace characters include space, tab, newline, vertical
 * tab, form feed, and carriage return.
 * @return
 * 1 if the character is a whitespace character, 0 otherwise.
 */
int		ft_isspace(int c);

/**
 * @brief
 * This function checks if a character is alphanumeric.
 * @param int c
 * The character to be checked.
 * @note
 * An alphanumeric character is either a letter or a digit.
 * @return
 * 1 if the character is alphanumeric, 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief
 * This function checks if a character is an uppercase letter.
 * @param int c
 * The character to be checked.
 * @note
 * An uppercase letter is any character between 'A' and 'Z'.
 * @return
 * 1 if the character is an uppercase letter, 0 otherwise.
 */
int		ft_isupper(int c);

/**
 * @brief
 * This function checks if a character is a lowercase letter.
 * @param int c
 * The character to be checked.
 * @note
 * A lowercase letter is any character between 'a' and 'z'.
 * @return
 * 1 if the character is a lowercase letter, 0 otherwise.
 */
int		ft_islower(int c);

/**
 * @brief
 * This function checks if a character is an alphabetic letter.
 * @param int c
 * The character to be checked.
 * @note
 * An alphabetic letter is any character between 'A' and 'Z'
 * or between 'a' and 'z'.
 * @return
 * 1 if the character is an alphabetic letter, 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief
 * This function checks if a character is an ASCII character.
 * @param int c
 * The character to be checked.
 * @note
 * An ASCII character is any character between 0 and 127.
 * @return
 * 1 if the character is an ASCII character, 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief
 * This function checks if a character is printable.
 * @param int c
 * The character to be checked.
 * @note
 * A printable character is any character that is not a control
 * character.
 * @return
 * 1 if the character is printable, 0 otherwise.
 */
int		ft_isprint(int c);

// // ft_convert..
// char	**ft_split(char const *s, char c);
// int		ft_atoi(const char *nptr);
// char	*ft_itoa(int n);
// int		ft_tolower(int c);
// int		ft_toupper(int c);
// // ft_istype
// int		ft_isdigit(int c);
// int		ft_isspace(int c);
// int		ft_isalnum(int c);
// int		ft_isupper(int c);
// int		ft_islower(int c);
// int		ft_isalpha(int c);
// int		ft_isascii(int c);
// int		ft_isprint(int c);

/**
 * @brief
 * This function creates a new linked list element with
 * the given content.
 * @param void *content
 * The content to be stored in the new list element.
 * @note
 * The content is not copied; the pointer is stored
 * directly.
 * @return
 * A pointer to the newly created list element.
 */
t_libft	*ft_lstnew(void *content);

/**
 * @brief
 * This function adds a new element at the beginning of
 * the list.
 * @param t_libft **lst
 * The address of a pointer to the first element of the
 * list.
 * @param t_libft *lstnew
 * The new element to add at the beginning of the list.
 * @return
 * Function returns nothing.
 */
void	ft_lstadd_front(t_libft **lst, t_libft *lstnew);

/**
 * @brief
 * This function counts the number of elements in a list.
 * @param t_libft *lst
 * The beginning of the list.
 * @return
 * The number of elements in the list.
 */
int		ft_lstsize(t_libft *lst);

/**
 * @brief
 * This function returns the last element of the list.
 * @param t_libft *lst
 * The beginning of the list.
 * @return
 * A pointer to the last element of the list.
 */
t_libft	*ft_lstlast(t_libft *lst);

/**
 * @brief
 * This function adds a new element at the end of the list.
 * @param t_libft **lst
 * The address of a pointer to the first element of the
 * list.
 * @param t_libft *lstnew
 * The new element to add at the end of the list.
 * @return
 * Function returns nothing.
 */
void	ft_lstadd_back(t_libft **lst, t_libft *lstnew);

/**
 * @brief
 * This function deletes a single element from the list.
 * @param t_libft *lst
 * The element to delete.
 * @param void (*del)(void*)
 * The function to delete the content of the element.
 * @return
 * Function returns nothing.
 */
void	ft_lstdelone(t_libft *lst, void (*del)(void*));

/**
 * @brief
 * This function iterates the list and applies a function
 * to the content of each element.
 * @param t_libft *lst
 * The beginning of the list.
 * @param void (*f)(void *)
 * The function to apply to the content of each element.
 * @return
 * Function returns nothing.
 */
void	ft_lstiter(t_libft *lst, void (*f)(void *));

/**
 * @brief
 * This function deletes and frees the entire list.
 * @param t_libft **lst
 * The address of a pointer to the first element of the
 * list.
 * @param void (*del)(void*)
 * The function to delete the content of each element.
 * @return
 * Function returns nothing.
 */
void	ft_lstclear(t_libft **lst, void (*del)(void*));

/**
 * @brief
 * This function iterates the list and applies a function
 * to the content of each element, creating a new list from
 * the results.
 * @param t_libft *lst
 * The beginning of the list.
 * @param void *(*f)(void *)
 * The function to apply to the content of each element.
 * @param void (*del)(void *)
 * The function to delete the content of each element in
 * case of failure.
 * @return
 * A pointer to the new list, or NULL if allocation fails.
 */
t_libft	*ft_lstmap(t_libft *lst, void *(*f)(void *), void (*del)(void *));

// t_libft	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_libft **lst, t_libft *lstnew);
// int		ft_lstsize(t_libft *lst);
// t_libft	*ft_lstlast(t_libft *lst);
// void	ft_lstadd_back(t_libft **lst, t_libft *lstnew);
// void	ft_lstdelone(t_libft *lst, void (*del)(void*));
// void	ft_lstiter(t_libft *lst, void (*f)(void *));
// void	ft_lstclear(t_libft **lst, void (*del)(void*));
// t_libft	*ft_lstmap(t_libft *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief
 * This function sets the first n bytes of the area starting
 * at s to zero (bytes containing '\0').
 * @param void *s
 * The starting address of the memory to be filled with
 * zeros.
 * @param size_t n
 * The number of bytes to be set to zero.
 * @return
 * Function returns nothing.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief
 * This function allocates memory for an array of nmemb
 * elements of size bytes each and initializes all bytes
 * in the allocated storage to zero.
 * @param size_t nmemb
 * Number of elements to allocate.
 * @param size_t size
 * Size of each element.
 * @return
 * A pointer to the allocated memory, or NULL if the
 * allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief
 * This function frees a NULL-terminated array of strings.
 * @param char **strarr
 * The array of strings to be freed.
 * @return
 * Function returns nothing.
 */
void	ft_free_strarr(char **strarr);

/**
 * @brief
 * This function dynamically reallocates a string to a new
 * capacity.
 * @param char *original_str
 * The original string to be reallocated.
 * @param int *capacity
 * A pointer to the current capacity of the string, which
 * will be updated to the new capacity.
 * @note
 * The function may allocate more memory than requested for
 * future growth.
 * @return
 * A pointer to the newly allocated string.
 */
char	*ft_dynstralloc(char *original_str, int *capacity);

/**
 * @brief
 * This function copies n bytes from memory area src to
 * memory area dest.
 * @param void *dest
 * The destination memory area.
 * @param const void *src
 * The source memory area.
 * @param size_t n
 * The number of bytes to copy.
 * @return
 * A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief
 * This function copies n bytes from memory area src to
 * memory area dest, handling overlapping memory areas
 * correctly.
 * @param void *dest
 * The destination memory area.
 * @param const void *src
 * The source memory area.
 * @param size_t n
 * The number of bytes to copy.
 * @return
 * A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief
 * This function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 * @param void *s
 * The memory area to be filled.
 * @param int c
 * The byte to fill the memory area with.
 * @param size_t n
 * The number of bytes to be set to the value.
 * @return
 * A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief
 * This function scans the initial n bytes of the memory
 * area pointed to by s for the first instance of c.
 * @param const void *s
 * The memory area to be scanned.
 * @param int c
 * The byte to search for.
 * @param size_t n
 * The number of bytes to be analyzed.
 * @return
 * A pointer to the matching byte or NULL if the byte is not
 * found.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief
 * This function compares the first n bytes of the memory
 * areas s1 and s2.
 * @param const void *s1
 * The first memory area.
 * @param const void *s2
 * The second memory area.
 * @param size_t n
 * The number of bytes to compare.
 * @return
 * An integer less than, equal to, or greater than zero if
 * the first n bytes of s1 is found, respectively, to be less
 * than, to match, or be greater than the first n bytes of
 * s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief
 * This function writes the character c to the given file
 * descriptor.
 * @param char c
 * The character to be written.
 * @param int fd
 * The file descriptor on which to write.
 * @return
 * Function returns nothing.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief
 * This function writes the string s to the given file
 * descriptor.
 * @param char *s
 * The string to be written.
 * @param int fd
 * The file descriptor on which to write.
 * @return
 * Function returns nothing.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief
 * This function writes the string s to the given file
 * descriptor, followed by a newline.
 * @param char *s
 * The string to be written.
 * @param int fd
 * The file descriptor on which to write.
 * @return
 * Function returns nothing.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief
 * This function writes the integer n to the given file
 * descriptor.
 * @param int n
 * The integer to be written.
 * @param int fd
 * The file descriptor on which to write.
 * @return
 * Function returns nothing.
 */
void	ft_putnbr_fd(int n, int fd);

// // ft_melloc..
// void	ft_bzero(void *s, size_t n);
// void	*ft_calloc(size_t nmemb, size_t size);
// void	ft_free_strarr(char **strarr);
// char	*ft_dynstralloc(char *original_str, int *capacity);
// // ft_mem..
// void	*ft_memcpy(void *dest, const void *src, size_t n);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// void	*ft_memset(void *s, int c, size_t n);
// void	*ft_memchr(const void *s, int c, size_t n);
// int		ft_memcmp(const void *s1, const void *s2, size_t n);
// // ft_put..
// void	ft_putchar_fd(char c, int fd);
// void	ft_putstr_fd(char *s, int fd);
// void	ft_putendl_fd(char *s, int fd);
// void	ft_putnbr_fd(int n, int fd);

/**
 * @brief
 * This function calculates the length of a string.
 * @param const char *s
 * The string to be measured.
 * @return
 * The number of characters in the string, excluding the
 * null terminator.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief
 * This function copies up to size - 1 characters from the
 * NULL-terminated string src to dst, NULL-terminating the
 * result.
 * @param char *dst
 * The destination buffer.
 * @param const char *src
 * The source string.
 * @param size_t size
 * The size of the destination buffer.
 * @return
 * The total length of the string it tried to create.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief
 * This function appends the NULL-terminated string src to
 * the end of dst. It will append at most size - strlen(dst)
 * - 1 bytes, NULL-terminating the result.
 * @param char *dst
 * The destination buffer.
 * @param const char *src
 * The source string.
 * @param size_t size
 * The size of the destination buffer.
 * @return
 * The total length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief
 * This function compares two strings.
 * @param const char *s1
 * The first string to compare.
 * @param const char *s2
 * The second string to compare.
 * @return
 * An integer less than, equal to, or greater than zero if
 * s1 is found, respectively, to be less than, to match, or
 * be greater than s2.
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief
 * This function compares up to n characters of two strings.
 * @param const char *s1
 * The first string to compare.
 * @param const char *s2
 * The second string to compare.
 * @param size_t n
 * The maximum number of characters to compare.
 * @return
 * An integer less than, equal to, or greater than zero if
 * s1 is found, respectively, to be less than, to match, or
 * be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief
 * This function locates the first occurrence of the null-
 * terminated string little in the string big, where not more
 * than len characters are searched.
 * @param const char *big
 * The string to be searched.
 * @param const char *little
 * The substring to find.
 * @param size_t len
 * The maximum number of characters to search.
 * @return
 * A pointer to the beginning of the located substring, or
 * NULL if the substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief
 * This function locates the first occurrence of c (converted
 * to a char) in the string pointed to by s. The terminating
 * null character is considered part of the string.
 * @param const char *s
 * The string to be searched.
 * @param int c
 * The character to find.
 * @return
 * A pointer to the first occurrence of the character c in
 * the string s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief
 * This function locates the last occurrence of c (converted
 * to a char) in the string pointed to by s. The terminating
 * null character is considered part of the string.
 * @param const char *s
 * The string to be searched.
 * @param int c
 * The character to find.
 * @return
 * A pointer to the last occurrence of the character c in
 * the string s, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief
 * This function duplicates a string by allocating memory and
 * copying the null-terminated string s into it.
 * @param const char *s
 * The string to duplicate.
 * @return
 * A pointer to the newly allocated string, or NULL if
 * allocation fails.
 */
char	*ft_strdup(const char *s);

/**
 * @brief
 * This function duplicates up to n characters of a string by
 * allocating memory and copying the string s into it.
 * @param const char *s
 * The string to duplicate.
 * @param size_t n
 * The maximum number of characters to duplicate.
 * @return
 * A pointer to the newly allocated string, or NULL if
 * allocation fails.
 */
char	*ft_strndup(const char *s, size_t n);

/**
 * @brief
 * This function allocates and returns a substring from the
 * string s. The substring begins at index start and is of
 * maximum size len.
 * @param char const *s
 * The string from which to create the substring.
 * @param unsigned int start
 * The starting index of the substring.
 * @param size_t len
 * The maximum length of the substring.
 * @return
 * A pointer to the newly allocated substring, or NULL if
 * allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief
 * This function allocates and returns a new string, which is
 * the result of the concatenation of s1 and s2.
 * @param char const *s1
 * The prefix string.
 * @param char const *s2
 * The suffix string.
 * @return
 * A pointer to the newly allocated string, or NULL if
 * allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief
 * This function allocates and returns a copy of s1 with the
 * characters specified in set removed from the beginning and
 * the end of the string.
 * @param char const *s1
 * The string to be trimmed.
 * @param char const *set
 * The set of characters to be trimmed.
 * @return
 * A pointer to the newly allocated string, or NULL if
 * allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief
 * This function applies the function f to each character of
 * the string s to create a new string resulting from
 * successive applications of f.
 * @param char const *s
 * The string on which to iterate.
 * @param char (*f)(unsigned int, char)
 * The function to apply to each character.
 * @return
 * A pointer to the newly allocated string, or NULL if
 * allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief
 * This function applies the function f to each character of
 * the string passed as argument, and passing its index as
 * the first argument. Each character is passed by address
 * to f to be modified if necessary.
 * @param char *s
 * The string on which to iterate.
 * @param void (*f)(unsigned int, char*)
 * The function to apply to each character.
 * @return
 * Function returns nothing.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// // ft_str..
// size_t	ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// size_t	ft_strlcat(char *dst, const char *src, size_t size);
// int		ft_strcmp(const char *s1, const char *s2);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_strnstr(const char *big, const char *little, size_t len);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strrchr(const char *s, int c);
// char	*ft_strdup(const char *s);
// char	*ft_strndup(const char *s, size_t n);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
// char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// FT_PRINTF FUNCTIONS
/**
 * @brief
 * This function produces output according to a format
 * string.
 * @param const char *format
 * The format string containing the text to be written and
 * the format specifiers.
 * @param ...
 * Additional arguments specifying the data to print.
 * @return
 * The number of characters printed (excluding the null
 * byte used to end output to strings).
 */
int		ft_printf(const char *format, ...);

/**
 * @brief
 * This function prints an unsigned integer in uppercase
 * hexadecimal format.
 * @param unsigned int n
 * The number to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @param t_flags flags
 * The flags for formatting.
 * @return
 * Function returns nothing.
 */
void	printf_x_upper(unsigned int n, unsigned int *count, t_flags flags);

/**
 * @brief
 * This function prints an unsigned integer in lowercase
 * hexadecimal format.
 * @param unsigned int n
 * The number to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @param t_flags flags
 * The flags for formatting.
 * @return
 * Function returns nothing.
 */
void	printf_x(unsigned int n, unsigned int *count, t_flags flags);

/**
 * @brief
 * This function prints an unsigned long integer in
 * hexadecimal format, prefixed with "0x".
 * @param unsigned long n
 * The number to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @return
 * Function returns nothing.
 */
void	printf_p(unsigned long n, unsigned int *count);

/**
 * @brief
 * This function converts an unsigned long integer to a
 * hexadecimal string.
 * @param unsigned long n
 * The number to be converted.
 * @param char *number
 * The buffer to store the hexadecimal string.
 * @return
 * Function returns nothing.
 */
void	printf_get_hex(unsigned long n, char *number);

/**
 * @brief
 * This function prints a string.
 * @param char *s
 * The string to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @return
 * The number of characters printed.
 */
int		printf_s(char *s, unsigned int *count);

/**
 * @brief
 * This function prints a character.
 * @param int i
 * The character to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @return
 * The number of characters printed.
 */
int		printf_c(int i, unsigned int *count);

/**
 * @brief
 * This function prints an integer.
 * @param int n
 * The integer to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @param t_flags flags
 * The flags for formatting.
 * @return
 * Function returns nothing.
 */
void	printf_int(int n, unsigned int *count, t_flags flags);

/**
 * @brief
 * This function prints an unsigned integer.
 * @param unsigned int n
 * The number to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @return
 * Function returns nothing.
 */
void	printf_u(unsigned int n, unsigned int *count);

/**
 * @brief
 * This function prints the digits of an integer, taking into
 * account the specified length and formatting flags.
 * @param int n
 * The number to be printed.
 * @param unsigned int *count
 * A pointer to the count of printed characters.
 * @param int len
 * The number of digits to print.
 * @param t_flags flags
 * The flags for formatting.
 * @return
 * Function returns nothing.
 */
void	printf_int_digits(int n, unsigned int *count, int len, t_flags flags);

// int		ft_printf(const char *format, ...);
// // hex.c functions for hex conversions for flags: x X p
// void	printf_x_upper(unsigned int n, unsigned int *count, t_flags flags);
// void	printf_x(unsigned int n, unsigned int *count, t_flags flags);
// void	printf_p(unsigned long n, unsigned int *count);
// void	printf_get_hex(unsigned long n, char *number);
// // chars.c functions for char and string for flags: c s
// int		printf_s(char *s, unsigned int *count);
// int		printf_c(int i, unsigned int *count);
// // numbers.c functions for nubmers for flags: i d u
// void	printf_int(int n, unsigned int *count, t_flags flags);
// void	printf_u(unsigned int n, unsigned int *count);
// void	printf_int_digits(int n, unsigned int *count, int len, t_flags flags);

// GET_NEXT_LINE FUNCTIONS
/**
 * @brief
 * This function reads a line from a file descriptor.
 * @param int fd
 * The file descriptor to read from.
 * @return
 * A pointer to the line read, or NULL if there is nothing
 * more to read or an error occurs.
 */
char	*get_next_line(int fd);

/**
 * @brief
 * This function calculates the length of the string in the
 * list until a newline character is found.
 * @param t_gnl *lst
 * The list to be searched.
 * @return
 * The number of characters until a newline is found.
 */
int		gnl_lst_until_nl(t_gnl *lst);

/**
 * @brief
 * This function calculates the length of the string in the
 * list until a newline character is found or until the end
 * of the list.
 * @param t_gnl *lst
 * The list to be searched.
 * @return
 * The number of characters until a newline or the end of the
 * list.
 */
int		gnl_lst_until_nl1(t_gnl *lst);

/**
 * @brief
 * This function allocates memory for an array of nmemb
 * elements of size bytes each and initializes all bytes in
 * the allocated storage to zero.
 * @param size_t nmemb
 * Number of elements to allocate.
 * @param size_t size
 * Size of each element.
 * @return
 * A pointer to the allocated memory, or NULL if the
 * allocation fails.
 */
void	*gnl_ft_calloc(size_t nmemb, size_t size);

/**
 * @brief
 * This function moves the list to the next line.
 * @param t_gnl *lst
 * The list to be updated.
 * @param char *next_line
 * The next line to move to.
 * @return
 * Function returns nothing.
 */
void	gnl_lst_to_next_line(t_gnl *lst, char *next_line);

/**
 * @brief
 * This function frees the master list and associated
 * resources.
 * @param t_gnl **list
 * The master list to be freed.
 * @param t_gnl **clean_node
 * The node to be cleaned.
 * @param char **buf
 * The buffer to be freed.
 * @param char **nl
 * The newline to be freed.
 * @return
 * 0 if successful, -1 if an error occurs.
 */
int		gnl_free_master(t_gnl **list, t_gnl **clean_node, \
			char **buf, char **nl);

// char	*get_next_line(int fd);

// int		gnl_lst_until_nl(t_gnl *lst);
// int		gnl_lst_until_nl1(t_gnl *lst);
// void	*gnl_ft_calloc(size_t nmemb, size_t size);
// void	gnl_lst_to_next_line(t_gnl *lst, char *next_line);
// int		gnl_free_master(t_gnl **list, t_gnl **clean_node,
// 			char **buf, char **nl);

#endif /* LIBFT_H */
