/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:23:21 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/05 17:31:38 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define mapWidth 24
#define mapHeight 24

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

void	wolf_events(t_wolf *wolf, t_input *in)
{
	esdl_update_events(in);
	if (in->key[SDL_SCANCODE_UP])
	{
		if (!worldMap2[(int)(wolf->posX + wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		{
			wolf->posX += wolf->dirX * wolf->moveSpeed;
		}
		if (!worldMap2[(int)wolf->posX][(int)(wolf->posY + wolf->dirY * wolf->moveSpeed)])
		{
			wolf->posY += wolf->dirY * wolf->moveSpeed;
		}
	}
	if (in->key[SDL_SCANCODE_DOWN])
	{
		if (!worldMap2[(int)(wolf->posX - wolf->dirX * wolf->moveSpeed)][(int)wolf->posY])
		{
			wolf->posX -= wolf->dirX * wolf->moveSpeed;
		}
		if (!worldMap2[(int)wolf->posX][(int)(wolf->posY - wolf->dirY * wolf->moveSpeed)])
		{
			wolf->posY -= wolf->dirY * wolf->moveSpeed;
		}
	}
	if (in->key[SDL_SCANCODE_RIGHT])
	{
		double oldDirX = wolf->dirX;
    	wolf->dirX = wolf->dirX * cos(-wolf->rotSpeed) - wolf->dirY * sin(-wolf->rotSpeed);
     	wolf->dirY = oldDirX * sin(-wolf->rotSpeed) + wolf->dirY * cos(-wolf->rotSpeed);
      	double oldPlaneX = wolf->planeX;
      	wolf->planeX = wolf->planeX * cos(-wolf->rotSpeed) - wolf->planeY * sin(-wolf->rotSpeed);
      	wolf->planeY = oldPlaneX * sin(-wolf->rotSpeed) + wolf->planeY * cos(-wolf->rotSpeed);
	}
	if (in->key[SDL_SCANCODE_LEFT])
	{
		double oldDirX = wolf->dirX;
     	wolf->dirX = wolf->dirX * cos(wolf->rotSpeed) - wolf->dirY * sin(wolf->rotSpeed);
      	wolf->dirY = oldDirX * sin(wolf->rotSpeed) + wolf->dirY * cos(wolf->rotSpeed);
    	double oldPlaneX = wolf->planeX;
      	wolf->planeX = wolf->planeX * cos(wolf->rotSpeed) - wolf->planeY * sin(wolf->rotSpeed);
      	wolf->planeY = oldPlaneX * sin(wolf->rotSpeed) + wolf->planeY * cos(wolf->rotSpeed);
	}
}