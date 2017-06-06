/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:23:21 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/06 15:55:37 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int worldMap2[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	wolf_up(t_wolf *wolf)
{
	if (!worldMap2[(int)(wolf->posX + wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		wolf->posX += wolf->dirX * wolf->moveSpeed;
	if (!worldMap2[(int)wolf->posX][(int)(wolf->posY + wolf->dirY * wolf->moveSpeed)])
		wolf->posY += wolf->dirY * wolf->moveSpeed;
}

void	wolf_down(t_wolf *wolf)
{
	if (!worldMap2[(int)(wolf->posX - wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		wolf->posX -= wolf->dirX * wolf->moveSpeed;
	if (!worldMap2[(int)wolf->posX][(int)(wolf->posY - wolf->dirY * wolf->moveSpeed)])
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

void	wolf_events(t_wolf *wolf, t_input *in)
{
	esdl_update_events(in);
	if (in->key[SDL_SCANCODE_W])
		wolf_up(wolf);
	if (in->key[SDL_SCANCODE_S])
		wolf_down(wolf);
	if (in->key[SDL_SCANCODE_D])
		wolf_right(wolf);
	if (in->key[SDL_SCANCODE_A])
		wolf_left(wolf);
}