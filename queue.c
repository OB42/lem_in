/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*new_queue(void)
{
	t_queue *temp;

	temp = pr_malloc(sizeof(temp));
	*temp = (t_queue){0, 0};
	return (temp);
}

void		enqueue(t_queue *queue, void *content, int content_size)
{
	t_list *temp;

	if (!(temp = ft_lstnew(content, content_size)))
		error();
	if (!queue->first)
		*queue = (t_queue){temp, temp};
	else
	{
		queue->last->next = temp;
		queue->last = queue->last->next;
	}
}

t_list		*dequeue(t_queue *queue)
{
	t_list *temp;

	if (!queue->first || !queue->last)
		return (0);
	temp = queue->first;
	if (queue->first->next)
		queue->first = queue->first->next;
	else
		*queue = (t_queue){0, 0};
	return (temp);
}

void		free_queue(t_queue *q)
{
	ft_lstdel(&(q->first), free_content);
	pr_free(q);
}
