/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:19:38 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/09 14:26:59 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"

#include "ft_printf.h"

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

void	refresh_display(t_line *line, t_dlist **lst)
{
	char	disp[100];
	char	*tmp;
	int		i;

	ft_bzero(disp, 100);
	i = 0;
	while (*lst && (*lst)->next)
	{
		tmp = (*lst)->content;
		disp[i++] = *tmp;
		*lst = (*lst)->next;
		line->cursor++;
		if (i == 99)
		{
			ft_putstr_fd(disp, 0);
			i = 0;
			ft_bzero(disp, 100);
		}
	}
	ft_putstr_fd(disp, 0);
}

/*
** Need to work on deleting on multiple line! Issue when using "dc" on the last
** column of the line!
*/

int		delete_char(t_line *line, int key, t_dlist **lst)
{
	size_t	cur_pos;

	if (key == KEY_BACKSPACE)
		if (cursor_to_left(line, lst))
			return (1);
	if (key == KEY_DC && !ft_strcmp((*lst)->content, "\t"))
		return (1);
	ft_dlstremovenode(lst);
	line->length--;
	tputs(tgetstr("vi", NULL), 1, &tc_putc);
	cur_pos = line->cursor;
	tputs(tgetstr("cd", NULL), 1, &tc_putc);
	refresh_display(line, lst);
	while (line->cursor > cur_pos)
		cursor_to_left(line, lst);
	tputs(tgetstr("ve", NULL), 1, &tc_putc);
	return (0);
}
