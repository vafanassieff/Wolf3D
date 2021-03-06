/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:59:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 15:35:55 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_speed(t_wolf *wolf)
{
	wolf->oldtime = wolf->time;
	wolf->time = SDL_GetTicks();
	wolf->frametime = (wolf->time - wolf->oldtime) / 1000.0;
	wolf->movespeed = wolf->frametime * 5.0;
	if (wolf->speedm == 1)
	{
		wolf->movespeed = wolf->frametime * 10.0;
		wolf->speedm = 0;
	}
	else
		wolf->movespeed = wolf->frametime * 5.0;
	wolf->rotspeed = wolf->frametime * 3.0;
}
