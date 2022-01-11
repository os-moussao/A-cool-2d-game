/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:04:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/11 16:57:44 by omoussao         ###   ########.fr       */
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
	return (assets);
}

void	render_map(t_assets assets, t_map map, t_mlx mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			mlx_put_image_to_window(mlx.mlx, mlx.win,
				assets.bg.img, j * DIM, i * DIM);
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					assets.wall.img, j * DIM, i * DIM);
			else if (map.map[i][j] == 'C')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					assets.coll.img, j * DIM, i * DIM);
			else if (map.map[i][j] == 'P')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					assets.player.img, j * DIM, i * DIM);
			else if (map.map[i][j] == 'E')
				mlx_put_image_to_window(mlx.mlx, mlx.win,
					assets.enemy.img, j * DIM, i * DIM);
		}
	}
}
