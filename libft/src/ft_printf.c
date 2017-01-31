/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:32:09 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/04 16:32:12 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_conversion(t_expr *expr, va_list ap)
{
	int					i;
	static const t_conv	conv[] = {
		{ "diouxXb", &int_arg },
		{ "DOU", &dou_arg },
		{ "Cc", &c_arg },
		{ "s", &s_arg },
		{ "S", &ws_arg },
		{ "p", &p_arg },
		{ "%", &pct_arg },
		{ "k", &date_arg }
	};

	i = 0;
	while (i < 8)
	{
		if (ft_strchr(conv[i].specifiers, expr->specifier))
			return (conv[i].p(expr, ap));
		i++;
	}
	return (invalid_arg(expr, ap));
}

int		begin_conversion(const char *restrict format,
		va_list ap, int test, int ret)
{
	t_expr *expr;

	while (*format)
	{
		if (*format == '%')
		{
			if ((expr = get_expression((char *)format, ap)) == NULL)
				return (-1);
			if (expr->specifier != 0)
			{
				if ((test = apply_conversion(expr, ap)) == -1)
					return (-1);
				ret += test;
				format = expr->end_expr;
			}
			free(expr);
		}
		else
		{
			ft_putchar(*format);
			ret++;
		}
		format++;
	}
	return (ret);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	ret = begin_conversion(format, ap, 0, 0);
	va_end(ap);
	return (ret);
}
