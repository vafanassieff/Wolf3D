/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/06 17:56:53 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void 	init_wolf(t_wolf *wolf)
{
	wolf->time = 0;
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
	wolf->wall = SDL_LoadBMP("./texture/RedgreyeagleD.bmp");
	wolf->esdl->eng.input->quit = 0;
	SDL_PixelFormat* pixelFormat = wolf->wall->format;
uint32_t pixelFormatEnum = pixelFormat->format;
const char* surfacePixelFormatName = SDL_GetPixelFormatName(pixelFormatEnum);
SDL_Log("The surface's pixelformat is %s", surfacePixelFormatName);

}

static void	loop_hook(t_wolf *wolf)
{
    while (!wolf->esdl->eng.input->quit)
    {
		wolf_events(wolf, wolf->esdl->eng.input);
		fill_skybox(0xFFFFACA6, wolf);
		fill_floor(0xFFCDCDC1, wolf);
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