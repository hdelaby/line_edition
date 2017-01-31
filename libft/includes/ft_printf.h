/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:45:32 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/04 16:01:26 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <stdint.h>

typedef struct	s_expr
{
	char	specifier;
	int		width;
	int		precision;
	char	flags[6];
	char	modifiers[3];
	int		is_neg;
	char	*end_expr;
}				t_expr;

typedef struct	s_conv
{
	char	*specifiers;
	int		(*p)(t_expr *expr, va_list ap);
}				t_conv;

int				ft_printf(const char *restrict format, ...);

t_expr			*get_expression(char *format, va_list ap);

int				s_arg(t_expr *expr, va_list ap);
int				int_arg(t_expr *expr, va_list ap);
int				c_arg(t_expr *expr, va_list ap);
int				pct_arg(t_expr *expr, va_list ap);
int				p_arg(t_expr *expr, va_list ap);
int				dou_arg(t_expr *expr, va_list ap);
int				ws_arg(t_expr *expr, va_list ap);
int				invalid_arg(t_expr *expr, va_list ap);
int				date_arg(t_expr *expr, va_list ap);
char			*format_argument(t_expr *expr, char *str);
int				format_menu(t_expr *expr, char *str);
int				pre_width(t_expr *expr);
int				post_width(t_expr *expr);
int				print_sign(t_expr *expr, char *str);

#endif
