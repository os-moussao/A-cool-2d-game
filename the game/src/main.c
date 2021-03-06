/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:07:43 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/12 20:42:43 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_file(int ac, char **av)
{
	char	*tmp;
	int		fd;

	if (ac != 2)
	{
		write(2, "Usage: ./so_long <map>\n", 23);
		exit(1);
	}
	tmp = ft_strstr(av[1], ".ber");
	if (!tmp || tmp[4])
	{
		write(2, "Error\nEnter a .ber file\n", 25);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_puterr(av[1], 1);
	return (fd);
}

int	validate_map(t_map *map)
{
	int		e;
	int		p;
	int		i;
	int		j;

	map->coll = 0;
	e = 0;
	p = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (!ft_strchar("01CEP", map->map[i][j]) || ((i == 0
				|| i == map->height - 1 || j == 0 || j == map->width - 1)
					&& map->map[i][j] != '1'))
				return (0);
			map->coll += map->map[i][j] == 'C';
			e += map->map[i][j] == 'E';
			p += map->map[i][j] == 'P';
		}
	}
	return (map->coll >= 1 && e >= 1 && p == 1);
}

t_map	list_to_map(t_list *list)
{
	t_map	map;
	t_node	*tmp;
	int		i;

	if (list->len < 3 || list->top->width < 3)
	{
		clear(list);
		ft_puterr(MAP_ERROR, 0);
	}
	map.map = malloc(((map.height = list->len) + 1) * sizeof(char *));
	if (!map.map)
	{
		clear(list);
		ft_puterr(ALLOCATION_FAILED, 0);
	}
	map.width = list->top->width;
	i = 0;
	tmp = list->bottom;
	while (tmp)
	{
		map.map[i++] = tmp->line;
		tmp = tmp->prev;
	}
	map.map[i] = NULL;
	return (clear(list), map);
}

t_map	parse_map(int fd)
{
	char	*line;
	t_list	*list;
	t_map	map;

	list = new_list();
	if (!list)
		ft_puterr(ALLOCATION_FAILED, 0);
	line = get_next_line(fd);
	while (line)
	{
		push(list, line);
		if (list->top->next && list->top->width != list->top->next->width)
		{
			clear(list);
			ft_puterr(MAP_ERROR, 0);
		}
		line = get_next_line(fd);
	}
	map = list_to_map(list);
	if (!validate_map(&map))
	{
		clear_arr(map.map);
		ft_puterr(MAP_ERROR, 0);
	}
	return (map);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_mlx		mlx;
	t_assets	assets;
	t_params	params;

	map = parse_map(get_file(ac, av));
	map.player_pos = get_player_pos(map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map.width * DIM,
			map.height * DIM, "so_long!");
	assets = load_images(mlx.mlx);
	params.assets = assets;
	params.map = map;
	params.mlx = mlx;
	render_map(&params);
	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, &params);
	mlx_hook(mlx.win, X_EVENT_DESTROY, 0, close_prog, &params);
	mlx_loop(mlx.mlx);
}
