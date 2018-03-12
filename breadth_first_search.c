/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		found_end_room(t_anthill *anthill)
{
	return ((*(int *)(anthill->adj->DATA) == i_in_list(anthill->node_list,
		anthill->end->DATA)));
}

void	tag_room(t_anthill *anthill, int *room)
{
	enqueue(anthill->tagged, room, sizeof(int));
}

int		tagged(t_anthill *anthill, int *room)
{
	return (int_i_in_list(anthill->tagged->first, *room) != -1);
}

void	breadth_first_search(t_anthill *anthill)
{
	anthill->start_id = i_in_list(anthill->node_list, anthill->start->DATA);
	enqueue(anthill->q, &(anthill->start_id), SZ(anthill->start_id));
	tag_room(anthill, &(anthill->start_id));
	while (anthill->q->first)
	{
		anthill->temp = dequeue(anthill->q);
		enqueue(anthill->path, anthill->temp->DATA, anthill->temp->DATA_SIZE);
		anthill->adj = anthill->adj_list[*(int *)(anthill->temp->DATA)]->next;
		while (anthill->adj)
		{
			if (found_end_room(anthill))
				return (get_path(anthill));
			if (!tagged(anthill, anthill->adj->DATA))
			{
				enqueue(anthill->q, anthill->adj->DATA, SZ(anthill->adj->DATA));
				tag_room(anthill, anthill->adj->DATA);
			}
			anthill->adj = anthill->adj->next;
		}
		pr_free(anthill->temp->DATA);
		pr_free(anthill->temp);
	}
	error();
}
