/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:47:05 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 11:51:34 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	match_key(char *key_str)
{
	int				i;
	static struct s_keymatch key_couple[10] = {
		{KEY_CODE_UP, KEY_UP},
		{KEY_CODE_DO, KEY_DOWN},
		{KEY_CODE_RI, KEY_RIGHT},
		{KEY_CODE_LE, KEY_LEFT},
		{KEY_CODE_ENTER, KEY_ENTER},
		{KEY_CODE_BKSPACE, KEY_DL},
		{KEY_CODE_DEL, KEY_DC},
		{KEY_CODE_TAB, KEY_STAB},
		{KEY_CODE_HOME, KEY_HOME},
		{KEY_CODE_END, KEY_END}
	};

	i = 0;
	while (i < 10)
		if (!ft_memcmp(key_couple[i++].key_code, key_str, MAX_KEY_LEN))
			return (key_couple[i - 1].key_ret);
	return (key_str[0]);
}

int			get_key(void)
{
	char	*key_str;
	int		key_pressed;

	key_str = ft_strnew(MAX_KEY_LEN);
	if (!key_str)
		return (-1);
	read(0, key_str, MAX_KEY_LEN);
	key_pressed = match_key(key_str);
	free(key_str);
	return (key_pressed);
}
