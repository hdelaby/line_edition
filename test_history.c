#include "libft.h"
#include <fcntl.h>

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
	while (hist)
	{
		ft_putendl(hist->content);
		hist = hist->next;
	}
	return (NULL);
}

int		main(void)
{
	retrieve_history("history");
	return (0);
}
