/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbubsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:55:35 by hdelaby           #+#    #+#             */
/*   Updated: 2016/12/16 14:56:07 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help_b_sort(t_list **nd, t_list **nx, t_list **pv, int *done)
{
	(*nd)->next = (*nx)->next;
	(*nx)->next = *nd;
	*pv = *nx;
	*done = 0;
}

void		ft_lstbubsort(t_list **head, int (*cmp)())
{
	int		done;
	t_list	**pv;
	t_list	*nd;
	t_list	*nx;

	done = 0;
	if (!(*head) || !(*head)->next)
		return ;
	while (!done)
	{
		pv = head;
		nd = *head;
		nx = (*head)->next;
		done = 1;
		while (nx)
		{
			if (cmp(nd->content, nx->content) > 0)
				help_b_sort(&nd, &nx, pv, &done);
			pv = &nd->next;
			nd = nx;
			nx = nx->next;
		}
	}
}
