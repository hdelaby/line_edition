/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:19:38 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 12:05:12 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "term_config.h"

#include "ft_printf.h"

int		insert_char(t_line *line, int key)
{
	if (line->length + 1 >= MAX_CMD_LEN)
		return (1);
	ft_memmove(line->cmd + line->cursor + 1, line->cmd + line->cursor,
			MAX_CMD_LEN - line->cursor - 1);
	line->cmd[line->cursor] = key;
	line->length++;
	line->cursor++;
	tputs(tgetstr("im", NULL), 1, &tc_putc);
	ft_putchar_fd(key, 0);
	tputs(tgetstr("ei", NULL), 1, &tc_putc);
	return (0);
}

/* int		delete_char(t_line *line, int key, t_dlist **lst) */
/* { */
/* 	size_t	cur_pos; */

/* 	if (key == KEY_BACKSPACE) */
/* 		if (cursor_to_left(line, lst)) */
/* 			return (1); */
/* 	if (key == KEY_DC && !ft_strcmp((*lst)->content, "\t")) */
/* 		return (1); */
/* 	ft_dlstremovenode(lst); */
/* 	line->length--; */
/* 	tputs(tgetstr("vi", NULL), 1, &tc_putc); */
/* 	cur_pos = line->cursor; */
/* 	tputs(tgetstr("cd", NULL), 1, &tc_putc); */
/* 	refresh_display(line, lst); */
/* 	while (line->cursor > cur_pos) */
/* 		cursor_to_left(line, lst); */
/* 	tputs(tgetstr("ve", NULL), 1, &tc_putc); */
/* 	return (0); */
/* } */
