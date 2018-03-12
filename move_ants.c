/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lstlen(t_list *l)
{
	int i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

char	**lst_to_int_arr(t_list *t, t_anthill *anthill)
{
	int		len;
	int		i;
	char	**arr;

	i = 0;
	len = lstlen(t);
	arr = pr_malloc(sizeof(char *) * len);
	while (t)
	{
		arr[i++] = anthill->node_names[*(int *)t->content];
		t = t->next;
	}
	return (arr);
}

int		empty(int *arr, int len)
{
	while (len--)
	{
		if (arr[len])
			return (0);
	}
	return (1);
}

void	print_ants(t_anthill *anthill, char **path, int *ants, int path_len)
{
	int i;
	int n;
	int first;

	n = 1;
	i = 0;
	while (n <= anthill->ants || !empty(ants, path_len))
	{
		first = 1;
		i = path_len - 1;
		while (i > -1)
		{
			if (ants[i])
			{
				ft_printf("%sL%i-%s", first ? "" : " ", ants[i], path[i]);
				ants[i + 1] = ants[i];
				ants[i] = 0;
				first = 0;
			}
			i--;
		}
		ft_printf("\n");
		ants[1] = ((n <= anthill->ants) ? (n++) : ants[1]);
	}
}

void	move_ants(t_anthill *anthill)
{
	int		path_len;
	int		*ants;
	char	**path;

	anthill_printing(0, 0, 1);
	path_len = lstlen(anthill->path->first);
	ants = pr_malloc(sizeof(int) * path_len);
	ft_memset(ants, 0, sizeof(int) * path_len);
	path = lst_to_int_arr(anthill->path->first, anthill);
	print_ants(anthill, path, ants, path_len);
	pr_free(ants);
	pr_free(path);
}
