/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:35:07 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/22 09:42:43 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(*ret) * ft_strlen(s1) + n + 1)) == NULL)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strncat(ret, s2, n);
	ret[ft_strlen(s1) + n] = '\0';
	return (ret);
}
