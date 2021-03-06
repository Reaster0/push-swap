/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:28:59 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/23 17:16:30 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	where_in(long *stack, long nbr)
{
	int	i;

	i = 0;
	while (stack[i] != END_STACK)
	{
		if (stack[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

long	find_next(long *stack, long current)
{
	int		i;
	long	result;

	result = -2147483649;
	i = 0;
	while (stack[i] != END_STACK)
	{
		if (stack[i] > current && (result == -2147483649 || stack[i] < result))
			result = stack[i];
		i++;
	}
	return (result);
}

void	find_sort(long *stack, int size, long *sorted)
{
	int		i;
	long	old;

	i = 0;
	old = -2147483649;
	while (i < size)
	{
		sorted[i] = find_next(stack, old);
		old = sorted[i];
		i++;
	}
}

int	check_sorted(t_stacks *stacks)
{
	int		i;
	int		j;
	long	*sorted;

	i = 0;
	j = stack_nb(stacks->a);
	if (stacks->b[0] != END_STACK)
		return (0);
	sorted = malloc(sizeof(long) * (stacks->size + 1));
	find_sort(stacks->a, stacks->size, sorted);
	while (j >= 0 && stacks->a[j] != END_STACK && sorted[i] != END_STACK)
	{
		if (stacks->a[j] != sorted[i])
		{
			free(sorted);
			return (0);
		}
		i++;
		j--;
	}
	free(sorted);
	return (1);
}
