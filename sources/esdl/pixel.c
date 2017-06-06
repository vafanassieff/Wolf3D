/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:10:16 by qfremeau          #+#    #+#             */
/*   Updated: 2017/06/06 15:39:59 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			esdl_put_pixel(SDL_Surface *surf, const int x, const int y,
				const int color)
{
	Uint32		*pixels;

	if (x >= 0 && y >= 0 && x < surf->w && y < surf->h)
	{
		pixels = (Uint32 *)surf->pixels;
		pixels[y * surf->w + x] = color;
	}
}

Uint32			esdl_read_pixel(SDL_Surface *surface, const int x, const int y)
{
	int		bpp;
	uint8_t *p;

	bpp = surface->format->BytesPerPixel;
	p = (uint8_t *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(uint16_t *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(uint32_t *)p);
	return (0);
}

// Debug a virer

void		print_pixel(uint32_t pixel, SDL_Surface *surface)
{
	uint8_t r,g,b;

	SDL_GetRGB(pixel, surface->format, &r, &g, &b);
	printf("r = %u g = %u b = %u\n", r, g,b);
}
