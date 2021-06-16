/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:11:24 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/16 12:48:22 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
void split_array(long *stack, long **split_stack)
{
	int ij[2];

	ij[0] = 0;
	ij[1] = 0;
	split_stack[0] = malloc(sizeof(stack) * 32);
	split_stack[1] = malloc(sizeof(stack) * 32);

	ij[0] = sizeof(stack);
	//while(ij[0] < sizeof())
	
}

void algo_merge(t_stacks *stack)
{
	int min_max[2];
	long *split_stack[2];

	find_min_max(stack->a, min_max);
	split_array(stack->a, split_stack);
}