/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:56:25 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/01 08:57:02 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddnext(t_dlist **head, t_dlist *new)
{
	t_dlist	*ptr;

	ptr = NULL;
	if (!new || !head)
		return ;
	if (*head)
	{
		ptr = (*head)->next;
		(*head)->next = new;
	}
	new->prev = *head;
	new->next = ptr;
	if (ptr)
	{
		ptr->prev = new;
		*head = ptr;
	}
	else
		*head = new;
}
