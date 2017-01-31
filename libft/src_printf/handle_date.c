/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:45:15 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/04 16:11:47 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_date(char *argument, t_expr *expr)
{
	if (!ft_strcmp(expr->modifiers, "l"))
	{
		write(1, argument + 4, 2);
		write(1, "-", 1);
		write(1, argument + 2, 2);
		write(1, "-", 1);
		write(1, argument, 4);
		return ;
	}
	write(1, argument, 4);
	write(1, "-", 1);
	write(1, argument + 2, 2);
	write(1, "-", 1);
	write(1, argument + 4, 2);
}

/*
** Quite simple function to handle date arguments in this printf. Only accepts
** correctly formatted char * dates: yyyymmdd. If the modifier 'l' is applied,
** it prints to the french format, otherwise international one.
** Returns nb of characters read.
** NB: Could be improved in many ways. But time is precious...
*/

int		date_arg(t_expr *expr, va_list ap)
{
	char	*argument;
	int		char_displayed;

	argument = (char *)va_arg(ap, char *);
	if (ft_strlen(argument) < 8)
		return (-1);
	char_displayed = pre_width(expr);
	print_date(argument, expr);
	char_displayed += 10;
	char_displayed += post_width(expr);
	return (char_displayed);
}
