/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:29:11 by qfremeau          #+#    #+#             */
/*   Updated: 2017/04/19 12:05:46 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				esdl_exit(t_esdl *esdl)
{
	SDL_DestroyRenderer(esdl->eng.render);
	SDL_DestroyWindow(esdl->eng.win);
	if (esdl->ttf)
		TTF_Quit();
	SDL_Quit();
}
