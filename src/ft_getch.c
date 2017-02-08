/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:48:00 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 15:32:55 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <curses.h>
#include "ft_printf.h"

static int	unique_char()
{
	char	buf[1];

	read(0, buf, 1);
	return (buf[0]);
}

/*
** This function reads 1 byte at a time when the terms is in canonical mode
** Man getch can be really interesting for that.
*/

int		ft_getch(void)
{
	int		key;

	key = unique_char();
	if (key == 9)
		return (KEY_STAB);
	if (key == 127)
		return (KEY_BACKSPACE);
	if (key == 27)
	{
		key = unique_char();
		key = unique_char();
		if (key == 65)
			return (KEY_UP);
		if (key == 66)
			return (KEY_DOWN);
		if (key == 67)
			return (KEY_RIGHT);
		if (key == 68)
			return (KEY_LEFT);
		if (key == 51)
		{
			unique_char();
			return (KEY_DC);
		}
		if (key == 72)
			return (KEY_HOME);
		if (key == 70)
			return (KEY_END);
		if (key == 91)
		{
			key = unique_char();
			if (key == 67)
				return (KEY_SRIGHT);
			if (key == 68)
				return (KEY_SLEFT);
			if (key == 65)
				return (KEY_SPREVIOUS);
			if (key == 66)
				return (KEY_SNEXT);
		}
	}
	return (key);
}
