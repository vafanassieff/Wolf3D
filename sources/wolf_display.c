/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:34:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 15:41:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			display_wolf(t_wolf *wolf)
{
	SDL_DestroyTexture(wolf->text);
	SDL_RenderClear(wolf->esdl->eng.render);
	wolf->text = SDL_CreateTextureFromSurface(wolf->esdl->eng.render,
		wolf->surf);
	SDL_RenderCopy(wolf->esdl->eng.render, wolf->text, NULL, wolf->rect);
	SDL_RenderPresent(wolf->esdl->eng.render);
}

SDL_Surface		*load_texture(char *path, t_wolf *wolf)
{
	SDL_Surface		*stock;
	SDL_Surface		*surface;

	stock = SDL_LoadBMP(path);
	if (stock == NULL)
	{
		ft_putstr("Error while loading a texture file\n");
		exit(1);
	}
	surface = SDL_ConvertSurfaceFormat(stock, wolf->surf->format->format, 0);
	SDL_FreeSurface(stock);
	return (surface);
}
