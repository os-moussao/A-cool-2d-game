/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:11:39 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/11 22:52:39 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 100000

# define DIM 50

# define ALLOCATION_FAILED "Error\nAllocation failed!\n"
# define MAP_ERROR "Error\nInvalid map\n"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_DESTROY		17
# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_W					13

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}				t_map;

typedef struct s_node
{
	char			*line;
	int				width;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
{
	int		len;
	t_node	*top;
	t_node	*bottom;
}				t_list;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	int		h;
	int		w;
}				t_img;

typedef struct s_assets
{
	t_img	wall;
	t_img	bg;
	t_img	coll;
	t_img	player;
	t_img	enemy;
	t_img	exit;
}				t_assets;

typedef struct s_params
{
	t_assets	assets;
	t_mlx		mlx;
	t_map		map;
}				t_params;

int			ft_strlen(char *str);
char		*ft_strchar(char *str, char c);
char		*ft_strstr(char *h, char *n);
void		ft_puterr(char *error, int use_perr);
void		clear_arr(char **arr);
void		display_map(t_map map);

char		*get_next_line(int fd);

t_list		*new_list(void);
void		push(t_list *list, char *line);
void		pop(t_list *list);
void		clear(t_list *list);

t_assets	load_images(void *mlx);
int			render_map(t_params *params);

int			key_press(int key, t_params *params);
int			close_prog(t_params *params);

#endif