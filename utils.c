/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:10:59 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 16:14:25 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	get_sorted(long *stack, long *result)
{
	int	i;

	i = 1;
	result[0] = find_next(stack, 0);
	while (i <= stack_nb(stack))
	{
		result[i] = find_next(stack, result[i - 1]);
		i++;
	}
}

int	other_than_num(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		neg;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = (str[i] == '-') * -2 + 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * neg);
}

int	error(int ret)
{
	write(STDOUT_FILENO, "Error\n", 6);
	return (ret);
}
