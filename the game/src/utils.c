/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:11:15 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/10 19:29:55 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char	*ft_strchar(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}

char    *ft_strstr(char *h, char *n)
{
    int i;
	int j;

	if (!*n)
		return (h);
	i = -1;
	while (h[++i])
	{
		j = -1;
		while (n[++j] && h[i + j])
		{
			if (n[j] != h[i + j])
				break ;
		}
		if (!n[j])
			return (h + i);
	}
	return (NULL);
}

void    ft_puterr(char *error, int use_perr)
{
    if (use_perr)
        perror(error);
    else
    {
        while (*error)
            write(2, error++, 1);
    }
    exit(1);
}

void	clear_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}