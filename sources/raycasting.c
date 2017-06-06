/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:35 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/06 17:23:24 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int worldMap[mapWidth][mapHeight]=
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

void	init_raycasting(t_wolf *wolf)
{
		wolf->cameraX = 2 * wolf->x / (double)wolf->w - 1.0;
		wolf->rayPosX = wolf->posX;
		wolf->rayPosY = wolf->posY;
		wolf->rayDirX = wolf->dirX + wolf->planeX * wolf->cameraX;
		wolf->rayDirY = wolf->dirY + wolf->planeY * wolf->cameraX;
		wolf->mapX = (int)wolf->rayPosX;
		wolf->mapY = (int)wolf->rayPosY;
		wolf->deltaDistX = sqrt(1 + (wolf->rayDirY * wolf->rayDirY) / (wolf->rayDirX * wolf->rayDirX));
		wolf->deltaDistY = sqrt(1 + (wolf->rayDirX * wolf->rayDirX) / (wolf->rayDirY * wolf->rayDirY));
		wolf->hit = 0;
}

void	texture_wolf(t_wolf *wolf)
{
	if (wolf->side == 0) 
		wolf->wallX = wolf->rayPosY + wolf->perpWallDist * wolf->rayDirY;
	else
		wolf->wallX = wolf->rayPosX + wolf->perpWallDist * wolf->rayDirX;
    wolf->wallX -= floor((wolf->wallX));
    wolf->texX = (int)(wolf->wallX * (double)texWidth);
    if(wolf->side == 0 && wolf->rayDirX > 0)
		  wolf->texX = texWidth - wolf->texX - 1;
    if(wolf->side == 1 && wolf->rayDirY < 0)
		wolf->texX = texWidth - wolf->texX - 1;
	wolf->y = wolf->drawStart;
	while(wolf->y++ < wolf->drawEnd)
      {
        wolf->d = wolf->y * 256 - wolf->h * 128 + wolf->lineheight * 128;
        wolf->texY = ((wolf->d * texHeight) / wolf->lineheight) / 256;
		wolf->pixel = esdl_read_pixel(wolf->wall, wolf->texX, wolf->texY);
		pixel_to_format(wolf);
	   	esdl_put_pixel(wolf->surf, wolf->x, wolf->y, wolf->pixel_put);
      }
}

void	wolf_raycasting(t_wolf *wolf)
{

	wolf->x = -1;
	while (++wolf->x < wolf->w)
	{
		init_raycasting(wolf);
		if (wolf->rayDirX < 0)
		{
			wolf->stepX = -1;
			wolf->sideDistX = (wolf->rayPosX - wolf->mapX) * wolf->deltaDistX;
		}
		else
		{
			wolf->stepX = 1;
			wolf->sideDistX = (wolf->mapX + 1.0 - wolf->rayPosX) * wolf->deltaDistX;
		}
		if (wolf->rayDirY < 0)
		{
			wolf->stepY = -1;
			wolf->sideDistY = (wolf->rayPosY - wolf->mapY) * wolf->deltaDistY;
		}
		else
		{
			wolf->stepY = 1;
			wolf->sideDistY = (wolf->mapY + 1.0 - wolf->rayPosY) * wolf->deltaDistY;
		}
		while (wolf->hit == 0)
		{
			if (wolf->sideDistX < wolf->sideDistY)
			{
				wolf->sideDistX += wolf->deltaDistX;
				wolf->mapX += wolf->stepX;
				wolf->side = 0;
			}
			else
			{
				wolf->sideDistY += wolf->deltaDistY;
				wolf->mapY += wolf->stepY;
				wolf->side = 1;
			}
			if (worldMap[wolf->mapX][wolf->mapY] > 0)
				wolf->hit = 1;
		}
		if (wolf->side == 0)
		{
			wolf->perpWallDist = (wolf->mapX - wolf->rayPosX + (1 - wolf->stepX) / 2) / wolf->rayDirX;
		}
		else
		{
			wolf->perpWallDist = (wolf->mapY - wolf->rayPosY + (1 - wolf->stepY) / 2) / wolf->rayDirY;
		}
		wolf->lineheight = (int)(wolf->h / wolf->perpWallDist);
		wolf->drawStart = -wolf->lineheight / 2 + wolf->h / 2;
		if (wolf->drawStart < 0)
		{
			wolf->drawStart = 0;
		}
		wolf->drawEnd = wolf->lineheight / 2 + wolf->h / 2;
		if (wolf->drawEnd >= wolf->h)
		{
			wolf->drawEnd = wolf->h - 1;
		}
		switch(worldMap[wolf->mapX][wolf->mapY])
		{
			case 1: wolf->color = 0xFF0000FF; break;
			case 2: wolf->color = 0xFF00FF00; break;
			case 3: wolf->color = 0xFFFF0000; break;
			case 4: wolf->color = 0xFFFFFFFF; break;
			default: wolf->color = 0xFF00FF00; break;
		}
		if (wolf->side == 1)
		{
			wolf->color = wolf->color / 2;
		}
		//draw_line(x, wolf);
		texture_wolf(wolf);
	}
		wolf->oldtime = wolf->time;
		wolf->time = SDL_GetTicks();
		wolf->frameTime = (wolf->time - wolf->oldtime) / 1000.0;
		wolf->moveSpeed = wolf->frameTime * 5.0;
		wolf->rotSpeed = wolf->frameTime * 3.0;
}