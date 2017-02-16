/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:01:51 by hdelaby           #+#    #+#             */
/*   Updated: 2017/02/16 10:03:11 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_CONFIG_H
# define TERM_CONFIG_H

# include "libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>

void	raw_term_mode(void);
void	default_term_mode(void);

#endif
