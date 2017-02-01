/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:48:00 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 14:55:23 by hdelaby          ###   ########.fr       */
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
** SPECIAL CASE FOR KEY_DC!! READ ONCE MORE
*/

int		ft_getch(void)
{
	int		key;

	key = unique_char();
	if (key == 127)
		return (KEY_BACKSPACE);
	if (key == 27)
	{
		key = unique_char();
		key = unique_char();
		if (key == 67)
			return (KEY_RIGHT);
		if (key == 68)
			return (KEY_LEFT);
		if (key == 51)
			return (KEY_DC);
	}
	return (key);
}
