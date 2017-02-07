/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:38:40 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/07 15:45:34 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dlst_to_str(t_dlist *lst)
{
	char	*ret;
	char	*ptr;

	ret = ft_strnew(ft_dlstsize(lst));
	if (!ret)
		return (NULL);
	ptr = ret;
	while (lst)
	{
		*(ret++) = *((char *)lst->content);
		lst = lst->next;
	}
	*ret = '\0';
	return (ptr);
}
