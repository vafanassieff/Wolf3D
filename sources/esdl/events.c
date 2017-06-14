/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:47:31 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 15:24:11 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			esdl_get_mouse_button(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		in->button[event->button.button] = 1;
		ret = SDL_MOUSEBUTTONDOWN;
	}
	else if (event->type == SDL_MOUSEBUTTONUP)
	{
		in->button[event->button.button] = 0;
		ret = SDL_MOUSEBUTTONUP;
	}
	return (ret);
}

static int			esdl_get_input(SDL_Event *event, t_input *in)
{
	int				ret;

	ret = 0;
	if (event->type == SDL_KEYDOWN)
	{
		in->key[event->key.keysym.scancode] = 1;
		ret++;
	}
	else if (event->type == SDL_KEYUP)
	{
		in->key[event->key.keysym.scancode] = 0;
		ret++;
	}
	return (ret);
}

int					esdl_check_input(t_input *in, const int input)
{
	if (in->key[input])
		return (1);
	return (0);
}

void				esdl_update_events(t_input *in)
{
	SDL_Event		event;
	int				ret;

	ret = 0;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT || event.key.keysym.scancode ==
			SDL_SCANCODE_ESCAPE)
			in->quit = 1;
		if ((ret += esdl_get_input(&event, in)) > 0)
			break ;
		if ((ret += esdl_get_mouse_button(&event, in)) > 0)
			break ;
	}
}
