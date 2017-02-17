/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:18:28 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/17 15:18:20 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "libft.h"
# include "fcntl.h"
# include "line_edition.h"

# define HISTORY_PATH "sh_history"

void	append_history(char *entry);
void	old_hist_entry(t_line *line, t_dlist **hist);
void	new_hist_entry(t_line *line, t_dlist **hist);
t_dlist	*retrieve_history(void);

#endif
