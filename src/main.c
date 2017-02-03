/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/03 09:01:30 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "auto_completion.h"
#include "ft_printf.h"

/*
** It is possible to encode parameters with tgoto
*/

void	print_dlst(t_dlist *lst)
{
	lst = ft_dlstgethead(lst);
	while (lst)
	{
		if (ft_strcmp(lst->content, "\n"))
			ft_putstr_fd(lst->content, 0);
		lst = lst->next;
	}
}

char	*line_editing(void)
{
	int		key_pressed;
	t_line	line;
	t_dlist	*lst;

	key_pressed = 10;
	lst = ft_dlstnew(&key_pressed, 2);
	ft_bzero(&line, sizeof(t_line));
	while (42)
	{
		key_pressed = ft_getch();
		if (key_pressed == '\n')
			break;
		if (key_pressed == KEY_LEFT)
			arrow_left(&line, &lst);
		else if (key_pressed == KEY_RIGHT)
			arrow_right(&line, &lst);
		else if (key_pressed == KEY_DC || key_pressed == KEY_BACKSPACE)
			delete_char(&line, key_pressed, &lst);
		else if (key_pressed == KEY_STAB)
			auto_complete(&lst, &line);
		else if (key_pressed > 31)
			insert_char(&line, key_pressed, &lst);
	}
	ft_putchar('\n');
	print_dlst(lst);
	return ("\nDONE");
}

int		main(void)
{
	term_config();
	ft_putstr(line_editing());
	term_basic_config(NULL);
	return (0);
}
