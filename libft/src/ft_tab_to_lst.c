/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:44:18 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/11 15:58:25 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_tab_to_lst(char **tab)
{
	t_list	*lst;

	lst = NULL;
	if (!tab || !(*tab))
		return (NULL);
	while (*tab)
	{
		ft_lstaddback(&lst, ft_lstnew(*tab, ft_strlen(*tab) + 1));
		tab++;
	}
	return (lst);
}
