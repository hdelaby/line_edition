/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:05:39 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 15:28:14 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Handles pointer adresses (%p). For this argument, precision is not applied.
** As printf behaviour is undefined, here I have chosen not to do it.
** Returns nb of characters displayed.
*/

int		p_arg(t_expr *expr, va_list ap)
{
	uintmax_t	address;
	char		*ret;
	int			char_displayed;

	address = 0;
	char_displayed = 0;
	if (expr->specifier == 'p')
		address = va_arg(ap, uintmax_t);
	if ((ret = ft_uitoa_base(address, 16, 0)) == NULL)
		return (-1);
	if ((ret = ft_strfreejoin(ft_strdup("0x"), ret)) == NULL)
		return (-1);
	expr->width -= ft_strlen(ret);
	char_displayed += pre_width(expr);
	ft_putstr(ret);
	char_displayed += ft_strlen(ret);
	char_displayed += post_width(expr);
	free(ret);
	return (char_displayed);
}
