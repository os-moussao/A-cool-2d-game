/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:04:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/12 19:19:55 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	load_images(void *mlx)
{
	t_assets	assets;

	assets.wall.img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm",
			&assets.wall.w, &assets.wall.h);
	assets.bg.img = mlx_xpm_file_to_image(mlx, "./assets/background.xpm",
			&assets.bg.w, &assets.bg.h);
	assets.player.img = mlx_xpm_file_to_image(mlx, "./assets/player.xpm",
			&assets.player.w, &assets.player.h);
	assets.enemy.img = mlx_xpm_file_to_image(mlx, "./assets/enemy.xpm",
			&assets.enemy.w, &assets.enemy.h);
	assets.coll.img = mlx_xpm_file_to_image(mlx, "./assets/collectible.xpm",
			&assets.coll.w, &assets.coll.h);
	assets.exit.img = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm",
			&assets.exit.w, &assets.exit.h);
	return (assets);
}

void	render_img(t_params *params, int i, int j)
{
	if (params->map.map[i][j] == '0')
		mlx_put_image_to_window(params->mlx.mlx, params->mlx.win,
			params->assets.bg.img, j * DIM, i * DIM);
	else if (params->map.map[i][j] == '1')
		mlx_put_image_to_window(params->mlx.mlx, params->mlx.win,
			params->assets.wall.img, j * DIM, i * DIM);
	else if (params->map.map[i][j] == 'C')
		mlx_put_image_to_window(params->mlx.mlx, params->mlx.win,
			params->assets.coll.img, j * DIM, i * DIM);
	else if (params->map.map[i][j] == 'P')
		mlx_put_image_to_window(params->mlx.mlx, params->mlx.win,
			params->assets.player.img, j * DIM, i * DIM);
	else if (params->map.map[i][j] == 'E')
		mlx_put_image_to_window(params->mlx.mlx, params->mlx.win,
			params->assets.exit.img, j * DIM, i * DIM);
}

int	render_map(t_params *params)
{
	int	i;
	int	j;

	i = -1;
	while (++i < params->map.height)
	{
		j = -1;
		while (++j < params->map.width)
			render_img(params, i, j);
	}
	return (0);
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
