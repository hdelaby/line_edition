/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:27:03 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 16:36:19 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"
#include "ft_printf.h"

int		cursor_to_end(t_line *line, t_dlist **lst)
{
	while (!cursor_to_right(line, lst))
		continue ;
	return (0);
}

int		cursor_to_home(t_line *line, t_dlist **lst)
{
	while (!cursor_to_left(line, lst))
		continue ;
	return (0);
}

int		cursor_to_left(t_line *line, t_dlist **lst)
{
	if (line->cursor == 0)
		return (1);
	line->cursor--;
	if ((*lst)->prev)
		*lst = (*lst)->prev;
	if (line->cursor + 1 % line->winsz.width)
		tputs(tgetstr("le", NULL), 1, &tc_putc);
	else
	{
		tputs(tgetstr("up", NULL), 1, &tc_putc);
		tputs(tgoto("ch", 0, line->winsz.width), 1, &tc_putc);
	}
	return (0);
}

int		cursor_to_right(t_line *line, t_dlist **lst)
{
	if (line->cursor == line->length)
		return (1);
	line->cursor++;
	if ((*lst)->next)
		*lst = (*lst)->next;
	if (line->cursor && line->cursor % line->winsz.width)
		tputs(tgetstr("nd", NULL), 1, &tc_putc);
	else if (line->cursor)
		tputs(tgetstr("docr", NULL), 1, &tc_putc);
	return (0);
}
