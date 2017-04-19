/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:29:04 by qfremeau          #+#    #+#             */
/*   Updated: 2017/04/19 12:05:52 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Color	esdl_int_to_color(int color)
{
	SDL_Color	ret_color;

	ret_color.r = (color >> 24) & 0xFF;
	ret_color.g = (color >> 16) & 0xFF;
	ret_color.b = (color >> 8) & 0xFF;
	ret_color.a = (color) & 0xFF;
	return (ret_color);
}

int			esdl_color_to_int(SDL_Color color)
{
	int			ret_color;

	ret_color = 0;
	ret_color = (ret_color << 8) + color.a;
	ret_color = (ret_color << 8) + color.b;
	ret_color = (ret_color << 8) + color.g;
	ret_color = (ret_color << 8) + color.r;
	return (ret_color);
}
