/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wolf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:34:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/09 19:24:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	display_wolf(t_wolf *wolf)
{
	SDL_DestroyTexture(wolf->text);
	SDL_RenderClear(wolf->esdl->eng.render);
	wolf->text = SDL_CreateTextureFromSurface(wolf->esdl->eng.render, wolf->surf);
	SDL_RenderCopy(wolf->esdl->eng.render, wolf->text, NULL, wolf->rect);
	SDL_RenderPresent(wolf->esdl->eng.render);
	fill_surf(0xFF000000, wolf);
}

SDL_Surface		*load_texture(char *path, t_wolf *wolf)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;

	stock = SDL_LoadBMP(path);
	if (stock == NULL)
		exit(1);
	surface = SDL_ConvertSurfaceFormat(stock, wolf->surf->format->format, 0);
	SDL_FreeSurface(stock);
	return (surface);
}

void	fill_surf(int color, t_wolf *wolf)
{
	int y = -1;
	int x;
	while (++y < wolf->rect->h)
	{
		x = -1;
		while (++x < wolf->rect->w)
		{
			esdl_put_pixel(wolf->surf, x, y, color);
		}
	}
}