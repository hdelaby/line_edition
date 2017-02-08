/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:52:20 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 13:53:20 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include "libft.h"
# include "term_config.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_winsz
{
	size_t	height;
	size_t	width;
}				t_winsz;

typedef struct	s_line
{
	size_t	cursor;
	size_t	length;
	size_t	hist_depth;
	t_winsz	winsz;
}				t_line;

char			*line_editing(void);

/*
** cursor_motion.c
*/

int				cursor_to_left(t_line *line, t_dlist **lst);
int				cursor_to_right(t_line *line, t_dlist **lst);
int				cursor_to_end(t_line *line, t_dlist **lst);
int				cursor_to_home(t_line *line, t_dlist **lst);

/*
** ft_getch.c
*/

int				ft_getch(void);

/*
** ft_dlstaddnext.c
*/

void			ft_dlstaddnext(t_dlist **head, t_dlist *new);

/*
** get_input.c
*/

int				delete_char(t_line *line, int key, t_dlist **lst);
int				insert_char(t_line *line, int key, t_dlist **lst);

/*
** ft_getwinsz.c
*/

int				ft_getwinsz(t_winsz *winsz);

/*
** tc_putc.c
*/

int				tc_putc(int c);

/*
** word_navigation.c
*/

int				goto_next_word(t_line *line, t_dlist **lst);
int				goto_prev_word(t_line *line, t_dlist **lst);

#endif
