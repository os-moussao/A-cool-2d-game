/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:03:22 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/10 20:06:12 by omoussao         ###   ########.fr       */
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