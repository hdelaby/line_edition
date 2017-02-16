/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 17:32:01 by hdelaby          ###   ########.fr       */
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

void	recognise_key(int key_pressed, t_line *line)
{
	int			i;
	t_keymove	keymove[8] = {
		{KEY_RIGHT, &cursor_to_right},
		{KEY_LEFT, &cursor_to_left},
		{KEY_HOME, &cursor_to_home},
		{KEY_END, &cursor_to_end},
		{KEY_SRIGHT, &goto_next_word},
		{KEY_SLEFT, &goto_prev_word},
		{KEY_SPREVIOUS, &goto_prev_line},
		{KEY_SNEXT, &goto_next_line}
	};
	
	i = 0;
	while (i < 8)
		if (key_pressed == keymove[i++].key)
			keymove[i - 1].p(line);
}

char	*line_editing(void)
{
	int		key_pressed;
	t_line	line;

	raw_term_mode();
	ft_bzero(&line, sizeof(line));
	line.hist = retrieve_history("sh_history");
	ft_putstr_fd("PROMPT > ", 0);
	get_cursor_start_pos(&line);
	ft_getwinsz(&(line.winsz));
	while (42)
	{
		if (line.start.row + line.cursor / line.winsz.col > line.winsz.row)
			line.start.row--;
		key_pressed = get_key();
		recognise_key(key_pressed, &line);
		if (key_pressed > 31 && key_pressed < 127)
			insert_char(&line, key_pressed);
		if (key_pressed == KEY_DC || key_pressed == 127)
			delete_char(&line, key_pressed);
		if (key_pressed == '\n')
			break;
	}
	cursor_to_end(&line);
	default_term_mode();
	ft_putchar('\n');
	append_history("sh_history", line.cmd);
	return (ft_strdup(line.cmd));
}

int		main(void)
{
	char *str;
	str = line_editing();
	ft_putendl(str);
	return (0);
}
