/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/04/19 17:29:22 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void 	init_wolf(t_wolf *wolf)
{
	wolf->esdl = malloc(sizeof(t_esdl));
	esdl_init(wolf->esdl, WIN_X, WIN_Y, API_NAME);
	wolf->rect = malloc(sizeof(SDL_Rect));
	SDL_GetWindowSize(wolf->esdl->eng.win, &wolf->rect->w, &wolf->rect->h);
	wolf->rect->x = 0;
	wolf->rect->y = 0;
	wolf->surf = esdl_create_surface(wolf->rect->w, wolf->rect->h);
}


void	display_wolf(t_wolf *wolf)
{
	SDL_RenderClear(wolf->esdl->eng.render);
	SDL_DestroyTexture(wolf->text);
	wolf->text = SDL_CreateTextureFromSurface(wolf->esdl->eng.render, wolf->surf);
	SDL_RenderCopy(wolf->esdl->eng.render, wolf->text, NULL, wolf->rect);
	SDL_RenderPresent(wolf->esdl->eng.render);
}

static void	loop_hook(t_wolf *wolf)
{
	SDL_Event event;

	wolf->esdl->eng.input->quit = 0;
    while (!wolf->esdl->eng.input->quit)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                wolf->esdl->eng.input->quit = 1;
            }
        }
		display_wolf(wolf);
		esdl_fps_limit(wolf->esdl);
		esdl_fps_counter(wolf->esdl);

    }
}

int main(void)
{
	t_wolf	p_wolf;
	t_wolf	*wolf;

	wolf = &p_wolf;
	init_wolf(wolf);
	int y = -1;
	int x;
	while (++y < wolf->rect->h)
	{
		x = -1;
		while (++x < wolf->rect->w)
		{
			esdl_put_pixel(wolf->surf, x, y, 0xFF00FF00);
		}
	}
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}