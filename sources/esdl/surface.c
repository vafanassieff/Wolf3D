/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:55:00 by qfremeau          #+#    #+#             */
/*   Updated: 2017/06/05 13:33:01 by vafanass         ###   ########.fr       */
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

void			esdl_draw_filled_square(SDL_Surface *surf,
				const SDL_Rect *rect, const int color, void *param)
{
	register int		x;
	register int		y;

	(void)param;
	y = 0;
	while (y < rect->h)
	{
		x = 0;
		while (x < rect->w)
		{
			esdl_put_pixel(surf, x + rect->x, y + rect->y, color);
			++x;
		}
		++y;
	}
}

void			esdl_clear_surface(SDL_Surface *surf,
				const SDL_Rect *rect, const int color, void *param)
{
	register int		x;
	register int		y;

	(void)rect;
	(void)param;
	y = 0;
	while (y < surf->h)
	{
		x = 0;
		while (x < surf->w)
		{
			esdl_put_pixel(surf, x, y, color);
			x++;
		}
		y++;
	}
}
