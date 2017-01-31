/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:42 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/11 15:57:09 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	char	**tab;
	t_list	*new_lst;

	tab = ft_lst_to_tab(lst);
	new_lst = ft_tab_to_lst(tab);
	ft_tabdel(tab);
	return (new_lst);
}
