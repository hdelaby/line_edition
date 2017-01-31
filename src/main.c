/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelaby <hdelaby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:51:53 by hdelaby           #+#    #+#             */
/*   Updated: 2017/01/31 10:09:41 by hdelaby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_getch();
{
	char	buf[3];
	buf = read(0, buf, 3);
	return (buf[0]);
}

char	*line_editing(void)
{
	int		key_pressed;

	while (42)
	{
		key_pressed = ft_getch();
		if (key_pressed = 'p')
			break;
		ft_putchar(key_pressed);
	}
	return ("LOL");
}

int		main(void)
{
	ft_putstr(line_editing());
}
