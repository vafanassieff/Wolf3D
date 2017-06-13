/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 19:55:28 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/13 12:51:15 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    weapon_anim(t_wolf *wolf, int nb)
{
	uint32_t		color;
    register int 	x;
	register int 	y;
  
	x = 0;
	while (++x < 120)
	{
		y = 0;
		while (++y < 168)
		{
			color = esdl_read_pixel(wolf->weapon[nb] ,x, y);
			if (color != COLOR_CYAN)
				esdl_put_pixel(wolf->surf, x + wolf->w / 2 - 40, y + wolf->h - 160, color);
		}
	}
}
void    weapon_choice(t_wolf *wolf)
{
    static int nb;
    
    if (nb > 50 || nb < 0)
        nb = 0;
    if (nb <= 7 && nb > 0)
        weapon_anim(wolf, 1);
    else if (nb <= 14 && nb >= 7)
        weapon_anim(wolf, 2);
    else if (nb <= 21 && nb >= 14)
        weapon_anim(wolf, 3);
    else if (nb <= 28 && nb >= 21)
        weapon_anim(wolf, 4);
    else if (nb <= 35 && nb >= 28)
        weapon_anim(wolf, 5);
    else if (nb <= 42 && nb >= 35)
        weapon_anim(wolf, 4);
    else if (nb <= 49 && nb >= 42)
        weapon_anim(wolf, 3);
    else if (nb == 50)
    {
        wolf->fire = 0;
        weapon_anim(wolf, 0);
    }
    else
         weapon_anim(wolf, 0);
    nb++;
}
void    display_weapon(t_wolf *wolf)
{
    if (wolf->fire == 1)
        weapon_choice(wolf);
    else
        weapon_anim(wolf, 0);
}