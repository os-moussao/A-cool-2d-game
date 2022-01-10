/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <omoussao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:35:29 by omoussao          #+#    #+#             */
/*   Updated: 2022/01/10 19:37:32 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->top = NULL;
	list->bottom = NULL;
	list->len = 0;
	return (list);
}

void	push(t_list *list, char *line)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		clear(list);
		free(line);
		ft_puterr(ALLOCATION_FAILED, 0);
	}
	new->line = line;
	new->width = ft_strlen(line);
	new->width -= (line[new->width - 1] == '\n');
	new->next = list->top;
	new->prev = NULL;
	if (list->top)
		list->top->prev = new;
	else
		list->bottom = new;
	list->top = new;
	(list->len)++;
}

void	pop(t_list *list)
{
	t_node	*to_free;

	to_free = list->top;
	list->top = list->top->next;
	if (list->top)
		list->top->prev = NULL;
	(list->len)--;
	free(to_free);
}

void	clear(t_list *list)
{
	while (list->len)
		pop(list);
	free(list);
}