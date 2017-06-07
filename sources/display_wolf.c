/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wolf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:34:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/07 17:40:42 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	display_wolf(t_wolf *wolf)
{
	SDL_RenderClear(wolf->esdl->eng.render);
	SDL_DestroyTexture(wolf->text);
	wolf->text = SDL_CreateTextureFromSurface(wolf->esdl->eng.render, wolf->surf);
	SDL_RenderCopy(wolf->esdl->eng.render, wolf->text, NULL, wolf->rect);
	SDL_RenderPresent(wolf->esdl->eng.render);
	fill_surf(0xFF000000, wolf);
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

void	fill_skybox(int color, t_wolf *wolf)
{
	int y = -1;
	int x;
	while (++y < wolf->rect->h / 2)
	{
		x = -1;
		while (++x < wolf->rect->w)
		{
			esdl_put_pixel(wolf->surf, x, y, color);
		}
	}
}

void	pixel_to_format(t_wolf *wolf, SDL_Surface *texture)
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	SDL_GetRGB(wolf->pixel, texture->format, &blue ,&green ,&red);
	wolf->pixel_put = 255 << 24 | red << 16 | green << 8 | blue << 0;
}