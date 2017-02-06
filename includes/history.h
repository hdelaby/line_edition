#ifndef HISTORY_H
# define HISTORY_H

#include "libft.h"
#include "fcntl.h"
#include "line_editing.h"

int		append_history(char *path, char *entry);
t_dlist	*retrieve_history(char *path);
int		old_hist_entry(t_dlist **lst, t_dlist **hist, t_line *line);

#endif
