/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		i_in_list(t_list *t, char *s)
{
	int i;

	i = -1;
	while (t)
	{
		i++;
		if (!ft_strcmp(t->DATA, s))
			return (i);
		t = t->next;
	}
	return (-1);
}

int		int_i_in_list(t_list *t, int n)
{
	int i;

	i = -1;
	while (t)
	{
		i++;
		if (*(int *)t->DATA == n)
			return (i);
		t = t->next;
	}
	return (-1);
}

void	ft_list_push_back(t_list **l, void *content, int content_size)
{
	t_list *temp;

	temp = *l;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = ft_lstnew(content, content_size)))
			error();
	}
	else if (!(*l = ft_lstnew(content, content_size)))
		error();
}

void	free_list(t_list *l)
{
	t_list *t;

	while (l)
	{
		t = l->next;
		pr_free(l->DATA);
		pr_free(l);
		l = t;
	}
}
