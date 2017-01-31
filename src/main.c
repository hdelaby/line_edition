/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/31 14:25:02 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include "ft_printf.h"

void	ft_dlstaddnext(t_dlist **head, t_dlist *new)
{
	t_dlist	*ptr;

	ptr = NULL;
	if (!new || !head)
		return ;
	if (*head)
	{
		ptr = (*head)->next;
		(*head)->next = new;
	}
	new->prev = *head;
	new->next = ptr;
	if (ptr)
	{
		ptr->prev = new;
		*head = ptr;
	}
	else
		*head = new;
}

int		tc_putc(int c)
{
	return (write(0, &c, 1));
}

void	print_dlst(t_dlist *lst)
{
	tputs(tgetstr("crce", NULL), 0, &tc_putc);
	lst = ft_dlstgethead(lst);
	while (lst)
	{
		ft_putstr_fd(lst->content, 0);
		lst = lst->next;
	}
}

int		ft_getch()
{
	char	buf[3];
	read(0, buf, 3);
	return (buf[0]);
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
		else if (key_pressed == 27)
		{
			tputs(tgetstr("le", NULL), 0, &tc_putc);
			lst = lst->prev;
		}
		else
			ft_dlstaddnext(&lst, ft_dlstnew(&key_pressed, 2));
		print_dlst(lst);
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
