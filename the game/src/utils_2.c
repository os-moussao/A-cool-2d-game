/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:03:22 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/12 18:26:55 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			printf("%c", map.map[i][j]);
		printf("\n");
	}
}

t_pos	get_player_pos(t_map map)
{
	int		i;
	int		j;
	t_pos	pos;

	pos.i = -1;
	pos.j = -1;
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (map.map[i][j] == 'P')
			{
				pos.i = i;
				pos.j = j;
				return (pos);
			}
		}
	}
	return (pos);
}
