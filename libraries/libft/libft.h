/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:19:37 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/13 15:19:37 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define INT_MIN 		-2147483648
# define INT_MAX 		2147483647
# define BUFFER_SIZE	100

int		ft_atoi_base(char *str, char *base);

/**
 * @brief convert string to integer. The string should contain numbers.
 * @param (char *ptr) pointer to a string.
 * @return (sign * res) a integer.
**/
int		ft_atoi(const char *ptr);

/**
 * @brief 	erases the data in the n bytes of the memory starting at
 			the location pointed to by s, by writing zeros (bytes
	   		containing '\0')  to  that area.
 * @param 1 pointer to a string.
 * @param 2 number of bytes to be converted to 0.
 * @return
**/
void	ft_bzero(void *s, size_t n);

/**
 * @brief 	allocates memory for an array of nmemb elements of size.
 * 			bytes each and returns a pointer to the allocated memory.
 * 			The memory is set  to
       		zero.
 * @param 1 number of members of the array
 * @param 2 bytes size of the each member of the array (ex: sizeof(int)).
 * @return  The malloc() and calloc() functions return a pointer to
 * 			the allocated memory, which is suitably aligned for any built-in
 * 			 type.
			If the multiplication of nmemb and size would result in
			integer overflow, then calloc() returns an error.
			If  nmemb  or  size is 0, returns either NULL, or a unique
			pointer value that can later be successfully passed to free().
**/
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief 	checks for an alphanumeric character; it is equivalent
			to (isalpha(c) || isdigit(c)).
 * @param 1 a integer
 * @return  The  values returned are nonzero if the character c
			falls into the tested class, and zero if not.
**/
int		ft_isalnum(int c);

/**
 * @brief	checks for an alphabetic character; in the standard  "C"  locale,
			it is equivalent  to (isupper(c) || islower(c)).
 * @param 1 parameteer that will be checked.
 * @return  The  values returned are nonzero if the character c
			falls into the tested class, and zero if not.
**/
int		ft_isalpha(int c);

/**
 * @brief 	checks whether c is a 7-bit unsigned char value that fits
			into the ASCII character set.
 * @param 1 parameter that will be checked
 * @return  The  values returned are nonzero if the character c
			falls into the tested class, and zero if not.
**/
int		ft_isascii(int c);

/**
 * @brief	checks for a digit (0 through 9).
 * @param 1 a charactere
 * @return  The  values returned are nonzero if the character c
			falls into the tested class, and zero if not.
**/
int		ft_isdigit(int c);

/**
 * @brief 	checks for any printable character including space.
 * @param 1 A integer.
 * @return  The  values returned are nonzero if the character c
			falls into the tested class, and zero if not.
**/
int		ft_isprint(int c);

/**
 * @brief	Allocates (with malloc(3)) and returns a string representing
 * 			the integer
 * 			received as an argument. Negative numbers must be handled.
 * @param 1 the integer to convert.
 * @return  The string representing the integer. NULL if the allocation fails.
**/
char	*ft_itoa(int n);

/**
 * @brief	Adds the element ’new’ at the end of the list.
 * @param 1 The address of a pointer to the first link of a list.
 * @param 2 The address of a pointer to the element to be added to the list.
 * @return  None
**/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief	Adds the element ’new’ at the beginning of the list.
 * @param 1 The address of a pointer to the first link of a list.
 * @param 2 The address of a pointer to the element to be added to the list.
 * @return  None
**/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief	Deletes and frees the given element and every successor of
 * 			that element,
 * 			using the function ’del’ and free(3).
 * 			Finally, the pointer to the list must be set to NULL.
 * @param 1 The adress of a pointer to an element.
 * @param 2 The adress of the function used to delete the content of
 * 			the element.
 * @return  None.
**/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief	Takes as a parameter an element and frees the memory of
 * 			the element’s content
 * 			using the function ’del’ given as a parameter and free the element.
 * 			The memory of ’next’ must not be freed.
 * @param 1 The element to free.
 * @param 2 The address of the function used to delete the content.
 * @return  None
**/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief	Iterates the list ’lst’ and applies the function ’f’ to the
 * 			content of each element.
 * @param 1	The adress of a pointer to an element.
 * @param 2 The adress of the function used to iterate on the list.
 * @return  None
**/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief	Returns the last element of the list.
 * @param 1 The beginning of the list.
 * @return  Last element of the list.
**/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief	Iterates the list ’lst’ and applies the function ’f’ to the
 * 			content of each element.
 * 			Creates a new list resulting of the successive applications
 * 			of the function ’f’.
 * 			The ’del’ function is used to delete the content of an element
 * 			if needed.
 * @param 1 The adress of a pointer to an element.
 * @param 2 The adress of the function used to iterate on the list.
 * @param 3 The adress of the function used to delete the content of an
 * 			element if needed.
 * @return  The new list. NULL if the allocation fails.
**/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief	Allocates (with malloc(3)) and returns a new element.
 * 			The variable ’content’
 * 			is initialized with the value of the parameter ’content’.
 * 			The variable ’next’
 * 			is initialized to NULL.
 * @param 1 The content to create the new element with.
 * @return  The new element.
**/
t_list	*ft_lstnew(void *content);

/**
 * @brief	Counts the number of elements in a list.
 * @param 1 The beginning of the list.
 * @return  Length of the list.
**/
int		ft_lstsize(t_list *lst);

/**
 * @brief	Scans the inicial n bytes of the memory arrea pointed to
 			by s for the first instance of c. Both are interpreted
			as unsigned char.
 * @param 1 *s	-pointer too a memory area.
 * @param 2 unsigned char c
 * @param 3 number of bytes to looking for.
 * @return  return a pointer to the matching byte or NULL if the character
 			does not occur in the given memory area.
**/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief	compares the first n bytes (each interpreted as unsigned char)
 * 			of the memory area s1 and s2.
 * @param 1 s1	-memory area 1
 * @param 2 s2	-memory area 2
 * @return  integer < 0	-n bytes of s1 < bytes of s2
  			integer = 0	-n bytes of s1 = bytes of s2
			integer > 0	-n bytes of s1 > bytes of s2
			The sign of the return is determined by the sign of the
			difference between the first pair of bytes (interpreted as
			unsigned char)
			that differ in s1 and s2.
			If n is 0, the return value is 0
**/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief	Copies n bytes from memory area src to memory area dest.
			The memory areas must not overlap.
			Use memmove(3) if the memory areas do over‐lap.
 * @param 1 *dest	- destiny memory area.
 * @param 2 *src	- source memory area.
 * @param 4 size_t n- number of bytes to be copied.
 * @return  Returns a pointer to dest.  If parameters are NUll segmentfault
 * 			returns.
**/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief 	copies n bytes from memory area src to memory area dest.
 * 			The memory areas may overlap: copying takes place as though
 * 			the bytes in src are first copied into a temporary array that
 * 			does not overlap src or dest, and the bytes are then copied from
 * 			 the temporary array to dest.
 * @param 1 *dest	-memory area where is going to be copied to.
 * @param 2 *src	-memory area where is going to be copied by.
 * @return  A pointer to dest. If parameters are NUll segmentfault returns.
**/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief 	Fills the first n bytes of the memory area pointed to by s
			with the constant byte c. #include <string.h>
 * @param 1 void *s	- pointer to a memory área.
 * @param 2	int c'	- any constant.
 * @param 3 size_t n- number of bytes.
 * @return  A pointer to the memory area s.
**/
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief 	Outputs the character ’c’ to the given file descriptor.
 * @param 1 The character to output.
 * @param 2	The file descriptor on which to write.
 * @return  None
**/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief 	Outputs the string ’s’ to the given file descriptor, followed
 * 			by a new line.
 * @param 1 The string to output.
 * @param 2	The file descriptor on which to write.
 * @return  None
**/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief 	Outputs the integer ’n’ to the given file descriptor.
 * @param 1 The integer to output.
 * @param 2	The file descriptor on which to write.
 * @return  None
**/
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief 	Outputs the string ’s’ to the given file descriptor.
 * @param 1 The string to output.
 * @param 2	The file descriptor on which to write.
 * @return  None
**/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief 	Allocates (with malloc(3)) and returns an array of strings
 * 			obtained by
 * 			splitting ’s’ using the character ’c’ as a delimiter.
 * 			The array must be
 * 			ended by a NULL pointer.
 * 			to free the malloc is necessary a loop as follow:
 *
 * @param 1 The string to be split.
 * @param 2 The delimiter character.
 * @return  The array of new strings resulting from the split. NULL if
 * 			the allocation fails.
**/
char	**ft_split(char const *s, char c);

/**
 * @brief	returns a pointer to the first occurrence of the character c in
 * 			the string s.
 * @param 1 pointer to the string
 * @param 2 character c
 * @return  return a pointer to the matched character or NULL if the
 * 			character is not found.
			The terminating null byte is considered part of the string, so
			that if c is
			specified as '\0', these functions return a pointer to the terminator.
**/
char	*ft_strchr(const char *s, int c);

/**
 * @brief 	duplicates the string s. Memory for the new string is obteined
 * 			with malloc, and can
			be freed with free. the NUll character is added to the end.
 * @param 1 string s
 * @return  a pointer to the new string.
**/
char	*ft_strdup(const char *s);

/**
 * @brief	Applies the function f to each character of the string passed
 * 			as argument, and passing its index as first argument.
 * 			Each character is passed by address to f to be modified
 * 			if necessary.
 * @param 1 The string on which to iterate.
 * @param 2 The function to apply to each character.
 * @return  None.
**/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief 	Allocates (with malloc(3)) and returns a new string, which is
 * 			the result of the
 * 			concatenation of ’s1’ and ’s2’.
 * @param 1 the prefix string
 * @param 2 the sufix string
 * @return  returns a new string, which is the result of the concatenation
 * 			of ’s1’ and ’s2’.
**/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief 	appends  the NULL terminated  src string to the dest string,
 * 			overwriting the terminating null byte ('\0') at the end of dest
 * 			 at most n bytes from src, and then adds a terminating null byte.
 * 			The strings may not overlap, and the dest string must have enough
 * 			space for the result.
 * 			If dest is not large enough, program behavior is unpredictable.
 * 			src does not need to be null-terminated if it contains n or
 * 			more bytes.
 * @param 1 pointer to the destination memory area
 * @param 2 pointer to the source memory area
 * @param 3	buffer size in bytes
 * @return  return the total length of the string, that is the initial
 * 			length of dest plus the length of src.
**/
size_t	ft_strlcat(char *dest, const char *src, size_t n);

/**
 * @brief 	copies up to size -1 characters from the NULL teminated src to
 * 			dest string an and NULL terminate the dest string.
 * @param 1 Pointer to the destination area of memory.
 * @param 2 Pointer to the source area of memory
 * @return  Buffer size in bytes.
**/
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

/**
 * @brief	calculates the length of the string pointed to by s, excluding
 * 			the terminating null.
 * 			byte ('\0').
 * @param 1
 * @return  the number of bytes in the string pointed to by s.
 * 			If parameters are NUll segmentfault returns.
**/
size_t	ft_strlen(const char *s);

/**
 * @brief	Applies the function ’f’ to each character of the string ’s’
 * 			to create a new string (with malloc(3)) resulting from
 * 			successive applications of ’f’.
 * @param 1 The string on which to iterate.
 * @param 2 The function to apply to each character.
 * @return  The string created from the successive applications of ’f’.
 * 			Returns NULL if the allocation fails.
**/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief	compares the first at most n bytes from two strings s1 and s2.
 * 			The locale is not taken into account.
 * @param 1
 * @param 2
 * @return  return an integer less than, equal to, or greater than zero if
 * 			s1 (or the first n bytes thereof) is found, respectively,
 * 			to be less than, to match, or be greater than s2.
**/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief 	finds the first occurrence of the substring needle in the
 * 			string haystack.
			The terminating null bytes ('\0') are not compared.
 * @param 1
 * @param 2
 * @param 3
 * @return  a pointer to the beginning of the located substring, or NULL if
 * 			the substring is not found.
**/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @brief	returns a pointer to the last occurrence of the character c in
 * 			the string s.
 * @param 1	pointer to the string
 * @param 2 character c
 * @return  returns a pointer to the matched character, or a pointer to
 * 			the null byte at the end of s (i.e., s+strlen(s)) if the
 * 			character is not found.
**/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief	Allocates (with malloc(3)) and returns a copy of ’s1’ with
 * 			the characters specified in ’set’ removed from the beginning
 * 			and the end of the string.
 * @param 1 The string to be trimmed.
 * @param 2 The reference set of characters to trim.
 * @return  The trimmed string. NULL if the allocation fails.
 * 			If parameters are NUll segmentfault returns.
**/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief 	Allocates (with malloc(3)) and returns a substring from the
 * 			string ’s’.	The substring begins at index ’start’ and is of
 * 			maximum size ’len’.
 * @param 1 The string from which to create the substring.
 * @param 2 The start index of the substring in the string ’s’.
 * @param 3	The maximum length of the substring.
 * @return  The substring. NULL if the allocation fails.
**/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief 	Change a alpha character from uppercase to lowercase.
 * @param 1
 * @param 2
 * @return  a alpha lowercase character.
**/
int		ft_tolower(int c);

/**
 * @brief 	Change a alpha character from lowercase to uppercase.
 * @param 1
 * @param 2
 * @return  a alpha uppercase character.
**/
int		ft_toupper(int c);

char	*ft_get_next_line(int fd);

void	ft_split_free(char **ptr);

char	*ft_str_superjoin(char **src);

#endif
