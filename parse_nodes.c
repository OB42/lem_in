/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_node(t_anthill *anthill, char *t, int mod)
{
	t_list	*l;
	char	*tf;

	tf = 0;
	l = 0;
	if (!ft_strchr(t, ' ') || !ft_strchr(ft_strchr(t, ' ') + 1, ' ')
		|| !(tf = ft_strsub(t, 0, (int)(ft_strchr(t, ' ') - t)))
		|| !(l = ft_lstnew(tf, (1 + ft_strlen(tf)) * sizeof(char)))
		|| i_in_list(anthill->node_list, l->DATA) != -1)
		error();
	pr_free(tf);
	ft_lstadd(&(anthill->node_list), l);
	if (mod == 1)
		anthill->start = l;
	else if (mod == -1)
		anthill->end = l;
	ft_atoi_lem_in(ft_strchr(t, ' ') + 1);
	ft_atoi_lem_in(ft_strchr(ft_strchr(t, ' ') + 1, ' '));
	check_int_parsing(ft_strchr(ft_strchr(t, ' ') + 1, ' ') + 1);
}

void	parse_command(int *mod, char **t, t_anthill *anthill)
{
	if ((ft_strequ(*t, "##start") || ft_strequ(*t, "##end"))
	&& (*mod = ft_strequ(*t, "##start") ? 1 : -(ft_strequ(*t, "##end"))))
	{
		if ((*mod == 1 && anthill->start) || (*mod == -1 && anthill->end))
			error();
	}
}

void	parse_nodes(t_anthill *anthill, char **t)
{
	int mod;
	int g;

	mod = 0;
	while ((g = anthill_printing(0, t, 0)) == 1)
	{
		if (!ft_strncmp(*t, "##", 2))
			parse_command(&mod, t, anthill);
		else if (!ft_strchr("#L", *t[0]) && ft_strchr(*t, ' '))
		{
			parse_node(anthill, *t, mod);
			mod = 0;
			anthill->n++;
		}
		else if (!ft_strchr("#L", *t[0]) && ft_strchr(*t, '-'))
			break ;
		else if (*t[0] != '#')
			error();
	}
	if (!g || !anthill->ants || !anthill->n || !anthill->start || !anthill->end)
		error();
}
