/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:11:39 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/10 20:10:05 by omoussao         ###   ########.fr       */
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

# define ALLOCATION_FAILED "Error\nAllocation failed!\n"
# define MAP_ERROR "Error\nInvalid map\n"

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

int		ft_strlen(char *str);
char	*ft_strchar(char *str, char c);
char	*ft_strstr(char *h, char *n);
void	ft_puterr(char *error, int use_perr);
void	clear_arr(char **arr);
void	display_map(t_map map);

char	*get_next_line(int fd);

t_list	*new_list(void);
void	push(t_list *list, char *line);
void	pop(t_list *list);
void	clear(t_list *list);

#endif