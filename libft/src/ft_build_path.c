/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:58:39 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/16 15:00:17 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_build_path(char *path, char *fname)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	path = tmp;
	tmp = ft_strjoin(tmp, fname);
	free(path);
	return (tmp);
}
