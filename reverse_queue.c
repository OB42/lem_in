/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reverse_queue(t_queue *q)
{
	int		i;
	t_list	*temp;

	if (q->first != q->last)
	{
		temp = dequeue(q);
		i = *(int *)temp->DATA;
		pr_free(temp->DATA);
		pr_free(temp);
		reverse_queue(q);
		enqueue(q, &i, sizeof(int));
	}
}
