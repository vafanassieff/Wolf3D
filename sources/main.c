/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/13 12:21:51 by vafanass         ###   ########.fr       */
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
		esdl_fps_limit(wolf->esdl);
		wolf->frame_number++;
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
	loop_hook(wolf);
	esdl_exit(wolf->esdl);
	return(0);
}