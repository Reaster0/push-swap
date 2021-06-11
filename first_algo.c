/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:42:54 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/11 18:44:20 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		there_min(long *stack, long pivot)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] < pivot)
			return (1);
		i++;
	}
	return (0);
}

void	rotate_until_push_a(t_stacks *stacks)
{
	int pivot;

	if (check_sorted(stacks) && stacks->a[stacks->size])
		return ;
	pivot = median_value(stacks->a, stack_nb(stacks->a));
	while(there_min(stacks->a, pivot)) //optimization here
	{
		if (stacks->a[stack_nb(stacks->a)] < pivot)
			switch_pb(stacks, 1);
		else
			switch_ra(stacks, 1);
		print_stacks(stacks);
	}
}

void	rotate_until_push_b(t_stacks *stacks)
{
	int pivot;

	if (check_sorted(stacks) && stacks->a[stacks->size])
		return ;
	pivot = median_value(stacks->b, stack_nb(stacks->b));
	while(there_min(stacks->b, pivot)) //optimization here
	{
		if (stacks->b[stack_nb(stacks->b)] < pivot)
			switch_pa(stacks, 1);
		else
			switch_rb(stacks, 1);
		print_stacks(stacks);
	}
}

void	first_algo(t_stacks *stacks)
{
	if (check_sorted(stacks))
		return ;
	rotate_until_push_a(stacks);
	rotate_until_push_b(stacks);
}