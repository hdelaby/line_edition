/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:19 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/11 16:36:10 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data, int (*cmp)())
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (cmp(lst->content, data))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
