/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reben-ha <reben-ha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:34:12 by reben-ha          #+#    #+#             */
/*   Updated: 2023/03/03 23:35:29 by reben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define FAIL -1

typedef struct s_list
{
	t_token			data;
	int				index;
	int				level_tree;
	int				level_side;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_bzero(void *dest, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int arg);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t nulb);
void	*ft_memcpy(void *dest, const void *src, size_t nulb);
void	*ft_memmove(void *dest, const void *src, size_t nulb);
void	*ft_memset(void *str, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *data);
int		ft_lstsize(t_list *lst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c, int option);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_cheack_gnl(const char *str, int c);

void	ft_printf(int fd, const char *str, ...);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *s, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_pos(unsigned int n, int fd);
int		ft_putnbr_hex(unsigned int n, int Ul, int fd);
int		ft_putptr(unsigned long long n, int fd);

void	ft_free(char **str);
void	ft_error(int status, int code);
void	ft_error_str(void *status, int code);
size_t	ft_matlen(char **matrix);
char	**ft_matrixdup(char **matrix);
t_list	*in(t_list *head, int index);
void	ft_indexing(t_list *list);

#endif
