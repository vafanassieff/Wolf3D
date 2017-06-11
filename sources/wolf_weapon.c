/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:55:28 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/11 19:56:23 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    display_weapon(t_wolf *wolf)
{
    int x;
	int y;
	
	x = 0;
	while (++x < wolf->weapon->w)
	{
		y = 0;
		while (++y < wolf->weapon->h)
		{
			if (esdl_read_pixel(wolf->weapon ,x, y) != COLOR_CYAN)
				esdl_put_pixel(wolf->surf, x, y, esdl_read_pixel(wolf->weapon ,x, y));
		}
	}
}