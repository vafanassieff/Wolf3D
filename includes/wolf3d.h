/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:06:18 by vafanass          #+#    #+#             */
/*   Updated: 2017/04/19 17:31:29 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

#include "global.h"
#include "libesdl.h"
#include "libft.h"

typedef	struct		s_wolf
{
	t_esdl			*esdl;
	SDL_Surface		*surf;
	SDL_Rect		*rect;
	SDL_Texture		*text;
}					t_wolf;



#endif