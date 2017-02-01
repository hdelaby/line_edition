/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 09:00:39 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "ft_printf.h"

/*
** It is possible to encode parameters with tgoto
*/

void	print_dlst(t_dlist *lst)
{
	lst = ft_dlstgethead(lst);
	while (lst)
	{
		ft_putstr_fd(lst->content, 0);
		lst = lst->next;
	}
}

char	*line_editing(void)
{
	int		key_pressed;
	int		i;
	t_dlist	*lst;

	lst = NULL;
	i = 0;
	while (42)
	{
		key_pressed = ft_getch();
		if (key_pressed == '\n')
			break;
		if (key_pressed == 27)
		{
			tputs(tgetstr("le", NULL), 1, &tc_putc);
			tputs(tgetstr("dc", NULL), 1, &tc_putc);
		}
		else
		{
			ft_dlstaddnext(&lst, ft_dlstnew(&key_pressed, 2));
			ft_putchar_fd(key_pressed, 0);
		}
	}
	return ("LOL");
}

int		main(void)
{
	term_config();
	ft_putstr(line_editing());
	term_basic_config(NULL);
	return (0);
}
