/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:16:42 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/08 15:57:33 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	outline_map(t_wolf *wolf)
{
	int	i;
	i = 0;
	while (++i < 24)
	{
		wolf->map[i][0] = 1;
		wolf->map[0][i] = 1;
		wolf->map[23][i] = 1;
		wolf->map[i][23] = 1;
		if (i % 3 == 0)
		{
			wolf->map[i][0] = 2;
			wolf->map[0][i] = 2;
			wolf->map[23][i] = 2;
			wolf->map[i][23] = 2;
		}
	}
}

void	maze_map(t_wolf *wolf)
{
	int i;
	i = 2;
	while (i < 8)
	{
		wolf->map[i][2] = 6;
		wolf->map[i][4] = 3;
		wolf->map[i][6] = 7;
		i = i + 2;
	}
}

void	fill_map(t_wolf *wolf)
{
	int i,j;

	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 24)
		{
			wolf->map[i][j] = 0;
			j++;
		}
		i++;
	}
	outline_map(wolf);
	maze_map(wolf);
	
	/*int x;
	int	y;
	x = 0;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			printf("%d ", wolf->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}*/
}