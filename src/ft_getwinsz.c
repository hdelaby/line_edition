/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwinsz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 09:44:39 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 13:45:29 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "line_editing.h"
#include <sys/ioctl.h>

/*
** Ioctl request to get window size. Result is stored in structure s_winsz.
** Return 0 if the request has succeeded, 1 otherwise.
*/

int		ft_getwinsz(t_winsz *winsz)
{
	struct winsize	w;

	if (ioctl(0, TIOCGWINSZ, &w))
		return (1);
	winsz->col = w.ws_col;
	winsz->row = w.ws_row;
	return (0);
}
