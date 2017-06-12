/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/12 14:44:15 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		loop_hook(t_wolf *wolf)
{
    while (!wolf->esdl->eng.input->quit)
    {
		wolf_events(wolf, wolf->esdl->eng.input);
		wolf_raycasting(wolf);
		display_weapon(wolf);
		display_wolf(wolf);
		SDL_SetWindowTitle(wolf->esdl->eng.win, ft_itoa(1.0 / wolf->frametime));
    }
}

int 			main(void)
{
	t_wolf	p_wolf;
	t_wolf	*wolf;

	wolf = &p_wolf;
	init_wolf(wolf);
	fill_map(wolf);
	init_texture(wolf);
	SDL_SetWindowIcon(wolf->esdl->eng.win, wolf->icon);
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}