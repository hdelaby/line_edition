/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:12:46 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/07 10:06:38 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

int		prev_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line)
{
	char	*entry;

	if ((*hist)->prev == NULL)
		return (1);
	while (!arrow_right(line, lst))
		continue ;
	while (!delete_char(line, KEY_BACKSPACE, lst))
		continue ;
	*hist = (*hist)->prev;
	entry = (*hist)->content;
	while (*entry)
		insert_char(line, *(entry++), lst);
	return (0);
}

int		old_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line)
{
	char	*entry;

	if ((*hist)->next == NULL)
		return (1);
	while (!arrow_right(line, lst))
		continue ;
	while (!delete_char(line, KEY_BACKSPACE, lst))
		continue ;
	*hist = (*hist)->next;
	entry = (*hist)->content;
	while (*entry)
		insert_char(line, *(entry++), lst);
	return (0);
}

/*
** Opens the file pointed by path and appends the new history entry.
** Returns 0 on success, 1 otherwise.
*/

int		append_history(char *path, char *entry)
{
	int		fd;

	fd = open(path, O_WRONLY | O_APPEND | O_CREAT);
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

	hist = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("History could not be retrieved", 2);
		return (NULL);
	}
	while (get_next_line(fd, &line))
	{
		ft_dlstadd(&hist, ft_dlstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	close(fd);
	return (hist);
}
