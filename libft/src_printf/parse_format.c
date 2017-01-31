/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 08:26:11 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/04 16:14:10 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** BONUS: If wildchar read, interprets the next argument as width or precision.
** Returns the value read or -1 if negative precision.
*/

size_t	get_wildchar(char *format, t_expr *expr, va_list ap, int *i)
{
	int		input;
	int		j;

	j = 0;
	input = 0;
	if (format[*i] == '*')
	{
		(*i)++;
		input = (int)va_arg(ap, int);
		if (input < 0 && expr->width == -1)
		{
			while (expr->flags[j])
				j++;
			*expr->flags = '-';
		}
		else if (input < 0)
			return (-1);
		input = input >= 0 ? input : -(input);
		return (input);
	}
	else
		return (ft_atoi(format + *i));
}

/*
** Initiliases the expression structure with default values. -1 for precision!
** Returns a fresh t_expr ready to use.
*/

t_expr	*init_expr(void)
{
	t_expr	*expr;

	if ((expr = (t_expr *)malloc(sizeof(t_expr))) == NULL)
		return (NULL);
	expr->specifier = '\0';
	expr->width = -1;
	expr->precision = -1;
	bzero(expr->flags, 6);
	bzero(expr->modifiers, 3);
	expr->is_neg = 0;
	return (expr);
}

/*
** Checks for length modifiers within the expression. It only accepts 1
** modifier else sets i to 0 which leads get_expression to return NULL.
** This behaviour was designed to avoid mistakes.
*/

void	get_modifiers(char *format, t_expr *expr, int *i)
{
	static char modifiers[] = "hljz";
	int			j;

	j = 0;
	while (ft_strchr(modifiers, format[*i]))
	{
		if ((!j || (j && ft_strchr(modifiers, format[*i]) &&
				ft_strchr(expr->modifiers, format[*i]))) && j < 2)
			expr->modifiers[j++] = format[(*i)++];
		else
		{
			*i = 0;
			return ;
		}
	}
}

/*
** Checks for flags. Here we accept as many similar flags as possible
** even if separated by others. Same behaviour than printf.
*/

void	get_flags(char *format, t_expr *expr, int *i)
{
	static char flags[] = "+-0# ";
	int			j;

	j = 0;
	while (ft_strchr(flags, format[*i]))
	{
		if ((j && ft_strchr(expr->flags, format[*i]) &&
				format[*i] != expr->flags[j - 1]) || j == 5)
			*i += 0;
		else if ((j && format[*i] != expr->flags[j - 1]) || !j)
			expr->flags[j++] = format[*i];
		(*i)++;
	}
}

/*
** Parses the % expression and stores all the elements in a structure.
** Returns t_expr with modifier (can be incorrect). Only returns NULL
** if more than one modifier has been sent.
*/

t_expr	*get_expression(char *format, va_list ap)
{
	int			i;
	t_expr		*expr;

	expr = init_expr();
	i = 1;
	if (format[i])
	{
		get_flags(format, expr, &i);
		expr->width = get_wildchar(format, expr, ap, &i);
		while (ft_isdigit(format[i]))
			i++;
		if (format[i] == '.')
		{
			i++;
			expr->precision = get_wildchar(format, expr, ap, &i);
			while (ft_isdigit(format[i]))
				i++;
		}
		get_modifiers(format, expr, &i);
		if (!i)
			return (NULL);
	}
	expr->specifier = format[i];
	expr->end_expr = format + i;
	return (expr);
}
