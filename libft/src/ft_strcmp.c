/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:29:07 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/05 10:31:52 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((int)(unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((int)(unsigned char)*s1 - (unsigned char)*s2);
}
