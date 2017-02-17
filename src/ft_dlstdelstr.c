/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:07:38 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/17 14:16:33 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelstr(t_dlist **lst)
{
	t_dlist *tmp;

	*lst = ft_dlstgethead(*lst);
	while (*lst)
	{
		tmp = *lst;
		free((*lst)->content);
		*lst = (*lst)->next;
		free(tmp);
	}
}
