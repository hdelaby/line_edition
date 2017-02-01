/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:19:38 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 15:33:46 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"

int		insert_char(t_line *line, int key, t_dlist **lst)
{
	tputs(tgetstr("im", NULL), 1, &tc_putc);
	ft_dlstadd(lst, ft_dlstnew(&key, 2));
	*lst = (*lst)->next;
	line->length++;
	line->cursor++;
	ft_putchar_fd(key, 0);
	tputs(tgetstr("ei", NULL), 1, &tc_putc);
	return (0);
}

int		delete_char(t_line *line, int key, t_dlist **lst)
{
	if (key == KEY_BACKSPACE)
		if (arrow_left(line, lst))
			return (1);
	if (key == KEY_DC && !ft_strcmp((*lst)->content, "\n"))
		return (1);
	tputs(tgetstr("dc", NULL), 1, &tc_putc);
	ft_dlstremovenode(lst);
	line->length--;
	return (0);
}
