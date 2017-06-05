/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wolf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:34:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/05 17:24:06 by vafanass         ###   ########.fr       */
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
	
	y1 = wolf->drawStart;
	y2 = wolf->drawEnd;
	while (y1 <= y2)
	{
		esdl_put_pixel(wolf->surf, x, y1, wolf->color);
		y1++;
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