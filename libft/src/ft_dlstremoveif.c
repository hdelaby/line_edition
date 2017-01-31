/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremoveif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:31:01 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/21 14:52:26 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremoveif(t_dlist **head, int cmp())
{
	t_dlist	*ptr;

	while (*head)
	{
		if (cmp((*head)->content, (*head)->content_size))
		{
			if ((*head)->prev)
				(*head)->prev->next = (*head)->next;
			if ((*head)->next)
				(*head)->next->prev = (*head)->prev;
			ptr = *head;
			*head = (*head)->prev ? (*head)->prev : (*head)->next;
			free(ptr->content);
			free(ptr);
		}
		head = &(*head)->next;
	}
}
