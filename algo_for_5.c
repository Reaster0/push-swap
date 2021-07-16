/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:35:08 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 15:42:41 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_for_5(t_stacks *stack)
{
	long	min_max[2];

	if (check_sorted(stack))
		return ;
	find_min_max(stack->a, min_max);
	while (stack->a[stack_nb(stack->a)] != min_max[0])
		best_rotate_a(stack, stack_nb(stack->a), min_max[0]);
	switch_pb(stack, 1);
	find_min_max(stack->a, min_max);
	while (stack->a[stack_nb(stack->a)] != min_max[0])
		best_rotate_a(stack, stack_nb(stack->a), min_max[0]);
	switch_pb(stack, 1);
	while (stack->a[0] != min_max[1])
		best_rotate_a(stack, 0, min_max[1]);
	if (stack->a[2] > stack->a[1])
		switch_sa(stack, 1);
	switch_pa(stack, 1);
	switch_pa(stack, 1);
}
