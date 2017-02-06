#ifndef HISTORY_H
# define HISTORY_H

#include "libft.h"
#include "fcntl.h"

int		append_history(char *path, char *entry);
t_dlist	*retrieve_history(char *path);

#endif
