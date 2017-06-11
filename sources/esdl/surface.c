/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:55:00 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/11 19:37:17 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		esdl_mask_byteorder(Uint32 *rmask, Uint32 *gmask, \
				Uint32 *bmask, Uint32 *amask)
{
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		*rmask = 0xFF000000;
		*gmask = 0x00FF0000;
		*bmask = 0x0000FF00;
		*amask = 0x000000FF;
	}
	else
	{
		*rmask = 0x000000FF;
		*gmask = 0x0000FF00;
		*bmask = 0x00FF0000;
		*amask = 0xFF000000;
	}
}

SDL_Surface		*esdl_create_surface(int width, int height)
{
	SDL_Surface		*surf;
	Uint32			rmask;
	Uint32			gmask;
	Uint32			bmask;
	Uint32			amask;

	esdl_mask_byteorder(&rmask, &gmask, &bmask, &amask);
	surf = SDL_CreateRGBSurface(0, width, height, 32, \
		rmask, gmask, bmask, amask);
	if (surf == NULL)
	{
		exit(1);
	}
	return (surf);
}

void	remove_color_from_surface(SDL_Surface *surface, uint32_t color)
{
	register int x;
	register int y;
	
	x = 0;
	while (++x < surface->w)
	{
		y = 0;
		while (++y < surface->h)
			if (esdl_read_pixel(surface ,x, y) == color)
				esdl_put_pixel(surface, x, y, 0x00000000);
	}
}

void	fill_surface(SDL_Surface *surface, uint32_t color)
{
	register int x;
	register int y;

	x = 0;
	while (++x < surface->w)
	{
		y = 0;
		while (++y < surface->h)
			esdl_put_pixel(surface, x, y, color);
	}
}