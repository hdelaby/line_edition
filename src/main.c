/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 11:49:23 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "auto_completion.h"
#include "ft_printf.h"
#include "history.h"
#include "keys.h"
#include <curses.h>

/*
** It is possible to encode parameters with tgoto
*/

void	print_dlst(t_dlist *lst)
{
	lst = ft_dlstgethead(lst);
	while (lst)
	{
		if (ft_strcmp(lst->content, "\t"))
			ft_putstr_fd(lst->content, 0);
		lst = lst->next;
	}
}

char	*line_editing(void)
{
	int		key_pressed;
	t_line	line;

	ft_putstr("PROMPT $> ");
	while (42)
	{
		ft_getwinsz(&(line.winsz));
		key_pressed = get_key();
		if (key_pressed == KEY_ENTER)
			break;

	}
	return ("LOL");
}

int		main(void)
{
	char *str;
	raw_term_mode();
	str = line_editing();
	default_term_mode();
	ft_putendl(str);
	return (0);
}
