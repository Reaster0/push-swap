/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:28:59 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/08 16:07:52 by earnaud          ###   ########.fr       */
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
		if (stack[i] > current && (!result || stack[i] < result))
		result = stack[i];
		i++;
	}
	return (result);
}

void	find_sort(long *stack, int size, long *sorted)
{
	int i;
	int old;

	i = 0;
	old = 0;
	while (i <= size)
	{
		sorted[i] = find_next(stack, old);
		old = sorted[i];
		i++;
	}
}

long	median_value(long *stack, int size)
{
	int	i;
	long temp[size + 1];
	int old;

	i = 0;
	old = 0;
	find_sort(stack, size, temp);
	if (size % 2)
	{
		size = size / 2;
		size++;
	}
	else
		size = size / 2;
	return (temp[size]);
}

int	check_sorted(t_stacks *stacks)
{
	int i;
	long sorted[stacks->size];

	i = 0;
	if (stacks->b[0])
		return(0);
	find_sort(stacks->a, stacks->size, sorted);
	while (stacks->a[i] && sorted[i])
	{
		if (stacks->a[i] != sorted[i])
			return(0);
		i++;
	}
	return (1);
}
