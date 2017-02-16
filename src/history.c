/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:12:46 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 18:07:13 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void	prev_hist_entry(t_line *line)
{
	char	*entry;

	if (!line->hist_depth)
		return ;
	line->hist_depth--;
	*hist = (*hist)->prev;
	entry = (*hist)->content;
	if (!line->hist_depth)
		ft_dlstremovenode(hist);
	return (0);
}


/* int			old_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line) */
/* { */
/* 	char	*entry; */

/* 	if (!(*hist) || !(*hist)->next) // PROBLEM WHEN ONLY 1 ENTRY */
/* 		return (1); */
/* 	cursor_to_home(line, lst); */
/* 	if (!line->hist_depth) */
/* 	{ */
/* 		entry = ft_dlst_to_nstr(*lst, ft_dlstsize(*lst) - 1); */
/* 		ft_dlstadd(hist, ft_dlstnew(entry, ft_strlen(entry) + 1)); */
/* 		free(entry); */
/* 	} */
/* 	del_line(lst, line); */
/* 	*hist = (*hist)->next; */
/* 	entry = (*hist)->content; */
/* 	while (*entry) */
/* 		insert_char(line, *(entry++), lst); */
/* 	line->hist_depth++; */
/* 	return (0); */
/* } */

/*
** Opens the file pointed by path and appends the new history entry.
** Returns 0 on success, 1 otherwise.
*/

int			append_history(char *path, char *entry)
{
	int		fd;

	fd = open(path, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		ft_putendl_fd("Could not open history", 2);
		return (1);
	}
	ft_putendl_fd(entry, fd);
	close(fd);
	return (0);
}

/*
** Takes the path to the history file as an argument and processes
** the data into a doubly-linked list for convenience of use.
** Returns the list on success, NULL otherwise.
*/

t_dlist	*retrieve_history(char *path)
{
	int		fd;
	t_dlist	*hist;
	char	*line;
	size_t	len;

	hist = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		len = ft_strlen(line);
		if (len < MAX_CMD_LEN)
			ft_dlstadd(&hist, ft_dlstnew(line, len + 1));
		free(line);
	}
	close(fd);
	return (hist);
}
