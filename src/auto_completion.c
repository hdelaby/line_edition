/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:55:23 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/02 14:01:44 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"

char	*ft_dlst_to_nstr(t_dlist *lst, size_t n)
{
	char	*ret;
	char	*ptr;

	ret = ft_strnew(n);
	if (!ret)
		return (NULL);
	ptr = ret;
	while (n)
	{
		*(ret++) = *((char *)lst->content);
		lst = lst->next;
		n--;
	}
	*ret = '\0';
	return (ptr);
}

char	*check_dir(char *dir_path, char *fname)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				flag;
	size_t			len;

	flag = 0;
	len = ft_strlen(fname);
	if (!(dirp = opendir(dir_path)))
		return (NULL);
	while ((dp = readdir(dirp)))
	{
		if (!ft_strncmp(dp->d_name, fname, len))
		{
			dir_path = dp->d_name;
			flag++;
		}
	}
	(void)closedir(dirp);
	return (flag == 1 ? dir_path : NULL);
}

int		find_occurences(char *path, t_dlst *lst)
{
	char	*fname;
	char	*ret;

	fname = ft_strrchr(path, '/');
	if (fname)
	{
		*(fname++) = '\0';
		ret = check_dir(path, fname);
		if (ret)
			ret += ft_strlen(fname);
	}
	return (0);
}

int		auto_complete(t_dlist **lst)
{
	char	*str;
	size_t	i;
	t_dlist	*ptr;

	i = 0;
	ptr = *lst;
	while (ptr && ptr->prev && ft_strcmp(ptr->prev->content, " "))
	{
		ptr = ptr->prev;
		i++;
	}
	str = ft_dlst_to_nstr(ptr, i);
	if (!str)
		return (1);
	find_occurences(str, lst);
	return (0);
}