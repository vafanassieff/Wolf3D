/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:11:48 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/09 19:46:33 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	esdl_init_esdl(t_esdl *esdl, const int rx, const int ry)
{
	esdl->eng.input = (t_input*)malloc(sizeof(t_input));
	ft_memset(esdl->eng.input, 0, sizeof(t_input));
	esdl->eng.rx = rx;
	esdl->eng.ry = ry;
}

int			esdl_init(t_esdl *esdl, const int rx, const int ry, char *name)
{
	esdl_init_esdl(esdl, rx, ry);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (-1);
	esdl->eng.win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, rx, ry, 0);
	if (!esdl->eng.win)
		return (-1);
	esdl->eng.render = SDL_CreateRenderer(esdl->eng.win, -1, 0);
	if (!esdl->eng.render)
		return (-1);
	return (0);
}
