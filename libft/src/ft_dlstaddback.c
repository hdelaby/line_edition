/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:33:52 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/21 12:34:10 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddback(t_dlist **head, t_dlist *new)
{
	t_dlist	*ptr;

	if (!new || !head)
		return ;
	while (*head && (*head)->next)
		head = &(*head)->next;
	ptr = *head;
	if (*head)
		(*head)->next = new;
	else
		*head = new;
	new->prev = ptr;
}
