/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:07:43 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/09 23:38:04 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_file(int ac, char **av)
{
    char    *tmp;
    int     fd;

    if (ac != 2)
    {
        write(2, "Usage: ./so_long <map>\n", 23);
        exit(1);
    }
    tmp = ft_strstr(av[0], ".ber");
    if (!tmp || tmp[4])
    {
        write(2, "Error: enter a .ber file\n", 25);
        exit(1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        ft_puterr(av[1], 1);
    return (fd);
}

char    **parse_map(int fd)
{
    char    **map;
    // parse file
}

int main(int ac, char **av)
{
    char    **map;
    
    map = parse_map(get_file(ac, av));
}