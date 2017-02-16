/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:47:05 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 15:26:58 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <curses.h>
#include "libft.h"
#include "keys.h"

/*
** Reads MAX_KEY_LEN at a time. Matches the string with a list of known
** key sequences. Then returns the value of the key_pressed contained in
** curses.h
*/

static int	match_key(char *key_str, int i)
{
	static struct s_keymatch	key_couple[11] = {
		{KEY_CODE_UP, KEY_UP},
		{KEY_CODE_DO, KEY_DOWN},
		{KEY_CODE_RI, KEY_RIGHT},
		{KEY_CODE_LE, KEY_LEFT},
		{KEY_CODE_DEL, KEY_DC},
		{KEY_CODE_HOME, KEY_HOME},
		{KEY_CODE_END, KEY_END},
		{KEY_CODE_SRI, KEY_SRIGHT},
		{KEY_CODE_SLE, KEY_SLEFT},
		{KEY_CODE_SUP, KEY_SPREVIOUS},
		{KEY_CODE_SDO, KEY_SNEXT}
	};

	while (i < 11)
		if (!ft_memcmp(key_couple[i++].key_code, key_str, MAX_KEY_LEN))
			return (key_couple[i - 1].key_ret);
	return (key_str[0]);
}

/*
** Small particularity of this function lies in the fact that we first read 1
** character. If this value equals '\x1b' we read 3 other chars.
** This behaviour makes copied text works.
*/

int			get_key(void)
{
	char	*key_str;
	int		key_pressed;

	key_str = ft_strnew(MAX_KEY_LEN);
	if (!key_str)
		return (-1);
	read(0, key_str, 1);
	if (*key_str == '\x1b')
		read(0, key_str + 1, MAX_KEY_LEN - 1);
	key_pressed = match_key(key_str, 0);
	free(key_str);
	return (key_pressed);
}
