/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:13:47 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/13 11:33:56 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void esdl_fps_limit_delay(t_esdl *esdl, const UINT framelimit)
{
  UINT ticks;
  int max;

  ticks = SDL_GetTicks();
  max = (1000 / esdl->fps.limit);
  if (framelimit < ticks)
    return;
  if (framelimit > ticks + max)
    SDL_Delay(max);
  else
    SDL_Delay(framelimit - ticks);
}

void esdl_fps_counter(t_esdl *esdl)
{
  if ((esdl->fps.update = SDL_GetTicks()) - esdl->fps.current >= 1000)
  {
    esdl->fps.current = esdl->fps.update;
    SDL_SetWindowTitle(esdl->eng.win, ft_itoa(esdl->fps.fps));
    esdl->fps.fps = 0;
  }
  ++(esdl->fps.fps);
}

void esdl_fps_limit(t_esdl *esdl)
{
  esdl_fps_limit_delay(esdl, esdl->fps.framelimit);
  esdl->fps.framelimit = SDL_GetTicks() + (1000 / esdl->fps.limit);
  esdl_fps_counter(esdl);
}