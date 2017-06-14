/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 17:22:14 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		wolf_exit(t_wolf *wolf)
{
	int i;

	esdl_exit(wolf->esdl);
	i = 0;
	while (i < NB_TEXTURE)
	{
		SDL_FreeSurface(wolf->wall_texture[i]);
		i++;
	}
	free(wolf->wall_texture);
	i = 0;
	while (i < ANIME_SHOTGUN)
	{
		SDL_FreeSurface(wolf->weapon[i]);
		i++;
	}
	free(wolf->weapon);
	SDL_FreeSurface(wolf->icon);
	SDL_FreeSurface(wolf->floor_texture);
	SDL_FreeSurface(wolf->ceiling_texture);
	SDL_FreeSurface(wolf->surf);
	free(wolf->esdl);
}

static void		loop_hook(t_wolf *wolf)
{
	while (!wolf->esdl->eng.input->quit)
	{
		wolf_events(wolf, wolf->esdl->eng.input);
		wolf_raycasting(wolf);
		display_weapon(wolf);
		display_wolf(wolf);
		esdl_fps_limit(wolf->esdl);
		wolf->frame_number++;
	}
}

int				main(void)
{
	t_wolf	p_wolf;
	t_wolf	*wolf;

	wolf = &p_wolf;
	init_wolf(wolf);
	fill_map(wolf);
	init_texture(wolf);
	loop_hook(wolf);
	wolf_exit(wolf);
	return (0);
}
