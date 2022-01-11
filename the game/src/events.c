/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:10:34 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/11 22:54:57 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_prog(t_params *params)
{
	mlx_destroy_window(params->mlx.mlx, params->mlx.win);
	clear_arr(params->map.map);
	exit(0);
	return (0);
}

int	key_press(int key, t_params *params)
{
	printf("%d\n", key);
	if (key == KEY_ESC)
		close_prog(params);
	return (0);
}
