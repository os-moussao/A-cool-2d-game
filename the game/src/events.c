/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:10:34 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/12 19:14:37 by omoussao         ###   ########.fr       */
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

void	mv_player(int key, t_params *params)
{
	int			i;
	int			j;
	t_pos		old;
	bool		change;
	static int	moves;

	change = 0;
	old = params->map.player_pos;
	i = old.i + (key == KEY_S) - (key == KEY_W);
	j = old.j + (key == KEY_D) - (key == KEY_A);
	if (params->map.map[i][j] == '0' || params->map.map[i][j] == 'C')
		change = 1;
	if (params->map.map[i][j] == 'C')
		(params->map.coll)--;
	if (params->map.map[i][j] == 'E' && params->map.coll == 0)
		close_prog(params);
	if (change)
	{
		params->map.map[old.i][old.j] = '0';
		params->map.map[i][j] = 'P';
		params->map.player_pos.i = i;
		params->map.player_pos.j = j;
		printf("Moves: %d\n", ++moves);
		render_map(params);
	}
}

int	key_press(int key, t_params *params)
{
	if (key == KEY_ESC)
		close_prog(params);
	if (key == KEY_W || key == KEY_A || key == KEY_D || key == KEY_S)
		mv_player(key, params);
	return (0);
}
