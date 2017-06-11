/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:23:21 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/11 18:38:43 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_up(t_wolf *wolf)
{
	if (!wolf->map[(int)(wolf->posX + wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		wolf->posX += wolf->dirX * wolf->moveSpeed;
	if (!wolf->map[(int)wolf->posX][(int)(wolf->posY + wolf->dirY * wolf->moveSpeed)])
		wolf->posY += wolf->dirY * wolf->moveSpeed;
}

void	wolf_down(t_wolf *wolf)
{
	if (!wolf->map[(int)(wolf->posX - wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		wolf->posX -= wolf->dirX * wolf->moveSpeed;
	if (!wolf->map[(int)wolf->posX][(int)(wolf->posY - wolf->dirY * wolf->moveSpeed)])
		wolf->posY -= wolf->dirY * wolf->moveSpeed;
}

void	wolf_right(t_wolf *wolf)
{
	wolf->oldDirX = wolf->dirX;
    wolf->dirX = wolf->dirX * cos(-wolf->rotSpeed) - wolf->dirY * sin(-wolf->rotSpeed);
    wolf->dirY = wolf->oldDirX * sin(-wolf->rotSpeed) + wolf->dirY * cos(-wolf->rotSpeed);
    wolf->oldPlaneX = wolf->planeX;
    wolf->planeX = wolf->planeX * cos(-wolf->rotSpeed) - wolf->planeY * sin(-wolf->rotSpeed);
    wolf->planeY = wolf->oldPlaneX * sin(-wolf->rotSpeed) + wolf->planeY * cos(-wolf->rotSpeed);
}

void	wolf_left(t_wolf *wolf)
{
	wolf->oldDirX = wolf->dirX;
    wolf->dirX = wolf->dirX * cos(wolf->rotSpeed) - wolf->dirY * sin(wolf->rotSpeed);
    wolf->dirY = wolf->oldDirX * sin(wolf->rotSpeed) + wolf->dirY * cos(wolf->rotSpeed);
    wolf->oldPlaneX = wolf->planeX;
    wolf->planeX = wolf->planeX * cos(wolf->rotSpeed) - wolf->planeY * sin(wolf->rotSpeed);
    wolf->planeY = wolf->oldPlaneX * sin(wolf->rotSpeed) + wolf->planeY * cos(wolf->rotSpeed);
}

void	wolf_left_shift(t_wolf *wolf)
{
	wolf->speedm = 1;
}

void	wolf_events(t_wolf *wolf, t_input *in)
{
	esdl_update_events(in);
	if (in->key[SDL_SCANCODE_W] || in->key[SDL_SCANCODE_UP])
		wolf_up(wolf);
	if (in->key[SDL_SCANCODE_S] || in->key[SDL_SCANCODE_DOWN])
		wolf_down(wolf);
	if (in->key[SDL_SCANCODE_D] || in->key[SDL_SCANCODE_RIGHT])
		wolf_right(wolf);
	if (in->key[SDL_SCANCODE_A] || in->key[SDL_SCANCODE_LEFT])
		wolf_left(wolf);
	if(in->key[SDL_SCANCODE_LSHIFT])
		wolf_left_shift(wolf);
}