/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:49:22 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/03 11:45:10 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

int		ft_isdir(char *path)
{
	struct stat	buf;

	stat(path, &buf);
	if (ft_get_ftype(buf.st_mode) == 'd')
		return (1);
	return (0);
}
