/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:28:59 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/07 16:32:49 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_stacks *stacks, int *min_max)
{
	int i;

	i = 1;
	min_max[0] = stacks->a[0];
	min_max[1] = stacks->a[0];
	while (stacks->a[i])
	{
		if (stacks->a[i] < min_max[0])
			min_max[0] = stacks->a[i];
		if (stacks->a[i] > min_max[1])
			min_max[1] = stacks->a[i];
		i++;
	}
}

long	find_min(long *stack)
{
	int i;
	int min;

	min = stack[0];
	i = 1;
	while(stack[i])
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

long	where_in(long *stack, int nbr)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

long	find_next(long *stack, int current)
{
	int i;
	int result;
	int next;
	
	result = 0;
	i = 0;
	while (stack[i])
	{
		next = stack[i];
		if (stack[i] > current && stack[i] <= next)
			result = stack[i];
	}
	return (result);
}

long	median_value(long *stack, int size)
{
	int	i;
	long temp[size];
	int old;

	ft_bzero(temp, size);
	i = 0;
	while (i <= size)
	{
		old = temp[i];
		i++;
		temp[i] = find_next(stack, old);
	}
	if (size % 2)
	old = size % 2;
	size = size / 2;
	return (temp[size]);
}