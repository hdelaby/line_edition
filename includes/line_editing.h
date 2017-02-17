/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:52:20 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/17 11:18:09 by hdelaby          ###   ########.fr       */
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

# define MAX_CMD_LEN 4096

typedef struct	s_winsz
{
	size_t	row;
	size_t	col;
}				t_winsz;

typedef struct	s_line
{
	t_dlist	*hist;
	size_t	cursor;
	size_t	length;
	size_t	hist_depth;
	size_t	hist_size;
	t_winsz	winsz;
	t_winsz start;
	char	cmd[MAX_CMD_LEN];
}				t_line;

typedef struct	s_keymove
{
	int		key;
	void	(*p)(t_line *line);
}				t_keymove;

char			*line_editing(void);

/*
** content_navigation.c
*/

void			goto_next_word(t_line *line);
void			goto_prev_word(t_line *line);
void			goto_next_line(t_line *line);
void			goto_prev_line(t_line *line);

/*
** cursor_motion.c
*/

void			set_curpos(t_line *line);
void			cursor_to_left(t_line *line);
void			cursor_to_right(t_line *line);
void			cursor_to_end(t_line *line);
void			cursor_to_home(t_line *line);

/*
** ft_getch.c
*/

int				ft_getch(void);

/*
** get_input.c
*/

void			delete_char(t_line *line, int key);
void			insert_char(t_line *line, int key);

/*
** ft_getwinsz.c
*/

int				ft_getwinsz(t_winsz *winsz);

/*
** tc_putc.c
*/

int				tc_putc(int c);

#endif
