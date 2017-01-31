/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/31 10:20:06 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_getch()
{
	char	buf[3];
	read(0, buf, 3);
	return (buf[0]);
}

char	*line_editing(void)
{
	int		key_pressed;
	char	ret[1024];
	int		i;

	i = 0;
	ft_bzero(ret, 1024);
	while (42)
	{
		key_pressed = ft_getch();
		if (key_pressed == 'p')
			break;
		ft_putchar(key_pressed);
		ret[i++] = key_pressed;
	}
	return ("LOL");
}

int		main(void)
{
	term_config();
	ft_putstr(line_editing());
	term_basic_config(NULL);
	return (0);
}
