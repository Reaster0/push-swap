/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:44:36 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/11 19:20:21 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void split_half(t_stacks *stack)
{
	int i;
	int median;

	median = median_value(stack->a, stack->size);
	while (i > stack->size)
	{
		if (!there_min(stack->a, median))
			break;
		if (stack->a[stack_nb(stack->a)] < median)
			switch_pb(stack, 1);
		else
			switch_ra(stack, 1);
	}
}

void second_algo(t_stacks *stack)
{
	int min_max[2];

	split_half(stack);
	find_min_max(stack->a, min_max);
	
}