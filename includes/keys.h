/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:19:28 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 11:48:34 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define MAX_KEY_LEN 4

# define KEY_CODE_UP "\x1b\x5b\x41\0"
# define KEY_CODE_DO "\x1b\x5b\x42\0"
# define KEY_CODE_RI "\x1b\x5b\x43\0"
# define KEY_CODE_LE "\x1b\x5b\x44\0"

# define KEY_CODE_ENTER "\xa\0\0\0"
# define KEY_CODE_BKSPACE "\x7f\0\0\0"
# define KEY_CODE_DEL "\x1b\x5b\x33\x7e"
# define KEY_CODE_TAB "\x9\0\0\0"

# define KEY_CODE_HOME "\x1b\x5b\x48\0"
# define KEY_CODE_END "\x1b\x5b\x46\0"

struct	s_keymatch
{
	char	*key_code;
	int	 	key_ret;
};

int		get_key(void);

/* KEY_CODE_SUP 1b 1b 5b 41 */
/* KEY_CODE_SDOWN 1b 1b 5b 42 */

/* KEY_CODE_CTRLD 4 */
/* KEY_CODE_CTRLL c */

#endif
