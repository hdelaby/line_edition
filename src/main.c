/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 14:02:43 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "auto_completion.h"
#include "ft_printf.h"
#include "history.h"
#include "keys.h"
#include <curses.h>

/*
** "\e[6n" corresponds to escape sequence to get cursor position. It writes
** on stdin an input of type ^[[1;1R that we then parse.
*/

void	get_cursor_start_pos(t_line *line)
{
	char	answer[20];
	int		i;

	ft_putstr_fd("\e[6n", 0);
	ft_bzero(answer, 20);
	i = read(0, answer, 20);
	answer[i] = 0;
	i = 2;
	line->start.row = ft_atoi(answer + i);
	while (ft_isdigit(answer[i]))
		i++;
	line->start.col = ft_atoi(answer + i + 1);
}

char	*line_editing(void)
{
	int		key_pressed;
	t_line	line;

	raw_term_mode();
	ft_bzero(&line, sizeof(line));
	ft_putstr_fd("PROMPT > ", 0);
	get_cursor_start_pos(&line);
	while (42)
	{
		ft_getwinsz(&(line.winsz));
		key_pressed = get_key();
		if (key_pressed == KEY_RIGHT)
			cursor_to_right(&line);
		if (key_pressed == KEY_LEFT)
			cursor_to_left(&line);
		if (key_pressed > 31 && key_pressed < 128)
			insert_char(&line, key_pressed);
		if (key_pressed == KEY_ENTER)
			break;
	}
	default_term_mode();
	return (ft_strdup(line.cmd));
}

int		main(void)
{
	char *str;
	str = line_editing();
	ft_putendl(str);
	return (0);
}
