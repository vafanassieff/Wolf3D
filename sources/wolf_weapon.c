/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:55:28 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 16:36:59 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    display_weapon(t_wolf *wolf)
{
	uint32_t		color;
    register int 	x;
	register int 	y;
	
	//printf("time = %u\n", wolf->time);
	x = 0;
	while (++x < wolf->weapon->w)
	{
		y = 0;
		while (++y < wolf->weapon->h)
		{
			color = esdl_read_pixel(wolf->weapon ,x, y);
			if (color != COLOR_CYAN)
				esdl_put_pixel(wolf->surf, x, y, color);
		}
	}
}