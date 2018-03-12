/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2018/03/01 00:56:45 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_content(void *p, size_t useless)
{
	if (useless)
		pr_free(&((t_list *)p)->DATA);
}

void	free_anthill(t_anthill *anthill)
{
	int		i;
	t_list	*l;
	t_list	*z;

	i = 0;
	while (i < anthill->n)
	{
		pr_free(anthill->node_names[i]);
		l = anthill->adj_list[i];
		while (l)
		{
			z = l->next;
			pr_free(l->DATA);
			pr_free(l);
			l = z;
		}
		i++;
	}
	pr_free(anthill->node_names);
	pr_free(anthill->adj_list);
	ft_lstdel(&(anthill->node_list), free_content);
	free_queue(anthill->q);
	free_queue(anthill->path);
	free_queue(anthill->tagged);
}

void	get_path(t_anthill *anthill)
{
	int		end_id;

	ft_lstdelone(&anthill->temp, free_content);
	reverse_queue(anthill->path);
	anthill->temp = anthill->path->first;
	while (anthill->temp && anthill->temp->next)
	{
		if (int_i_in_list(anthill->adj_list[*(int *)
		anthill->temp->next->DATA], *(int *)anthill->temp->DATA) == -1)
		{
			anthill->adj = anthill->temp->next->next;
			ft_lstdelone(&(anthill->temp->next), free_content);
			anthill->temp->next = anthill->adj;
		}
		else
			anthill->temp = anthill->temp->next;
	}
	reverse_queue(anthill->path);
	end_id = i_in_list(anthill->node_list, anthill->end->DATA);
	enqueue(anthill->path, &end_id, sizeof(int));
	move_ants(anthill);
}

int		main(void)
{
	t_anthill	anthill;
	char		*temp_line;

	valid_last_line(1);
	skip_comments(&temp_line);
	anthill = (t_anthill){ft_atoi_lem_in(temp_line), 0, 0, 0, 0, 0, 0,
		new_queue(), new_queue(), new_queue(), 0, 0, 0};
	if (anthill.ants < 1)
		error();
	check_int_parsing(temp_line);
	parse_nodes(&anthill, &temp_line);
	init_adj_list(&anthill);
	parse_edges(&anthill, &temp_line);
	breadth_first_search(&anthill);
	free_anthill(&anthill);
	pr_free(temp_line);
	return (0);
}
