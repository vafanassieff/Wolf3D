/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/07 17:40:27 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_texture(t_wolf *wolf)
{
	wolf->wall_texture = malloc(sizeof(SDL_Surface) * NB_TEXTURE);
	wolf->wall_texture[0] = SDL_LoadBMP("./texture/BluegreyL.bmp");
	wolf->wall_texture[1] = SDL_LoadBMP("./texture/BluegreyeagleL.bmp");
	wolf->wall_texture[2] = SDL_LoadBMP("./texture/GreybrickworkersL.bmp");
	wolf->wall_texture[3] = SDL_LoadBMP("./texture/SteelwallswitchoffL.bmp");
	wolf->wall_texture[4] = SDL_LoadBMP("./texture/SteelwallswitchonL.bmp");
	wolf->wall_texture[5] = SDL_LoadBMP("./texture/StoneUWHitlerL.bmp");
	wolf->wall_texture[6] = SDL_LoadBMP("./texture/WallpapergreenL.bmp");
	wolf->wall_texture[7] = SDL_LoadBMP("./texture/005-doomhexred.bmp");
	wolf->floor_texture = SDL_LoadBMP("./texture/005-doomhexred.bmp");
	wolf->ceiling_texture = SDL_LoadBMP("./texture/021-brickgreybrownmould1.bmp");
}

static void 	init_wolf(t_wolf *wolf)
{
	wolf->w = WIN_W;
	wolf->h = WIN_H;
	wolf->esdl = malloc(sizeof(t_esdl));
	esdl_init(wolf->esdl, wolf->w, wolf->h, API_NAME);
	wolf->rect = malloc(sizeof(SDL_Rect));
	SDL_GetWindowSize(wolf->esdl->eng.win, &wolf->rect->w, &wolf->rect->h);
	wolf->surf = esdl_create_surface(wolf->rect->w, wolf->rect->h);
	wolf->time = 0;
	wolf->rect->x = 0;
	wolf->rect->y = 0;
	wolf->posX = 12.0;
	wolf->posY = 12.0;
	wolf->dirX = -1.0;
	wolf->dirY = 0.0;
	wolf->planeX = 0.0;
	wolf->planeY = 0.90;
	wolf->esdl->eng.input->quit = 0;
	wolf->no_texture = TRUE;
}

static void		loop_hook(t_wolf *wolf)
{
    while (!wolf->esdl->eng.input->quit)
    {
		wolf_events(wolf, wolf->esdl->eng.input);
		wolf_raycasting(wolf);
		display_wolf(wolf);
    }
}

int 			main(void)
{
	t_wolf	p_wolf;
	t_wolf	*wolf;

	wolf = &p_wolf;
	init_wolf(wolf);
	fill_map(wolf);
	init_texture(wolf);
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}