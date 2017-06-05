/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:06:18 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/05 17:23:14 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

#include "global.h"
#include "libesdl.h"
#include "libft.h"

typedef	struct		s_wolf
{
	t_esdl			*esdl;
	SDL_Surface		*surf;
	SDL_Rect		*rect;
	SDL_Texture		*text;
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
	
}					t_wolf;

void	wolf_events(t_wolf *wolf, t_input *in);
void	display_wolf(t_wolf *wolf);
void 			draw_line(int x, t_wolf *wolf);
void	fill_surf(int color, t_wolf *wolf);
#endif