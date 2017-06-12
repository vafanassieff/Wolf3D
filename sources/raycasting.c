/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:32:35 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 14:44:18 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void find_step(t_wolf *wolf)
{
	if (wolf->raydirx < 0)
		{
			wolf->stepx = -1;
			wolf->sidedistx = (wolf->rayposx - wolf->mapx) * wolf->deltadistx;
		}
		else
		{
			wolf->stepx = 1;
			wolf->sidedistx = (wolf->mapx + 1.0 - wolf->rayposx) * wolf->deltadistx;
		}
		if (wolf->raydiry < 0)
		{
			wolf->stepy = -1;
			wolf->sidedisty = (wolf->rayposy - wolf->mapy) * wolf->deltadisty;
		}
		else
		{
			wolf->stepy = 1;
			wolf->sidedisty = (wolf->mapy + 1.0 - wolf->rayposy) * wolf->deltadisty;
		}
}

static void	dda(t_wolf *wolf)
{
	while (wolf->hit == 0)
	{
		if (wolf->sidedistx < wolf->sidedisty)
		{
			wolf->sidedistx += wolf->deltadistx;
			wolf->mapx += wolf->stepx;
			wolf->side = 0;
		}
		else
		{
			wolf->sidedisty += wolf->deltadisty;
			wolf->mapy += wolf->stepy;
			wolf->side = 1;
		}
		if (wolf->map[wolf->mapx][wolf->mapy] > 0)
			wolf->hit = 1;
	}
}

static void	init_raycasting(t_wolf *wolf)
{
		wolf->camerax = 2 * wolf->x / (double)wolf->w - 1.0;
		wolf->rayposx = wolf->posx;
		wolf->rayposy = wolf->posy;
		wolf->raydirx = wolf->dirx + wolf->planex * wolf->camerax;
		wolf->raydiry = wolf->diry + wolf->planey * wolf->camerax;
		wolf->mapx = (int)wolf->rayposx;
		wolf->mapy = (int)wolf->rayposy;
		wolf->deltadistx = sqrt(1 + (wolf->raydiry * wolf->raydiry) / (wolf->raydirx * wolf->raydirx));
		wolf->deltadisty = sqrt(1 + (wolf->raydirx * wolf->raydirx) / (wolf->raydiry * wolf->raydiry));
		wolf->hit = 0;
}


static void	texture_wall(t_wolf *wolf)
{
	wolf->textnb = wolf->map[wolf->mapx][wolf->mapy] - 1;
	if (wolf->side == 0) 
		wolf->wallx = wolf->rayposy + wolf->walldist * wolf->raydiry;
	else
		wolf->wallx = wolf->rayposx + wolf->walldist * wolf->raydirx;
    wolf->wallx -= floor((wolf->wallx));
    wolf->texx = (int)(wolf->wallx * (double)texWidth);
    if(wolf->side == 0 && wolf->raydirx > 0)
		  wolf->texx = texWidth - wolf->texx - 1;
    if(wolf->side == 1 && wolf->raydiry < 0)
		wolf->texx = texWidth - wolf->texx - 1;
	wolf->y = wolf->drawstart;
	while (wolf->y++ < wolf->drawend)
      {
        wolf->d = wolf->y * 256 - wolf->h * 128 + wolf->lineheight * 128;
        wolf->texy = ((wolf->d * texHeight) / wolf->lineheight) / 256;
	   	esdl_put_pixel(wolf->surf, wolf->x, wolf->y, 
		esdl_read_pixel(wolf->wall_texture[wolf->textnb], wolf->texx, wolf->texy));
      }
}

void	wolf_raycasting(t_wolf *wolf)
{
	wolf->x = -1;
	while (++wolf->x < wolf->w)
	{
		init_raycasting(wolf);
		find_step(wolf);
		dda(wolf);
		if (wolf->side == 0)
			wolf->walldist = (wolf->mapx - wolf->rayposx + (1 - wolf->stepx) / 2) / wolf->raydirx;
		else
			wolf->walldist = (wolf->mapy - wolf->rayposy + (1 - wolf->stepy) / 2) / wolf->raydiry;
		wolf->lineheight = (int)(wolf->h / wolf->walldist);
		wolf->drawstart = -wolf->lineheight / 2 + wolf->h / 2;
		if (wolf->drawstart < 0)
			wolf->drawstart = 0;
		wolf->drawend = wolf->lineheight / 2 + wolf->h / 2;
		if (wolf->drawend >= wolf->h)
			wolf->drawend = wolf->h - 1;
		texture_wall(wolf);
		texture_floor(wolf);
	}
	wolf_speed(wolf);
}