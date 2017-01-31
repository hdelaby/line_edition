/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:30:34 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/31 10:01:18 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		term_basic_config(struct termios *old_term)
{
	static struct termios	*term;

	if (old_term)
		term = old_term;
	else
	{
		if (tcsetattr(0, TCSAFLUSH, old_term))
			return (1);
	}
	return (0);
}

int		term_config(void)
{
	struct termios	term;
	struct termios	old_term;
	char			*term_name;

	term_name = getenv("TERM");
	if (!term_name || !tgetent(NULL, term_name))
		return (-1);
	if (tcgetattr(0, &term) || tcgetattr(0, &old_term))
		return (-1);
	term_basic_config(&old_term);
	term.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(0, TCSAFLUSH, &term))
		return (-1);
	return (0);
}
