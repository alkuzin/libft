# libft Documentation

## Contents

1. [Introduction](#1-introduction)
2. [Installation](#2-installation)
3. [Ctype functions](#3-ctype-functions)
4. [Math functions](#4-math-functions)
5. [Memory functions](#5-memory-functions)
6. [Stdio functions](#6-stdio-functions)
7. [Stdlib functions](#7-stdlib-functions)
8. [String functions](#8-string-functions)

## 1. Introduction
The libft - rewrited C standard library for own projects.

## 2. Installation
First clone this repository:
```console
git clone https://github.com/alkuzin/libft.git
```
Then move to the __`libft/`__ directory and run:
```console
make all && make clean
```
Then include the __`libft.h`__ header file in your project.
```c
#include "<path to your project>/libft/libft.h"
/* project code here */
```
Finaly compile your project, including __`libft.a`__ file.

To return everything to original state:
```console
make fclean
```

## 3. Ctype functions
The __`ft_ctype.h`__ declares several functions that are useful for testing and mapping characters.

```c
/* Checks for an alphabetic character */
extern int ft_isalpha(int c);

/* Checks for a digit */
extern int ft_isdigit(int c);

/* Checks for an alphanumeric character */
extern int ft_isalnum(int c);

/* Checks for an ASCII character */
extern int ft_isascii(int c);

/* Checks for a printable character (including space) */
extern int ft_isprint(int c);

/* Converts to an uppercase character */
extern int ft_toupper(int c);

/* Converts to lowercase character */
extern int ft_tolower(int c);

/* Checks for an uppercase character */
extern int ft_isupper(int c);

/* Checks for a lowercase character */
extern int ft_islower(int c);
```

## 4. Math functions

The __`ft_math.h`__ defines various mathematical functions.
```c
/* The ft_inf() return infinity */
extern double ft_inf(void);

/* The ft_log() calculates natural logarithm */
extern double ft_log(double x);

/* The ft_pow() is equal to 'x^y' in math */
extern double ft_pow(double x, double y);

/* The ft_exp() is equal to 'e^x' in math */
extern double ft_exp(double x);

/* The ft_sqrt() calculates the square root */
extern double ft_sqrt(double x);

/* The ft_factorial() is equal to 'n!' in math (up to 20! including) */
extern unsigned long ft_factorial(unsigned int n);

/* The ft_pfactorial() is equal calculating factorial from n to m including */
extern unsigned long ft_pfactorial(unsigned int n, unsigned int m);

/* Combinatorical functions */

/* The ft_permutations() permutations without repetition */
extern unsigned long ft_permutations(unsigned int n);

/* The ft_variations() variations without repetition */
extern unsigned long ft_variations(unsigned int m, unsigned int n);

/* The ft_variations_r() variations with repetition */
extern unsigned long ft_variations_r(unsigned int n, unsigned int m);

/* The ft_combinations() combinations without repetition */
extern unsigned long ft_combinations(unsigned int m, unsigned int n);

/* The ft_combinations_r() combinations with repetition */
extern unsigned long ft_combinations_r(unsigned int m, unsigned int n);
```
## 5. Memory functions

The __`ft_memory.h`__ defines several memory management functions.

```c
/* The ft_memset() fills the first n bytes of the 
 * memory of the area pointed to by s 
 * with the constant byte c. */
extern void *ft_memset(void *s, int c, size_t n);

/* The ft_bzero() erases the data in the n bytes 
 * of the memory of the area pointed to by s, 
 * by writing '\0' bytes to that area. */
extern void ft_bzero(void *s, size_t n);

/* The ft_memcpy() copies n bytes from memory area src
 * to memory area dest. */
extern void *ft_memcpy(void *dest, const void *src, size_t n);

/* The ft_memccpy() copies no more than n bytes 
 * from memory area src to memory area dest, 
 * stopping when the character c is found. */
extern void *ft_memccpy(void *dest, const void *src, int c, size_t n);

/* The ft_memmove() copy n bytes 
 * from memory area src to memory area dest. */
extern void *ft_memmove(void *dest, const void *src, size_t n);

/* The ft_memchr() scans the initial n bytes
 * of the memory area pointed to by s
 * for the first instance of c. */
extern void *ft_memchr(const void *s, int c, size_t n);

/* The ft_memcmp() function compares the 
 * first n bytes (each interpreted as 
 * unsigned char) of the memory areas s1 and s2. */
extern int ft_memcmp(const void *s1, const void *s2, size_t n);
```

## 6. Stdio functions

The __`ft_stdio.h`__ defines several output functions.

```c
/* Print character */
extern void ft_putchar(char c);

/* Print string on the current line */
extern void ft_putstr(char *str);

/* Print string on the new line */
extern void ft_puts(char *str);

/* Outputs the character ’c’ to the given file descriptor. */
extern void ft_putchar_fd(char c, int fd);

/* Outputs the string ’s’ to the given file descriptor. */
extern void ft_putstr_fd(char *s, int fd);

/* Outputs the string ’s’ to the given file 
 * descriptor, followed by a newline. */
extern void ft_putendl_fd(char *s, int fd);

/* Outputs the integer ’n’ to the given file descriptor.*/
extern void ft_putnbr_fd(int n, int fd);
```

## 7. Stdlib functions

The __`ft_stdlib.h`__ defines several standard library functions.

```c
/* The atoi() converts the initial portion 
 * of the string pointed to by str to int. */
extern int ft_atoi(char *str);

/* The ft_range() returns the array of int 
 * from min including to max excluding. */
extern int *ft_range(int min, int max);

/* The ft_calloc() allocates memory for an 
 * array of nmemb elements of size bytes each and 
 * returns a pointer to the allocated memory.  
 * The memory is set to zero. */
extern void *ft_calloc(size_t nmemb, size_t size);
```

## 8. String functions

The __`ft_string.h`__ defines several strings management functions.

```c
/* Get string length */
extern int ft_strlen(const char *str);

/* Copy a string with truncation. */
extern size_t ft_strlcpy(char *dest, const char *src, size_t size);

/* Catenate a string with truncation. */
extern size_t ft_strlcat(char *dest, const char *src, size_t size);

/* The ft_strchr() returns a pointer to the 
 * first occurrence of the character c in the string s. */
extern char *ft_strchr(const char *s, int c);

/* The ft_strrchr() returns a pointer to the 
 * last occurrence of the character c in the string s. */
extern char *ft_strrchr(const char *s, int c);

/* The ft_strnstr() function locates the first	occurrence 
 * of the  null-termi-nated string little in the 
 * string big, where not more than len characters are searched. */
extern char *ft_strnstr(const char *big, const char *little, size_t len);

/* The ft_strcmp() compares the two strings s1 and s2. */
extern int ft_strncmp(char *s1, char *s2, size_t n);

/* The ft_split() returns an array of strings obtained by splitting ’s’
 * using the character ’c’ as a delimiter.*/
extern char **ft_split(char *str, char *charset);

/* The ft_strdup() returns a pointer to a new string 
 * which is a duplicate of the string s. */
extern char *ft_strdup(const char *src);

/* The ft_strjoin() returns a new string, which is 
 * the result of the concatenation of ’s1’ and ’s2’. */
extern char *ft_strjoin(int size, char **strs, char *sep);

/* The ft_substr() returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’ */
extern char *ft_substr(char const *s, unsigned int start, size_t len);

/* The ft_strtrim() returns a copy of ’s1’ with the characters specified 
 * in ’set’ removed from the beginning and the end of the string. */
extern char *ft_strtrim(char const *s1, char const *set);

/* The ft_itoa() returns a string representing the 
 * integer received as an argument. */
extern char *ft_itoa(int n);

/* The ft_strmapi() applies the function ’f’ to each character of the string ’s’ */
extern char *ft_strmapi(char const *s, int (*f)(int));
```
