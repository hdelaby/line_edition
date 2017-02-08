/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_navigation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:29:30 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 14:02:57 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		goto_next_word(t_line *line, t_dlist **lst)
{
	while (ft_strcmp((*lst)->content, " "))
		if (cursor_to_right(line, lst))
			return (0);
	while (!ft_strcmp((*lst)->content, " "))
		if (cursor_to_right(line, lst))
			return (0);
	return (0);
}

int		goto_prev_word(t_line *line, t_dlist **lst)
{
	if ((*lst)->prev && !ft_strcmp((*lst)->prev->content, " "))
		cursor_to_left(line, lst);
	while (!ft_strcmp((*lst)->content, " "))
		if (cursor_to_left(line, lst))
			return (0);
	while (ft_strcmp((*lst)->content, " "))
		if (cursor_to_left(line, lst))
			return (0);
	cursor_to_right(line, lst);
	return (0);
}
