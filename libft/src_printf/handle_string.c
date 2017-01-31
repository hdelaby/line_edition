/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:02:31 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 15:14:08 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Reads from str until offset bytes are read or wstr is over.
** Returns a pointer to str with the offset calculated beforehand.
*/

char	*wstr_offset(wchar_t *wstr, char *str, int offset)
{
	while (offset > 0 && *wstr)
	{
		if ((int)ft_strlen(str) > offset)
			return (str);
		offset -= ft_strlen(str);
		str += 4;
		wstr += 1;
	}
	return (str);
}

void	init_wstr(int *i, char *str, wchar_t *wstr, t_expr *expr)
{
	while (wstr[*i])
	{
		ft_utf8_encode(wstr[*i], (unsigned char *)str + (*i * 4));
		(*i)++;
	}
	if (expr->precision >= 0)
		ft_bzero(wstr_offset(wstr, str, expr->precision), 4 *
				ft_wcslen(wstr) - expr->precision);
	*i = ft_wcs_nbchar(wstr, str);
}

/*
** Handles wchar * arguments (%S or %ls). Special case for NULL argument
** where an hard-coded (null) is set as the argument to print.
** Returns nb of characters displayed or -1 on error.
*/

int		ws_arg(t_expr *expr, va_list ap)
{
	wchar_t	*wstr;
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	wstr = (wchar_t *)va_arg(ap, wchar_t *);
	if (wstr == NULL)
		str = !expr->precision ? ft_strdup("") : ft_strdup("(null)");
	else
	{
		if ((str = ft_strnew(4 * ft_wcslen(wstr))) == NULL)
			return (-1);
		init_wstr(&i, str, wstr, expr);
	}
	expr->width -= wstr ? i : ft_strlen(str);
	i += pre_width(expr);
	wstr ? ft_putwstr(wstr, str) : ft_putstr(str);
	i += wstr ? 0 : ft_strlen(str);
	i += post_width(expr);
	free(str);
	return (i);
}

/*
** Handles char * arguments (%s). Redirects to ws_arg if l modifier is
** specified. Special case for NULL just as ws_arg.
** Returns nb of characters displayed or -1 on error.
*/

int		s_arg(t_expr *expr, va_list ap)
{
	char	*str;
	int		char_displayed;

	char_displayed = 0;
	if (!ft_strcmp(expr->modifiers, "l"))
		return (ws_arg(expr, ap));
	str = va_arg(ap, char *);
	if (!str)
		str = expr->precision == 0 ? ft_strdup("") : ft_strdup("(null)");
	else if (expr->precision >= 0 && (size_t)expr->precision < ft_strlen(str))
		str = ft_strndup(str, expr->precision);
	else
		str = ft_strdup(str);
	if (!str)
		return (-1);
	expr->width -= ft_strlen(str);
	char_displayed += pre_width(expr);
	ft_putstr(str);
	char_displayed += ft_strlen(str);
	free(str);
	char_displayed += post_width(expr);
	return (char_displayed);
}
