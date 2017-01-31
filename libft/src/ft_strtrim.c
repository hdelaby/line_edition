/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:29:30 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/07 17:15:38 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strtrim(char const *s)
{
	char	*end;

	if (!s)
		return (NULL);
	end = (char *)s + ft_strlen(s) - 1;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s += 1;
	if (*s == '\0')
		return (ft_strdup(""));
	while (*end == ' ' || *end == '\t' || *end == '\n')
		end--;
	return (ft_strndup(s, end - s + 1));
}
