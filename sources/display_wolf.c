/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wolf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:34:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/06 23:56:07 by vafanass         ###   ########.fr       */
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

void draw_line(int x, t_wolf *wolf)
{
	int y1;
	int y2;
	int y;

	y1 = wolf->drawStart;
	y2 = wolf->drawEnd;
	while (y1 <= y2)
	{
		esdl_put_pixel(wolf->surf, x, y1, wolf->color);
		y1++;
	}
	y1 = wolf->drawStart;
	y = 0;
	while (y <= y1)
	{
		esdl_put_pixel(wolf->surf, x, y, 0xFFFFACA6);
		y++;
	}
	while (y2 <= wolf->h)
	{
		esdl_put_pixel(wolf->surf, x, y2, 0xFFCDCDC1);
		y2++;
	}
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

void	fill_floor(int color, t_wolf *wolf)
{
	int y = wolf->rect->h / 2;
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

void	pixel_to_format(t_wolf *wolf)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;

	//b = wolf->pixel >> 1;
	//g = wolf->pixel >> 4;
	//r = wolf->pixel >> 8;
	SDL_GetRGB(wolf->pixel, wolf->wall->format, &b,&g,&r);
	wolf->pixel_put = 255 << 24 | r << 16 | g << 8 | b << 0;
}