/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:32:28 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 20:08:18 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stacks *stack, int *min_a_b)
{
	while (min_a_b[0] > 0 && min_a_b[1] > 0)
	{
		switch_rr(stack);
		min_a_b[0]--;
		min_a_b[1]--;
	}
	while (min_a_b[0] < 0 && min_a_b[1] < 0)
	{
		switch_rrr(stack);
		min_a_b[0]++;
		min_a_b[1]++;
	}
}

void	rotate_simple(t_stacks *stack, int *min_a_b)
{
	while (min_a_b[0] > 0)
	{
		switch_ra(stack, 1);
		min_a_b[0]--;
	}
	while (min_a_b[0] < 0)
	{
		switch_rra(stack, 1);
		min_a_b[0]++;
	}
	while (min_a_b[1] > 0)
	{
		switch_rb(stack, 1);
		min_a_b[1]--;
	}
	while (min_a_b[1] < 0)
	{
		switch_rrb(stack, 1);
		min_a_b[1]++;
	}
}

void	insertion_loop(t_stacks *stacks, int *min_a_b)
{
	if ((min_a_b[1] > 0 && min_a_b[0] > 0)
		|| (min_a_b[1] < 0 && min_a_b[0] < 0))
		rotate_both(stacks, min_a_b);
	rotate_simple(stacks, min_a_b);
	switch_pa(stacks, 1);
}

void	set_var(int *temp, int *min_a_b_best, int *count_a_b_b2, int best_value)
{
	temp[1] = temp[0];
	min_a_b_best[2] = best_value;
	min_a_b_best[0] = count_a_b_b2[0];
	min_a_b_best[1] = count_a_b_b2[2];
}

void	push_best(t_stacks *stack, long *sorted)
{
	int	i;
	int	min_a_b_best[3];
	int	temp[2];
	int	count_a_b_b2[3];

	count_a_b_b2[1] = 0;
	i = stack_nb(stack->b);
	temp[1] = __INT_MAX__;
	while (i >= 0)
	{
		count_a_b_b2[0] = find_cheaper_action(stack->a,
				where_in(sorted, stack->b[i]), sorted);
		count_a_b_b2[2] = count_a_b_b2[1];
		if (count_a_b_b2[1] > stack_size(stack->b) / 2)
			count_a_b_b2[2] -= stack_size(stack->b);
		temp[0] = best_action(count_a_b_b2[0], count_a_b_b2[2]);
		if (temp[0] < temp[1])
			set_var(temp, min_a_b_best, count_a_b_b2, stack->b[i]);
		i--;
		count_a_b_b2[1]++;
	}
	insertion_loop(stack, min_a_b_best);
}
