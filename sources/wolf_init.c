/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 18:41:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 14:48:31 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_texture(t_wolf *wolf)
{
	wolf->wall_texture = malloc(sizeof(SDL_Surface) * NB_TEXTURE);
	wolf->wall_texture[0] = load_texture(TEXT_BLUE_EAGLE, wolf);
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
    wolf->weapon = load_texture("./ressources/sprite/shotgun.bmp", wolf);
}

void 	init_wolf(t_wolf *wolf)
{
	wolf->w = WIN_W;
	wolf->h = WIN_H;
	wolf->esdl = malloc(sizeof(t_esdl));
	if (esdl_init(wolf->esdl, wolf->w, wolf->h, APP_NAME))
		exit(1);
	wolf->rect = malloc(sizeof(SDL_Rect));
	SDL_GetWindowSize(wolf->esdl->eng.win, &wolf->rect->w, &wolf->rect->h);
	wolf->surf = esdl_create_surface(wolf->rect->w, wolf->rect->h);
    fill_surface(wolf->surf, 0xFFFFFF00);
	wolf->time = 0;
	wolf->rect->x = 0;
	wolf->rect->y = 0;
	wolf->posx = 12.0;
	wolf->posy = 12.0;
	wolf->dirx = -1.0;
	wolf->diry = 0.0;
	wolf->planex = 0.0;
	wolf->planey = 0.90;
	wolf->speedm = 0;
	wolf->esdl->eng.input->quit = 0;
}