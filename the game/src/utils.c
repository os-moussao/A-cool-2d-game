/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:11:15 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/09 23:33:13 by omoussao         ###   ########.fr       */
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