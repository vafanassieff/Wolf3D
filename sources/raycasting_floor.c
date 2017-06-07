/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:35:50 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/07 17:42:15 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_floor(t_wolf *wolf)
{
if(wolf->side == 0 && wolf->rayDirX > 0)
      {
        wolf->floorXWall = wolf->mapX;
        wolf->floorYWall = wolf->mapY + wolf->wallX;
      }
      else if(wolf->side == 0 && wolf->rayDirX < 0)
      {
        wolf->floorXWall = wolf->mapX + 1.0;
        wolf->floorYWall = wolf->mapY + wolf->wallX;
      }
      else if(wolf->side == 1 && wolf->rayDirY > 0)
      {
        wolf->floorXWall = wolf->mapX + wolf->wallX;
        wolf->floorYWall = wolf->mapY;
      }
      else
      {
        wolf->floorXWall = wolf->mapX + wolf->wallX;
        wolf->floorYWall = wolf->mapY + 1.0;
      }

       wolf->distWall =  wolf->perpWallDist;
       wolf->distPlayer = 0.0;

      if ( wolf->drawEnd < 0)
	  		wolf->drawEnd =  wolf->h;

      for(wolf->y =  wolf->drawEnd + 1; wolf->y <  wolf->h; wolf->y++)
      {
        wolf->currentDist = wolf->h / (2.0 * wolf->y - wolf->h); 
        wolf->weight = ( wolf->currentDist -  wolf->distPlayer) / ( wolf->distWall -  wolf->distPlayer);

        wolf->currentFloorX = wolf->weight *  wolf->floorXWall + (1.0 - wolf->weight) *  wolf->posX;
        wolf->currentFloorY = wolf->weight *  wolf->floorYWall + (1.0 - wolf->weight) *  wolf->posY;

        wolf->floorTexX = (int)(wolf->currentFloorX * texWidth) % texWidth;
       	wolf->floorTexY = (int)(wolf->currentFloorY * texHeight) % texHeight;
		wolf->pixel = esdl_read_pixel(wolf->floor_texture,wolf->floorTexX, wolf->floorTexY);
		pixel_to_format(wolf, wolf->floor_texture);
	   	esdl_put_pixel(wolf->surf, wolf->x, wolf->y - 1, wolf->pixel_put);
		wolf->pixel = esdl_read_pixel(wolf->ceiling_texture,wolf->floorTexX, wolf->floorTexY);
		pixel_to_format(wolf, wolf->ceiling_texture);
	   	esdl_put_pixel(wolf->surf, wolf->x, wolf->h - wolf->y + 1, wolf->pixel_put);
      }
}