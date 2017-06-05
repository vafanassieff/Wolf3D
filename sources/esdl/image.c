/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:57:18 by qfremeau          #+#    #+#             */
/*   Updated: 2017/06/05 13:29:55 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					esdl_init_img(t_esdl *esdl)
{
	int		ret;

	ret = 0;
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == -1)
	{
		ret = -1;
	}
	esdl->img = 1;
	return (ret);
}
