/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:40:24 by youngski          #+#    #+#             */
/*   Updated: 2022/12/30 20:06:19 by youngski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

typedef struct s_mynode
{
	char			*content;
	int				fd;
	struct s_mynode	*next;
	ssize_t			size;
}					t_mynode;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t			ft_strlen(const char *s);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*get_next_line(int fd);
char			*appending_save(char *dest, t_mynode *temp_n);
char			*make_return(t_mynode *temp, t_mynode **root);
char			*get_next_line(int fd);
char			*free_node(t_mynode **root, int fd);
int				read_line(t_mynode *temp, t_mynode **root);
t_mynode		*create_node(int fd);
t_mynode		*find_node(t_mynode **root, int fd);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
long			ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

t_list			*ft_lstnew(int data);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst);
void			ft_lstclear(t_list **lst);
void			ft_lstiter(t_list *lst);

int				err_check(const char *str, va_list ap);
int				print_memo(va_list ap);
char			*make_hex(size_t t_temp, char *hex);
int				print_str(va_list ap, int flag);
int				print_anything(int arg, char *degree, char *print, int index);
int				check_limit(void *arg, int flag);
int				print_decimal(va_list ap);
int				print_udecimal(va_list ap);
int				print_hex(va_list ap, int flag);
int				ft_printf(const char *str, ...);
int				ft_issp(char c);

unsigned int	ft_strlcpy(char *dest, char const *src, unsigned int size);
#endif
