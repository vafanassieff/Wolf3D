/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/09 20:06:12 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_texture(t_wolf *wolf)
{
	wolf->wall_texture = malloc(sizeof(SDL_Surface) * NB_TEXTURE);
	wolf->wall_texture[0] = load_texture("./ressources/texture/BluegreyL.bmp", wolf);
	wolf->wall_texture[1] = load_texture("./ressources/texture/BluegreyeagleL.bmp", wolf);
	wolf->wall_texture[2] = load_texture("./ressources/texture/GreybrickworkersL.bmp", wolf);
	wolf->wall_texture[3] = load_texture("./ressources/texture/SteelwallswitchoffL.bmp", wolf);
	wolf->wall_texture[4] = load_texture("./ressources/texture/SteelwallswitchonL.bmp", wolf);
	wolf->wall_texture[5] = load_texture("./ressources/texture/StoneUWHitlerL.bmp", wolf);
	wolf->wall_texture[6] = load_texture("./ressources/texture/WallpapergreenL.bmp", wolf);
	wolf->wall_texture[7] = load_texture("./ressources/texture/005-doomhexred.bmp", wolf);
	wolf->floor_texture = load_texture("./ressources/texture/005-doomhexred.bmp", wolf);
	wolf->ceiling_texture = load_texture("./ressources/texture/021-brickgreybrownmould1.bmp", wolf);
	wolf->icon = load_texture("./ressources/icon/wolf_icon.bmp", wolf);

}

static void 	init_wolf(t_wolf *wolf)
{
	wolf->w = WIN_W;
	wolf->h = WIN_H;
	wolf->esdl = malloc(sizeof(t_esdl));
	if (esdl_init(wolf->esdl, wolf->w, wolf->h, APP_NAME))
		exit(1);
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
}

static void		loop_hook(t_wolf *wolf)
{
    while (!wolf->esdl->eng.input->quit)
    {
		wolf_events(wolf, wolf->esdl->eng.input);
		wolf_raycasting(wolf);
		display_wolf(wolf);
		SDL_SetWindowTitle(wolf->esdl->eng.win, ft_itoa(1.0 / wolf->frameTime));
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
	SDL_SetWindowIcon(wolf->esdl->eng.win, wolf->icon);
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}