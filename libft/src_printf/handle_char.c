/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:51:22 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 15:40:40 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		invalid_arg(t_expr *expr, va_list ap)
{
	int		char_displayed;

	ap += 0;
	expr->width -= 1;
	char_displayed = 0;
	char_displayed += pre_width(expr);
	ft_putchar(expr->specifier);
	char_displayed += post_width(expr);
	return (char_displayed + 1);
}

int		pct_arg(t_expr *expr, va_list ap)
{
	int		char_displayed;

	char_displayed = 0;
	if (ap)
		expr->specifier = '%';
	expr->width -= 1;
	char_displayed += pre_width(expr);
	ft_putchar('%');
	char_displayed += post_width(expr);
	return (char_displayed + 1);
}

/*
** Handles w_char argument (%lc and %C). Here we convert the value to UTF8
** and store the converted sequence in str.
** Special case for 0
*/

int		upperc_arg(t_expr *expr, va_list ap)
{
	char	*wchar;
	wchar_t	arg;
	int		char_displayed;

	char_displayed = 0;
	if ((wchar = (char *)malloc(5)) == NULL)
		return (-1);
	arg = (wchar_t)va_arg(ap, int);
	ft_bzero(wchar, 5);
	ft_utf8_encode(arg, (unsigned char *)wchar);
	if (!wchar)
	{
		free(wchar);
		return (-1);
	}
	expr->width -= arg ? ft_strlen(wchar) : 1;
	char_displayed += arg ? ft_strlen(wchar) : 1;
	char_displayed += pre_width(expr);
	arg ? ft_putstr(wchar) : ft_putchar(0);
	free(wchar);
	char_displayed += post_width(expr);
	return (char_displayed);
}

int		c_arg(t_expr *expr, va_list ap)
{
	char	c;
	int		char_displayed;

	char_displayed = 0;
	if (expr->specifier == 'C' || !ft_strcmp(expr->modifiers, "l"))
		return (upperc_arg(expr, ap));
	c = (char)va_arg(ap, int);
	expr->width -= 1;
	char_displayed += pre_width(expr);
	ft_putchar(c);
	char_displayed += post_width(expr);
	return (char_displayed + 1);
}
