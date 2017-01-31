/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 07:26:54 by hdelaby           #+#    #+#             */
/*   Updated: 2016/11/22 12:06:33 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Goes through the list until it finds the node that corresponds to the fd.
** content_size is used as an indicator for the fd.
** Returns the corresponding node or a fresh node filled with 0.
*/

static t_list	*get_list(t_list **lst, int fd)
{
	t_list *tmp;

	tmp = *lst;
	if (lst)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstaddback(lst, tmp);
	return (tmp);
}

/*
** Feeds lst->content until it finds a \n. Then malloc the line and stores
** the remaining part of the buffer in lst->content for next call to GNL.
** Returns 0 if reached the EOF, 1 if line succesfully read.
*/

static int		split_endl(char **line, t_list *lst, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	int		buf_ret;
	int		ret;

	while (!ft_strchr(lst->content, '\n') && (buf_ret =
			read(fd, buffer, BUFF_SIZE)))
	{
		tmp = lst->content;
		lst->content = ft_strnjoin(lst->content, buffer, buf_ret);
		free(tmp);
	}
	ret = ft_strlenc(lst->content, '\n');
	if (!ret && !buf_ret && ((char *)lst->content)[0] != '\n')
		return (0);
	*line = ft_strndup(lst->content, ret);
	if (*((char *)lst->content + ret) == '\n')
		ret++;
	tmp = lst->content;
	lst->content = ft_strdup(lst->content + ret);
	free(tmp);
	return (1);
}

/*
** Gets the correct node corresponding to fd, then creates the line. If
** EOF is reached, the node and its content are freed.
** Returns -1 on error, 0 if EOF is reached, 1 on success.
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*start;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	if (!line || (read(fd, buffer, 0) < 0) || fd < 0)
		return (-1);
	start = lst;
	lst = get_list(&start, fd);
	if ((ret = split_endl(line, lst, fd)))
	{
		lst = start;
		return (1);
	}
	free(lst->content);
	lst->content = NULL;
	lst = ft_lstremoveif(start, NULL);
	return (0);
}
