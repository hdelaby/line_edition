/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_nstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:48:33 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/07 10:48:35 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dlst_to_nstr(t_dlist *lst, size_t n)
{
	char	*ret;
	char	*ptr;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	ptr = ret;
	while (n)
	{
		*(ret++) = *((char *)lst->content);
		lst = lst->next;
		n--;
	}
	*ret = '\0';
	return (ptr);
}
