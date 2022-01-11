/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:04:17 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/10 23:56:29 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_assets	load_images(void *mlx)
{
	t_assets	assets;

	assets.wall.img = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &assets.wall.w, &assets.wall.h);
	assets.background.img = mlx_xpm_file_to_image(mlx, "./assets/background.xpm", &assets.background.w, &assets.background.h);
	assets.player.img = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &assets.player.w, &assets.player.h);
	assets.enemy.img = mlx_xpm_file_to_image(mlx, "./assets/enemy.xpm", &assets.enemy.w, &assets.enemy.h);
	assets.collectible.img = mlx_xpm_file_to_image(mlx, "./assets/collectible.xpm", &assets.collectible.w, &assets.collectible.h);
	return (assets);
}

void	render_map(t_assets assets, t_map map, t_mlx mlx)
{
	int		i;
	int		j;
	char	c;
	
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			c = map.map[i][j];
			// printf("%d %d\n", assets.enemy.h, assets.enemy.w);
			if (c == '0')
			 	mlx_put_image_to_window(mlx.mlx, mlx.win, assets.background.img, j * DIM, i * DIM);
			else if (c == '1')
				mlx_put_image_to_window(mlx.mlx, mlx.win, assets.wall.img, j * DIM, i * DIM);
			else if (c == 'C')
				mlx_put_image_to_window(mlx.mlx, mlx.win, assets.collectible.img, j * DIM, i * DIM);
			else if (c == 'P')
				mlx_put_image_to_window(mlx.mlx, mlx.win, assets.player.img, j * DIM, i * DIM);
			else if (c == 'E')
				mlx_put_image_to_window(mlx.mlx, mlx.win, assets.enemy.img, j * DIM, i * DIM);
		}
	}
}