/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremovenode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:33:06 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/21 16:36:58 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremovenode(t_dlist **head)
{
	t_dlist	*ptr;

	if (*head)
	{
		if ((*head)->prev)
			(*head)->prev->next = (*head)->next;
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		ptr = *head;
		*head = (*head)->next ? (*head)->next : ft_dlstgethead(*head);
		free(ptr->content);
		free(ptr);
	}
}
