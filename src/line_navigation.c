/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_navigation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:58:28 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 16:14:32 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		goto_next_line(t_line *line, t_dlist **lst)
{
	size_t	i;

	i = 0;
	while (i < line->winsz.width)
	{
		i++;
		if (cursor_to_right(line, lst))
			return (1);
	}
	return (0);
}

int		goto_prev_line(t_line *line, t_dlist **lst)
{
	size_t	i;

	i = 0;
	while (i < line->winsz.width)
	{
		i++;
		if (cursor_to_left(line, lst))
			return (1);
	}
	return (0);
}
