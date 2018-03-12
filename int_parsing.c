/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenazzo <obenazzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:54:33 by obenazzo          #+#    #+#             */
/*   Updated: 2017/11/08 10:54:40 by obenazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_int_parsing(char *s)
{
	if (ft_strchr("+-", *s))
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		error();
}

int		ft_atoi_lem_in(const char *str)
{
	int			i;
	long long	nb;
	int			sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = *str == '-' ? -1 : 1;
	if (ft_strchr("+-", *str))
		str++;
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb * sign < -2147483648 || nb > 2147483647)
			error();
		i++;
	}
	if (!i || !(str[i] == ' ' || !str[i]))
		error();
	return (nb * sign);
}
