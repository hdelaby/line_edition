/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_fname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 15:40:17 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/16 15:40:19 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract_fname(char *path)
{
	char *tmp;

	if (!(tmp = ft_strrchr(path, '/')))
		return (path);
	else
		return (tmp + 1);
}
