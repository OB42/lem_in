/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_adj_list(t_anthill *anthill)
{
	int		i;
	t_list	*t;

	i = 0;
	t = anthill->node_list;
	anthill->adj_list = pr_malloc(sizeof(t_list *) * anthill->n);
	anthill->node_names = pr_malloc(sizeof(char *) * anthill->n);
	while (t)
	{
		if (!(anthill->adj_list[i] = ft_lstnew(&i, sizeof(int))))
			error();
		anthill->node_names[i] = ft_strdup(t->DATA);
		i++;
		t = t->next;
	}
}

void	pr_free_char_arr(char **to_free, int len)
{
	while (len--)
		pr_free(to_free[len]);
}

int		parse_edges(t_anthill *anthill, char **t)
{
	static int	g = 1;
	char		*sa;
	char		*sb;
	int			a;
	int			b;

	while (g == 1)
	{
		if (*t[0] != '#')
		{
			if (!ft_strchr(*t, '-'))
				return (valid_last_line(0));
			if (!(sa = ft_strsub(*t, 0, (int)((ft_strchr(*t, '-') - *t))))
			|| !(sb = ft_strdup(ft_strchr(*t, '-') + 1)))
				error();
			else if ((a = i_in_list(anthill->node_list, sa)) == -1
			|| (b = i_in_list(anthill->node_list, sb)) == -1)
				return (valid_last_line(0));
			ft_list_push_back(&(anthill->adj_list[a]), &b, sizeof(b));
			ft_list_push_back(&(anthill->adj_list[b]), &a, sizeof(a));
			pr_free_char_arr((char *[]){sa, sb}, 2);
		}
		g = anthill_printing(0, t, 0);
	}
	return (0);
}
