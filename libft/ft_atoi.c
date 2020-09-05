/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldediu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:23:30 by ldediu            #+#    #+#             */
/*   Updated: 2019/09/30 10:46:07 by ldediu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		ft_atoi(const char *str)
{
	int i;
	int	answer;
	int	sign;

	i = 0;
	sign = 1;
	answer = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		answer = answer * 10 + str[i] - '0';
		i++;
	}
	return (answer * sign);
}
