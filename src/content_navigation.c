/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_navigation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:13:08 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/17 15:17:32 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_edition.h"

void	goto_next_word(t_line *line)
{
	while (line->cmd[line->cursor] != ' ' && line->cursor != line->length)
		cursor_to_right(line);
	while (line->cmd[line->cursor] == ' ' && line->cursor != line->length)
		cursor_to_right(line);
}

void	goto_prev_word(t_line *line)
{
	if (line->cursor && line->cmd[line->cursor - 1] == ' ')
		cursor_to_left(line);
	while (line->cmd[line->cursor] == ' ' && line->cursor)
		cursor_to_left(line);
	while (line->cmd[line->cursor] != ' ' && line->cursor)
		cursor_to_left(line);
	if (line->cursor)
		cursor_to_right(line);
}

void	goto_next_line(t_line *line)
{
	line->cursor = line->cursor + line->winsz.col > line->length ?
		line->length : line->cursor + line->winsz.col;
	set_curpos(line);
}

void	goto_prev_line(t_line *line)
{
	line->cursor = line->cursor < line->winsz.col ? 0 : line->cursor -
		line->winsz.col;
	set_curpos(line);
}
