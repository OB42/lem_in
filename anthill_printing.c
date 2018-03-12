/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/06 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_invalid_last_line(char **t)
{
	char *s;

	if (valid_last_line(-1))
		return ;
	s = ft_strchr(*t, '\n') + 1;
	while (ft_strchr(s, '\n')[1])
		s = ft_strchr(s, '\n') + 1;
	*s = 0;
}

int		anthill_printing(int fd, char **t, int print)
{
	static char	*buffer = 0;
	int			g;
	char		*temp;
	char		*tf;

	pr_free(t ? *t : 0);
	if (print && buffer)
	{
		remove_invalid_last_line(&buffer);
		write(1, buffer, ft_strlen(buffer));
		pr_free(buffer);
		buffer = 0;
		return (1);
	}
	if ((g = get_next_line(fd, t)) == 1)
	{
		tf = buffer;
		buffer = ft_strjoin(buffer ? buffer : "",
		temp = ft_strjoin(*t, "\n"));
		pr_free(tf);
		pr_free(temp);
	}
	else if (g == -1)
		error();
	return (g);
}
