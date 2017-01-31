/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_config.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:01:51 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/31 10:04:36 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_CONFIG_H
# define TERM_CONFIG_H

# include "libft.h"
# include <termios.h>

int		term_basic_config(struct termios *old_term);
int		term_config(void);

#endif
