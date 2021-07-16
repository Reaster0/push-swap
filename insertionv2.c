/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:02:02 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 16:29:23 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_list(long *list, long size)
{
	long	i;

	i = 0;
	while (i <= size)
	{
		list[i] = 0;
		i++;
	}
}

int	long_consecutive(t_stacks *stack, int index, long *list)
{
	long	index_max;
	int		i;
	int		count;

	i = index;
	count = 0;
	index_max = 0;
	index_minus(stack->a, &i);
	while (i != index)
	{
		if (stack->a[i] >= index_max)
		{
			if (list)
			{
				if (stack_nb(list) == -1)
					list[0] = stack->a[i];
				else
					list[stack_nb(list) + 1] = stack->a[i];
			}
			index_max = stack->a[i];
			count++;
		}
		index_minus(stack->a, &i);
	}
	return (count);
}

int	long_consecutive_start(t_stacks *stack)
{
	long	max_values;
	int		index;
	long	temp;
	int		i;

	i = 0;
	index = 0;
	max_values = 0;
	while (stack->a[i])
	{
		temp = long_consecutive(stack, i, NULL);
		if (temp > max_values)
		{
			max_values = temp;
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_b_unsorted(t_stacks *stack, long *list)
{
	while (stack_nb(stack->a) > stack_nb(list))
	{
		if (where_in(list, stack->a[stack_nb(stack->a)]) == -1)
			switch_pb(stack, 1);
		else
			switch_ra(stack, 1);
	}
}

void	insertionv2(t_stacks *stack, long size)
{
	int		best_index;
	long	*list;
	long	*sorted;

	list = malloc(sizeof(long) * (stack->size + 1));
	if (!list)
		return ;
	sorted = malloc(sizeof(long) * (stack->size + 1));
	if (!sorted)
		return ;
	find_sort(stack->a, size, sorted);
	reset_list(list, size);
	best_index = long_consecutive_start(stack);
	long_consecutive(stack, best_index, list);
	push_b_unsorted(stack, list);
	while (stack->b[0])
		push_best(stack, sorted);
	while (stack->a[stack_nb(stack->a)] != find_min(stack->a))
		best_rotate_a(stack, stack_nb(stack->a), find_min(stack->a));
}
