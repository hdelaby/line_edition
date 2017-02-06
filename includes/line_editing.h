/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:52:20 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/06 15:06:35 by hdelaby          ###   ########.fr       */
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

typedef struct	s_line
{
	size_t	cursor;
	size_t	length;
}				t_line;

char			*line_editing(void);

/*
** cursor_motion.c
*/

int				arrow_left(t_line *line, t_dlist **lst);
int				arrow_right(t_line *line, t_dlist **lst);

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
** tc_putc.c
*/

int				tc_putc(int c);

#endif
