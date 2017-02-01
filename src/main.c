/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 17:34:18 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "ft_printf.h"

/*
** It is possible to encode parameters with tgoto
*/

int		auto_complete(t_dlist **lst)
{
	char	*str;
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = *lst;
	while (ptr && ptr->prev && ft_strcmp(ptr->prev->content, " "))
	{
		ptr = ptr->prev;
		i++;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	char *test = str;
	while (i)
	{
		*(str++) = *((char *)ptr->content);
		ptr = ptr->next;
		i--;
	}
	*str = '\0';
	ft_putstr(test);
	return (i);
}

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
			auto_complete(&lst);
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
