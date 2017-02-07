/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:27:03 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/07 12:01:42 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"
#include "ft_printf.h"

int		line_end(t_line *line, t_dlist **lst)
{
	while (!arrow_right(line, lst))
		continue ;
	return (0);
}

int		line_begin(t_line *line, t_dlist **lst)
{
	while (!arrow_left(line, lst))
		continue ;
	return (0);
}

int		arrow_left(t_line *line, t_dlist **lst)
{
	if (line->cursor == 0)
		return (1);
	line->cursor--;
	if ((*lst)->prev)
		*lst = (*lst)->prev;
	tputs(tgetstr("le", NULL), 1, &tc_putc);
	return (0);
}

int		arrow_right(t_line *line, t_dlist **lst)
{
	if (line->cursor == line->length)
		return (1);
	line->cursor++;
	if ((*lst)->next)
		*lst = (*lst)->next;
	tputs(tgetstr("nd", NULL), 1, &tc_putc);
	return (0);
}
