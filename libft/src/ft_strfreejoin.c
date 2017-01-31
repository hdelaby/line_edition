/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:38:45 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/03 16:55:13 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfreejoin(char const *s1, char const *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free((void *)s1);
	s1 = NULL;
	free((void *)s2);
	s2 = NULL;
	return (tmp);
}
