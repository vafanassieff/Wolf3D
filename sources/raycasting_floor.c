/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:35:50 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 14:51:27 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	find_wall(t_wolf *wolf)
{
	if (wolf->side == 0 && wolf->raydirx > 0)
  	{
    	wolf->floorxwall = wolf->mapx;
    	wolf->floorywall = wolf->mapy + wolf->wallx;
  	}
    else if(wolf->side == 0 && wolf->raydirx < 0)
    {
        wolf->floorxwall = wolf->mapx + 1.0;
        wolf->floorywall = wolf->mapy + wolf->wallx;
    }
    else if(wolf->side == 1 && wolf->raydiry > 0)
    {
        wolf->floorxwall = wolf->mapx + wolf->wallx;
        wolf->floorywall = wolf->mapy;
    }
    else
    {
    	wolf->floorxwall = wolf->mapx + wolf->wallx;
        wolf->floorywall = wolf->mapy + 1.0;
    }
}

void	texture_floor(t_wolf *wolf)
{
	find_wall(wolf);
	wolf->distfromwall =  wolf->walldist;
    wolf->distplayer = 0.0;
    if ( wolf->drawend < 0)
		wolf->drawend =  wolf->h;
    wolf->y = wolf->drawend - 1;
    while (++wolf->y <  wolf->h)
    {
    	wolf->currentdist = wolf->h / (2.0 * wolf->y - wolf->h); 
        wolf->weight = (wolf->currentdist -  wolf->distplayer) / ( wolf->distfromwall -  wolf->distplayer);
        wolf->currentfloorx = wolf->weight *  wolf->floorxwall + (1.0 - wolf->weight) *  wolf->posx;
        wolf->currentfloory = wolf->weight *  wolf->floorywall + (1.0 - wolf->weight) *  wolf->posy;
        wolf->floortexx = (int)(wolf->currentfloorx * TEXT_WIDTH) % TEXT_WIDTH;
       	wolf->floortexy = (int)(wolf->currentfloory * TEXT_HEIGHT) % TEXT_HEIGHT;
	    esdl_put_pixel(wolf->surf, wolf->x, wolf->y,
        esdl_read_pixel(wolf->floor_texture,wolf->floortexx, wolf->floortexy));
	   	esdl_put_pixel(wolf->surf, wolf->x, wolf->h - wolf->y,
        esdl_read_pixel(wolf->ceiling_texture,wolf->floortexx, wolf->floortexy));
    }
}