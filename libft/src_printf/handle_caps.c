/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_caps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:20:38 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 15:43:27 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** For capped conversion specifiers, we simply to_lower the specifier stored
** and set the modifier to 'l' as explained in printf's man. This is only
** applied for decimal arguments though.
*/

int		dou_arg(t_expr *expr, va_list ap)
{
	expr->specifier = ft_tolower(expr->specifier);
	ft_bzero(expr->modifiers, 2);
	*(expr->modifiers) = 'l';
	return (int_arg(expr, ap));
}
