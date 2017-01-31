/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:59:23 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 16:27:28 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pre_width(t_expr *expr)
{
	char	*ret;
	int		char_displayed;

	char_displayed = 0;
	if (expr->width > 0 && !ft_strchr(expr->flags, '-'))
	{
		if ((ret = (char *)malloc(expr->width + 1)) == NULL)
			return (-1);
		ft_bzero(ret, expr->width + 1);
		if (ft_strchr(expr->flags, '0') && !(expr->precision >= 0 &&
					ft_strchr("diouixX", expr->specifier)))
		{
			char_displayed += print_sign(expr, "");
			ft_memset(ret, '0', expr->width);
		}
		else
			ft_memset(ret, ' ', expr->width);
		char_displayed += expr->width;
		expr->width = 0;
		ft_putstr(ret);
		free(ret);
	}
	else if (!ft_strchr(expr->flags, '-') && ft_strchr(expr->flags, '0'))
		char_displayed += print_sign(expr, "");
	return (char_displayed);
}

int		post_width(t_expr *expr)
{
	int		char_displayed;
	char	*ret;

	char_displayed = 0;
	if (expr->width > 0)
	{
		ret = (char *)malloc(expr->width + 1);
		if (!ret)
			return (-1);
		ft_bzero(ret, expr->width + 1);
		ft_memset(ret, ' ', expr->width);
		char_displayed = expr->width;
		ft_putstr(ret);
		free(ret);
	}
	return (char_displayed);
}
