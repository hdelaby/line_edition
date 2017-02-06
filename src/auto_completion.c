/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:55:23 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/03 11:54:55 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "auto_completion.h"

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
	return (flag == 1 ? dir_path + len : NULL);
}

/* 
** Change the name of the function.
*/

void	ft_str_to_dlst(char *path, char *str, t_dlist **lst, t_line *line)
{
	path = ft_strjoin(path, str);
	if (!path)
		return ;
	while (*str)
		insert_char(line, *(str++), lst);
	if (ft_isdir(path))
		insert_char(line, '/', lst);
	else
		insert_char(line, ' ', lst);
	free(path);
}

int		find_occurences(char *path, t_dlist **lst, t_line *line)
{
	char	*fname;
	char	*ret;

	fname = ft_strrchr(path, '/');
	if (*path == '/')
		ret = check_dir("/", path + 1);
	else if (fname)
	{
		*(fname++) = '\0';
		ret = check_dir(path, fname);
		*(fname - 1) = '/';
	}
	else
		ret = check_dir(".", path);
	if (ret)
		ft_str_to_dlst(path, ret, lst, line);
	return (0);
}

int		auto_complete(t_dlist **lst, t_line *line)
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
	find_occurences(str, lst, line);
	free(str);
	return (0);
}
