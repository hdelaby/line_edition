/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:16:01 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/16 14:22:35 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop(t_list **lst)
{
	t_list	*next;
	void	*ret;

	ret = NULL;
	next = NULL;
	if (!(*lst))
		return (NULL);
	next = (*lst)->next;
	ret = (*lst)->content;
	free(*lst);
	*lst = next;
	return (ret);
}
