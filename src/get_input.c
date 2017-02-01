/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:19:38 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 10:58:29 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"

int		insert_char(t_line *line, int key, t_dlist **lst)
{
	tputs(tgetstr("im", NULL), 1, &tc_putc);
	line->length++;
	line->cursor++;
	ft_dlstaddnext(lst, ft_dlstnew(&key, 2));
	if (line->length != line->cursor && line->cursor && (*lst)->prev) 
		*lst = (*lst)->prev;
	ft_putchar_fd(key, 0);
	tputs(tgetstr("ei", NULL), 1, &tc_putc);
	return (0);
}
