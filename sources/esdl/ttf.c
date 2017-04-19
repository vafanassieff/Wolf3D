/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 21:31:36 by popzelife         #+#    #+#             */
/*   Updated: 2017/04/19 12:17:22 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			esdl_init_ttf(t_esdl *esdl)
{
	int		ret;

	ret = 1;
	if (TTF_Init() == -1)
	{
		ret = -1;
	}
	esdl->ttf = 1;
	return (ret);
}

t_font		esdl_load_font(char *name, int size, int color)
{
	t_font		f;

	f.font = TTF_OpenFont(name, size);
	if (f.font == NULL)
	{
		exit(-1);
	}
	f.color = esdl_int_to_color(color);
	return (f);
}

t_text		esdl_render_blendedtext(char *text, t_font f, int xy[2],
			SDL_Renderer *render)
{
	t_text			t;
	SDL_Surface		*surf;

	surf = TTF_RenderText_Blended(f.font, text, f.color);
	t.text = SDL_CreateTextureFromSurface(render, surf);
	SDL_FreeSurface(surf);
	t.rect.x = xy[0];
	t.rect.y = xy[1];
	SDL_QueryTexture(t.text, NULL, NULL, &(t.rect.w), &(t.rect.h));
	return (t);
}

t_text		esdl_render_solidtext(char *text, t_font f, int xy[2],
			SDL_Renderer *render)
{
	t_text			t;
	SDL_Surface		*surf;

	surf = TTF_RenderText_Solid(f.font, text, f.color);
	t.text = SDL_CreateTextureFromSurface(render, surf);
	SDL_FreeSurface(surf);
	t.rect.x = xy[0];
	t.rect.y = xy[1];
	SDL_QueryTexture(t.text, NULL, NULL, &(t.rect.w), &(t.rect.h));
	return (t);
}
