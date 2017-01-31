/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:31:29 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/22 09:43:57 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

t_list	*ft_lstremoveif(t_list *lst, void *test)
{
	t_list *tmp;

	if (lst == NULL)
		return (NULL);
	if (lst->content == test)
	{
		tmp = lst->next;
		free(lst);
		return (tmp);
	}
	lst->next = ft_lstremoveif(lst->next, test);
	return (lst);
}
