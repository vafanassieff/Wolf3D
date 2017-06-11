/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:59:22 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/11 18:39:22 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_speed(t_wolf *wolf)
{
	wolf->oldtime = wolf->time;
	wolf->time = SDL_GetTicks();
	wolf->frameTime = (wolf->time - wolf->oldtime) / 1000.0;
	wolf->moveSpeed = wolf->frameTime * 5.0;
	if (wolf->speedm == 1)
	{
		wolf->moveSpeed = wolf->frameTime * 10.0;
		wolf->speedm = 0;
	}
	else 
		wolf->moveSpeed = wolf->frameTime * 5.0;
	wolf->rotSpeed = wolf->frameTime * 3.0;
}