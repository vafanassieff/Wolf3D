/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_event_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:45:23 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 16:29:11 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_left_shift(t_wolf *wolf)
{
	wolf->speedm = 1;
}

void	wolf_left_button(t_wolf *wolf)
{
	wolf->fire = 1;
}

void	wolf_use_button(t_wolf *wolf)
{
	if (wolf->map[(int)wolf->posx - 1][(int)wolf->posy] == 4)
	{
		wolf->map[(int)wolf->posx - 1][(int)wolf->posy] = 5;
		wolf->map[(int)wolf->posx - 1][(int)wolf->posy + 2] = 0;
	}
}
