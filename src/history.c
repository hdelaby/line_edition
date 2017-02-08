/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:12:46 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/08 09:13:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "auto_completion.h"
#include "ft_printf.h"

/*
** Feeds the line with the previous entry in the history.
** Returns 0 on success, 1 otherwise.
*/

int		prev_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line)
{
	char	*entry;

	if (!(*hist) || !(*hist)->prev)
		return (1);
	line->hist_depth--;
	cursor_to_end(line, lst);
	while (!delete_char(line, KEY_BACKSPACE, lst))
		continue;
	*hist = (*hist)->prev;
	entry = (*hist)->content;
	while (*entry)
		insert_char(line, *(entry++), lst);
	if (!line->hist_depth)
		ft_dlstremovenode(hist);
	return (0);
}

/*
** Feeds the line with the next entry in the history.
** Returns 0 on success, 1 otherwise.
*/

int		old_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line)
{
	char	*entry;

	if (!(*hist) || !(*hist)->next)
		return (1);
	cursor_to_home(line, lst);
	if (!line->hist_depth)
	{
		entry = ft_dlst_to_nstr(*lst, ft_dlstsize(*lst) - 1);
		ft_dlstadd(hist, ft_dlstnew(entry, ft_strlen(entry) + 1));
		free(entry);
	}
	cursor_to_end(line, lst);
	while (!delete_char(line, KEY_BACKSPACE, lst))
		continue ;
	*hist = (*hist)->next;
	entry = (*hist)->content;
	while (*entry)
		insert_char(line, *(entry++), lst);
	line->hist_depth++;
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
