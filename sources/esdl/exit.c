/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:29:11 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/09 19:40:30 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				esdl_exit(t_esdl *esdl)
{
	SDL_DestroyRenderer(esdl->eng.render);
	SDL_DestroyWindow(esdl->eng.win);
	SDL_Quit();
}
