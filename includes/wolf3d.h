/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:06:18 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/07 17:50:11 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include "global.h"
# include "libesdl.h"
# include "libft.h"
# include <math.h>

typedef	struct		s_wolf
{
	t_esdl			*esdl;
	SDL_Surface		*surf;
	SDL_Rect		*rect;
	SDL_Texture		*text;
	SDL_Surface		**wall_texture;
	SDL_Surface		*floor_texture;
	SDL_Surface		*ceiling_texture;
	uint32_t 		pixel;
	uint32_t 		pixel_put;
	int				map[24][24];
	int				render;
	int				w;
	int				h;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineheight;
	int				drawStart;
	int				drawEnd;
	int				color;
	int 			texX;
	int 			texY;
	int				textnb;
	int				x;
	int				y;
	int				d;
	int				floorTexX;
	int				floorTexY;
	double			time;
	double			oldtime;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	double			moveSpeed;
	double			rotSpeed;
	double			frameTime;
	double 			oldDirX;
	double 			oldPlaneX;
	double 			wallX;
	double 			floorXWall;
	double			floorYWall;
	double 			distWall;
	double			distPlayer;
	double			currentDist;
	double 			weight;
	double 			currentFloorX;
	double 			currentFloorY;
	BOOL			no_texture;
}					t_wolf;

void				wolf_events(t_wolf *wolf, t_input *in);
void				display_wolf(t_wolf *wolf);
void 				draw_line(int x, t_wolf *wolf);
void				fill_surf(int color, t_wolf *wolf);
void				fill_skybox(int color, t_wolf *wolf);
void				fill_floor(int color, t_wolf *wolf);
void				wolf_raycasting(t_wolf *wolf);
void				pixel_to_format(t_wolf *wolf, SDL_Surface *texture);
void				fill_map(t_wolf *wolf);
void				wolf_speed(t_wolf *wolf);
void				texture_floor(t_wolf *wolf);

#endif