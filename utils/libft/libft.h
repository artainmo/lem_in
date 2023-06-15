/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:21:03 by artainmo          #+#    #+#             */
/*   Updated: 2020/02/26 19:14:01 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
void			*ft_memset(void *b, int c, unsigned int len);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
void			*ft_memccpy(void *dst, const void *src, int c, unsigned int n);
void			*ft_memmove(void *dst, const void *src, unsigned int len);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
int				ft_strlen(const char *str);
unsigned int	ft_strlcpy(char *dest, const char *rc, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *h, const char *n, unsigned int m);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_str_isdigit(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));

int				ft_round(double d);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_last_decf(char *str);
char			*ft_ftoa(double f, int precision);
int				ft_count_b_zeros(char *str);
char		*ft_dec_to_hex(unsigned long long int s);
int				ft_abs(int a);
double			ft_atof(char *s);
int				ft_strrchr_m(char *s, int c);
char			*ft_strjoin_f(char *s1, char *s2, int free_);
char			*ft_strjoin_len_f(char *s1, int len1, char *s2, int len2, int free_);
int				ft_file_trim(char *filename, char trim);
int				ft_file_rep(char *filename, char trim, char replace);
int				ft_filebordertrim(char *filename, char *trim);
void			ft_error(char *text);
void			ft_errno(void);
void			ft_malloc_error(void);
char			*ft_cut_f(char *str, int len);
int 			ft_round_up(float x);
char 			*ft_strrev(char *str, int len);

void			ft_print_ds(char **str);
char			**add_end_ds(char **ds, char *add);
char			**remove_begin_ds(char **ds);
void 			free_ds(char **str);
int				ft_len_ds(char **double_str);

#endif
