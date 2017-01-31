/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:07:18 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/21 16:37:28 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

# define F_BLK "\e[30m"
# define F_RED "\e[31m"
# define F_GRE "\e[32m"
# define F_YEL "\e[33m"
# define F_BLU "\e[34m"
# define F_MAG "\e[35m"
# define F_CYA "\e[36m"
# define F_LGRY "\e[37m"
# define RESET "\e[0m"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

/*
** MEMORY
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** STRINGS
*/

size_t			ft_strlen(const char *s);
size_t			ft_strlenc(char *str, char c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_strcnew(size_t size, int c);
char			*ft_strfreejoin(char const *s1, char const *s2);
char			**ft_strsplit(char *str, char c);

/*
** NUMBER
*/

int				ft_atoi(const char *str);
int				ft_max(int a, int b);
int				ft_iterative_power(int nb, int power);
char			*ft_itoa(int n);

/*
** CHECK / MINOR STR MODIF
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isupper(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** PUT / DISPLAY
*/

void			ft_putchar(char c);
void			ft_putstr(char const *c);
void			ft_putendl(char const *c);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_puttab(char **tab);
void			ft_putlst(t_list *lst);
void			ft_putnbrll_str(intmax_t nb, char *str, int i, int is_neg);
void			ft_putwstr(wchar_t *wstr, char *str);

/*
** SINGLY LINKED LISTS
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstcpy(t_list *lst);
t_list			*ft_lstremoveif(t_list *lst, void *test);
t_list			*ft_lstfind(t_list *lst, void *data, int (*cmp)());
t_list			*ft_tab_to_lst(char **tab);
size_t			ft_lstsize(t_list *lst);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstaddback(t_list **alst, t_list *new);
void			ft_lstrev(t_list **head);
void			ft_lstbubsort(t_list **head, int (*cmp)());
void			ft_lstdelstr(void *content, size_t content_size);
void			*ft_lstpop(t_list **lst);
void			*ft_lstlastcontent(t_list *list);

/*
** DOUBLY LINKED LISTS
*/

t_dlist			*ft_dlstnew(void const *content, size_t content_size);
t_dlist			*ft_dlstgethead(t_dlist *dlst);
t_dlist			*ft_dlstgettail(t_dlist *dlst);
void			ft_dlstadd(t_dlist **head, t_dlist *new);
void			ft_dlstaddback(t_dlist **head, t_dlist *new);
void			ft_dlstremoveif(t_dlist **head, int cmp());
void			ft_dlstremovenode(t_dlist **head);

/*
** TAB
*/

size_t			ft_tablen(char **tab);
void			ft_tabdel(char **tab);
char			**ft_lst_to_tab(t_list *lst);
char			**ft_tabjoin(char **tab1, char **tab2);

/*
** OTHERS
*/

int				ft_nbrlen(int nb);
void			ft_strrev(char *str);
char			*ft_uitoa_base(uintmax_t nb, int base, int upper);
void			ft_utf8_encode(wchar_t c, unsigned char *b);
void			ft_putunicode(unsigned char *s);
size_t			ft_wcslen(wchar_t *wstr);
size_t			ft_wcs_nbchar(wchar_t *wstr, char *str);
char			*ft_build_path(char *path, char *fname);
char			*ft_extract_fname(char *path);
char			ft_get_ftype(mode_t mode);
int				ft_is_parent_dir(char *fname);
int				ft_isdir(char *path);

#endif
