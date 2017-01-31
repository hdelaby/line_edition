/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:46:24 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/04 14:32:03 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*unsigned_conv(t_expr *expr, intmax_t number)
{
	char	*str;

	if (!ft_strcmp("ll", expr->modifiers))
		number = (unsigned long long)number;
	else if (!ft_strcmp("l", expr->modifiers))
		number = (unsigned long)number;
	else if (!ft_strcmp("h", expr->modifiers))
		number = (unsigned short)number;
	else if (!ft_strcmp("hh", expr->modifiers))
		number = (unsigned char)number;
	else if (!ft_strcmp("z", expr->modifiers))
		number = (size_t)number;
	else if (!(*expr->modifiers))
		number = (unsigned int)number;
	if (expr->specifier == 'o')
		str = ft_uitoa_base(number, 8, 0);
	else if (expr->specifier == 'u')
		str = ft_uitoa_base(number, 10, 0);
	else if (expr->specifier == 'b')
		str = ft_uitoa_base(number, 2, 0);
	else
		str = expr->specifier == 'X' ? ft_uitoa_base(number, 16, 1) :
			ft_uitoa_base(number, 16, 0);
	return (str ? (str) : (NULL));
}

char	*signed_conv(t_expr *expr, intmax_t number)
{
	char test[50];

	if (!ft_strcmp("ll", expr->modifiers))
		number = (long long)number;
	else if (!ft_strcmp("l", expr->modifiers))
		number = (long)number;
	else if (!ft_strcmp("h", expr->modifiers))
		number = (short)number;
	else if (!ft_strcmp("hh", expr->modifiers))
		number = (char)number;
	else if (!(*expr->modifiers))
		number = (int)number;
	else
		number = (intmax_t)number;
	number < 0 ? ft_putnbrll_str(number, test, 0, 1) :
		ft_putnbrll_str(number, test, 0, 0);
	ft_strrev(test);
	return (ft_strdup(test));
}

int		int_arg(t_expr *expr, va_list ap)
{
	uintmax_t	number;
	char		*ret;
	int			char_displayed;

	char_displayed = 0;
	number = va_arg(ap, uintmax_t);
	if (ft_strchr("di", expr->specifier))
		ret = signed_conv(expr, number);
	else
		ret = unsigned_conv(expr, number);
	if (!ret)
		return (-1);
	char_displayed += format_menu(expr, ret);
	free(ret);
	return (char_displayed);
}
