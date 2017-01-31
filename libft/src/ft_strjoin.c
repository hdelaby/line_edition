/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:28:01 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/06 14:29:07 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;

	if (!s1 || !s2)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ret);
}
