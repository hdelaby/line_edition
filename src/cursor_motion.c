/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:27:03 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 13:58:47 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"
#include "ft_printf.h"

void	set_curpos(t_line *line)
{
	size_t	xpos;
	size_t	ypos;

	xpos = line->start.col + line->cursor % line->winsz.col;
	ypos = line->start.row + line->cursor / line->winsz.col;
	if (xpos > line->winsz.col)
	{
		xpos %= line->winsz.col;
		ypos++;
	}
	tputs(tgoto(tgetstr("cm", NULL), xpos - 1, ypos - 1), 0, &tc_putc);
}

/* int		cursor_to_end(t_line *line, t_dlist **lst) */
/* { */
/* 	while (!cursor_to_right(line, lst)) */
/* 		continue ; */
/* 	return (0); */
/* } */

/* int		cursor_to_home(t_line *line, t_dlist **lst) */
/* { */
/* 	while (!cursor_to_left(line, lst)) */
/* 		continue ; */
/* 	return (0); */

void	cursor_to_left(t_line *line)
{
	if (!line->cursor)
		return ;
	line->cursor--;
	set_curpos(line);
}

void	cursor_to_right(t_line *line)
{
	if (line->cursor == line->length)
		return ;
	line->cursor++;
	set_curpos(line);
}
