/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 13:23:21 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/14 15:45:42 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf_up(t_wolf *wolf)
{
	if (!wolf->map[(int)(wolf->posx + wolf->dirx *
		wolf->movespeed)][(int)wolf->posy])
		wolf->posx += wolf->dirx * wolf->movespeed;
	if (!wolf->map[(int)wolf->posx][(int)(wolf->posy +
		wolf->diry * wolf->movespeed)])
		wolf->posy += wolf->diry * wolf->movespeed;
}

void	wolf_down(t_wolf *wolf)
{
	if (!wolf->map[(int)(wolf->posx - wolf->dirx *
		wolf->movespeed)][(int)wolf->posy])
		wolf->posx -= wolf->dirx * wolf->movespeed;
	if (!wolf->map[(int)wolf->posx][(int)(wolf->posy -
		wolf->diry * wolf->movespeed)])
		wolf->posy -= wolf->diry * wolf->movespeed;
}

void	wolf_right(t_wolf *wolf)
{
	wolf->olddirx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(-wolf->rotspeed) -
		wolf->diry * sin(-wolf->rotspeed);
	wolf->diry = wolf->olddirx * sin(-wolf->rotspeed) +
		wolf->diry * cos(-wolf->rotspeed);
	wolf->oldplanex = wolf->planex;
	wolf->planex = wolf->planex * cos(-wolf->rotspeed) -
		wolf->planey * sin(-wolf->rotspeed);
	wolf->planey = wolf->oldplanex * sin(-wolf->rotspeed) +
		wolf->planey * cos(-wolf->rotspeed);
}

void	wolf_left(t_wolf *wolf)
{
	wolf->olddirx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(wolf->rotspeed) -
		wolf->diry * sin(wolf->rotspeed);
	wolf->diry = wolf->olddirx * sin(wolf->rotspeed) +
		wolf->diry * cos(wolf->rotspeed);
	wolf->oldplanex = wolf->planex;
	wolf->planex = wolf->planex * cos(wolf->rotspeed) -
		wolf->planey * sin(wolf->rotspeed);
	wolf->planey = wolf->oldplanex * sin(wolf->rotspeed) +
		wolf->planey * cos(wolf->rotspeed);
}

void	wolf_events(t_wolf *wolf, t_input *in)
{
	esdl_update_events(in);
	if (in->key[SDL_SCANCODE_W] || in->key[SDL_SCANCODE_UP])
		wolf_up(wolf);
	if (in->key[SDL_SCANCODE_S] || in->key[SDL_SCANCODE_DOWN])
		wolf_down(wolf);
	if (in->key[SDL_SCANCODE_D] || in->key[SDL_SCANCODE_RIGHT])
		wolf_right(wolf);
	if (in->key[SDL_SCANCODE_A] || in->key[SDL_SCANCODE_LEFT])
		wolf_left(wolf);
	if (in->key[SDL_SCANCODE_LSHIFT])
		wolf_left_shift(wolf);
	if (in->button[SDL_BUTTON_LEFT])
		wolf_left_button(wolf);
	if (in->key[SDL_SCANCODE_E])
		wolf_use_button(wolf);
}
