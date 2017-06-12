/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:06:18 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 16:34:06 by vafanass         ###   ########.fr       */
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
	SDL_Rect		*rect;
	SDL_Texture		*text;
	SDL_Surface		*surf;
	SDL_Surface		**wall_texture;
	SDL_Surface		*floor_texture;
	SDL_Surface		*ceiling_texture;
	SDL_Surface		*icon;
	SDL_Surface		*weapon;
	uint32_t		time;
	uint32_t		oldtime;
	uint32_t		fpstime;
	int				map[24][24];
	int				x;
	int				y;
	int				d;
	int				w;
	int				h;
	int				speedm;
	int				render;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	int 			texx;
	int 			texy;
	int				textnb;
	int				floortexx;
	int				floortexy;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			walldist;
	double			movespeed;
	double			rotspeed;
	double			frametime;
	double 			olddirx;
	double 			oldplanex;
	double 			wallx;
	double 			floorxwall;
	double			floorywall;
	double 			distfromwall;
	double			distplayer;
	double			currentdist;
	double 			weight;
	double 			currentfloorx;
	double 			currentfloory;
}					t_wolf;

SDL_Surface			*load_texture(char *path, t_wolf *wolf);
void				wolf_events(t_wolf *wolf, t_input *in);
void				display_wolf(t_wolf *wolf);
void				fill_surf(int color, t_wolf *wolf);
void				wolf_raycasting(t_wolf *wolf);
void				fill_map(t_wolf *wolf);
void				wolf_speed(t_wolf *wolf);
void				texture_floor(t_wolf *wolf);
void 				init_wolf(t_wolf *wolf);
void				init_texture(t_wolf *wolf);
void    			display_weapon(t_wolf *wolf);

#endif