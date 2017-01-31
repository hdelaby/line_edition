/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:48:20 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/24 12:44:55 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	char	**ret;
	char	**ptr;

	ret = (char **)malloc(sizeof(char *) *
			(ft_tablen(tab1) + ft_tablen(tab2) + 1));
	if (!ret)
		return (NULL);
	ptr = ret;
	while (*tab1)
		*(ret++) = ft_strdup(*(tab1++));
	while (*tab2)
		*(ret++) = ft_strdup(*(tab2++));
	*ret = NULL;
	return (ptr);
}
