/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:35:52 by vintran           #+#    #+#             */
/*   Updated: 2022/04/20 05:47:13 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list	t_list;
struct		s_list
{
	void	*content;
	t_list	*next;
};

int			ft_atoi(const char *str);
void		ft_bzero(void *s, int n);
void		*ft_calloc(int nmemb, int size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dst, const void *src, int c, int n);
void		*ft_memchr(const void *s, int c, int n);
int			ft_memcmp(const void *s1, const void *s2, int n);
void		*ft_memcpy(void *dst, const void *src, int n);
void		*ft_memmove(void *dst, const void *src, int len);
void		*ft_memset(void *b, int c, int len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(const char *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlcat(char *dst, const char *src, int size);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
int			ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, int n);
char		*ft_strnstr(const char *s1, const char *s2, int n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, int len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_putstr(char *str);
void		ft_putchar(char c);
char		*ft_strndup(const char *s, size_t n);

#endif
