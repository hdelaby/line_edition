/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:59:02 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/07 14:20:27 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_precision(t_expr *expr)
{
	char	*ret;
	int		char_displayed;

	char_displayed = 0;
	if (expr->precision > 0)
	{
		ret = (char *)malloc(sizeof(char) * expr->precision + 1);
		if (!ret)
			exit(-1);
		ft_bzero(ret, expr->precision + 1);
		ft_memset(ret, '0', expr->precision);
		ft_putstr(ret);
		free(ret);
		char_displayed += expr->precision;
		if (expr->specifier == 'o')
			expr->precision = 0;
	}
	return (char_displayed);
}

int		print_sign(t_expr *expr, char *str)
{
	if (ft_strchr("dDi", expr->specifier))
	{
		if (expr->is_neg)
		{
			ft_putchar('-');
			expr->is_neg = 0;
		}
		else if (ft_strchr(expr->flags, '+'))
			ft_putchar('+');
		else if (ft_strchr(expr->flags, ' '))
			ft_putchar(' ');
		else
			return (0);
		return (1);
	}
	else if (ft_strchr("xX", expr->specifier) && ft_strchr(expr->flags, '#')
			&& *str != '0')
	{
		if (expr->specifier == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		return (2);
	}
	return (0);
}

void	format_prep(t_expr *expr, char **str)
{
	if (**str == '-')
	{
		expr->is_neg = 1;
		expr->width -= 1;
		*str += 1;
	}
	if (**str == '0' && expr->precision == 0 &&
			ft_strchr("xXdi", expr->specifier))
		expr->width += 1;
	if (expr->precision >= 0 && (size_t)expr->precision > ft_strlen(*str))
		expr->precision -= ft_strlen(*str);
	else if (expr->precision >= 0)
		expr->precision = 0;
	if (ft_strchr(expr->flags, '+') || ft_strchr(expr->flags, ' '))
	{
		expr->width -= 1;
		if (expr->is_neg)
			expr->width += 1;
	}
	if (expr->specifier == 'o' && ft_strchr(expr->flags, '#'))
		expr->precision = expr->precision > 0 ? expr->precision : 1;
	else if (ft_strchr(expr->flags, '#') && **str != '0')
		expr->width -= 2;
}

int		format_menu(t_expr *expr, char *str)
{
	int ret;

	ret = 0;
	format_prep(expr, &str);
	if (*str != '0' || ft_strchr("xXdib", expr->specifier))
		expr->width -= expr->precision >= 0 ?
			expr->precision + ft_strlen(str) : ft_strlen(str);
	if (expr->precision != 0 && expr->specifier == 'u' && *str == '0')
		expr->width -= 1;
	ret += pre_width(expr);
	if (expr->is_neg || (ft_strchr("xX", expr->specifier) &&
				!ft_strchr(expr->flags, '0')) || !ft_strchr(expr->flags, '0'))
		ret += print_sign(expr, str);
	ret += print_precision(expr);
	if (expr->precision == 0 && *str == '0')
		ft_putstr("");
	else
	{
		ft_putstr(str);
		ret += ft_strlen(str);
	}
	ret += post_width(expr);
	return (ret);
}
