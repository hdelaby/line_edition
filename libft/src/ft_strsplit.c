/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:35:01 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/11 15:35:51 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	nb_words(char *str, char c)
{
	int i;
	int compteur;
	int flag;

	i = 0;
	compteur = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			compteur++;
			if (flag == 1)
				compteur--;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 1)
		compteur--;
	return (compteur + 1);
}

char		**ft_strsplit(char *str, char c)
{
	char			**b;
	unsigned int	j;

	b = NULL;
	j = 0;
	if (!str)
		return (NULL);
	if ((b = (char **)(malloc(sizeof(char *) * (nb_words(str, c) + 1))))
			== NULL)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			b[j] = ft_strndup(str, ft_strlenc(str, c));
			str += (ft_strlenc(str, c) - 1);
			j++;
		}
		str++;
	}
	b[j] = 0;
	return (b);
}
