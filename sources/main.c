/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/05 17:35:43 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#define mapWidth 24
#define mapHeight 24

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

void 	init_wolf(t_wolf *wolf)
{
	wolf->time = 0;
	wolf->oldtime = 0;
	wolf->w = WIN_W;
	wolf->h = WIN_H;
	wolf->esdl = malloc(sizeof(t_esdl));
	esdl_init(wolf->esdl, wolf->w, wolf->h, API_NAME);
	wolf->rect = malloc(sizeof(SDL_Rect));
	SDL_GetWindowSize(wolf->esdl->eng.win, &wolf->rect->w, &wolf->rect->h);
	wolf->rect->x = 0;
	wolf->rect->y = 0;
	wolf->surf = esdl_create_surface(wolf->rect->w, wolf->rect->h);
	wolf->posX = 22.0;
	wolf->posY = 12.0;
	wolf->dirX = -1.0;
	wolf->dirY = 0.0;
	wolf->planeX = 0.0;
	wolf->planeY = 0.90;
}

void	wolf_raycasting(t_wolf *wolf)
{
	int x;
	for (x = 0; x < wolf->w; x++)
	{
		wolf->cameraX = 2 * x / (double)wolf->w - 1.0;
		wolf->rayPosX = wolf->posX;
		wolf->rayPosY = wolf->posY;
		wolf->rayDirX = wolf->dirX + wolf->planeX * wolf->cameraX;
		wolf->rayDirY = wolf->dirY + wolf->planeY * wolf->cameraX;
		wolf->mapX = (int)wolf->rayPosX;
		wolf->mapY = (int)wolf->rayPosY;
		wolf->deltaDistX = sqrt(1 + (wolf->rayDirY * wolf->rayDirY) / (wolf->rayDirX * wolf->rayDirX));
		wolf->deltaDistY = sqrt(1 + (wolf->rayDirX * wolf->rayDirX) / (wolf->rayDirY * wolf->rayDirY));
		wolf->hit = 0;
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
			wolf->color = wolf->color;
		}
		draw_line(x, wolf);
	}
		wolf->oldtime = wolf->time;
		wolf->time = SDL_GetTicks();
		wolf->frameTime = (wolf->time - wolf->oldtime) / 1000.0;
		wolf->moveSpeed = wolf->frameTime * 5.0;
		wolf->rotSpeed = wolf->frameTime * 3.0;
}

static void	loop_hook(t_wolf *wolf)
{
	wolf->esdl->eng.input->quit = 0;
    while (!wolf->esdl->eng.input->quit)
    {
		wolf_events(wolf, wolf->esdl->eng.input);
		wolf_raycasting(wolf);
		display_wolf(wolf);
    }
}

int main(void)
{
	t_wolf	p_wolf;
	t_wolf	*wolf;

	wolf = &p_wolf;
	init_wolf(wolf);
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}