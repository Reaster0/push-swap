/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:44:36 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/22 13:14:01 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Separer la pile en deux avec la médiane,
// Mettre dans la pile b du plus gros au plut petit jusqu’a épuisement / non plutot du plus petit au plus gros
// Mettre dans la pile a les nombres du plus gros au plus petit que la médiane dans le bon ordre
// Puis mettre a la suite dans a tout les nombres pour finir


int		there_max(long *stack, long pivot)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] >= pivot)
			return (1);
		i++;
	}
	return (0);
}

void split_half(t_stacks *stack)
{
	int i;
	int median;

	i = 0;
	median = median_value(stack->a, stack->size);
	while (there_min(stack->a, median))
	{
		if (stack->a[stack_nb(stack->a)] < median)
			switch_pb(stack, 1);
		else
			best_rotate_split(stack, stack_nb(stack->a), median);
	}
}

void best_rotate_b(t_stacks *stack, int index, long goal)
{
	int ij[2];
	int index2;

	index2 = index;
	ij[0] = 0;
	ij[1] = 0;

	//print_stacks(stack);
	
	while (stack->b[index] != goal)
	{
		index--;
		ij[0]++;
		if (index == -1)
			index = stack_nb(stack->b);
	}
	while (stack->b[index2] != goal)
	{
		index2++;
		ij[1]++;
		if (index2 == stack_nb(stack->b) + 1)
			index2 = 0;
	}
	if (ij[0] < ij[1])
		switch_rb(stack, 1);
	else
		switch_rrb(stack, 1);	
}

void best_rotate_split(t_stacks *stack, int index, long median)
{
	int ij[2];
	int index2;

	index2 = index;
	ij[0] = 0;
	ij[1] = 0;

	while (stack->a[index] < median)
	{
		index--;
		ij[0]++;
		if (index == -1)
			index = stack_nb(stack->a);
	}
	while (stack->a[index2] < median)
	{
		index2++;
		ij[1]++;
		if (index2 == stack_nb(stack->a) + 1)
			index2 = 0;
	}
	if (ij[0] < ij[1])
		switch_ra(stack, 1);
	else
		switch_rra(stack, 1);	
}

void best_rotate_a(t_stacks *stack, int index, long goal)
{
	int ij[2];
	int index2;

	index2 = index;
	ij[0] = 0;
	ij[1] = 0;

	while (stack->a[index] != goal)
	{
		index--;
		ij[0]++;
		if (index == -1)
			index = stack_nb(stack->a);
	}
	while (stack->a[index2] != goal)
	{
		index2++;
		ij[1]++;
		if (index2 == stack_nb(stack->a) + 1)
			index2 = 0;
	}
	if (ij[0] < ij[1])
		switch_ra(stack, 1);
	else
		switch_rra(stack, 1);	
}

void put_into_b(t_stacks *stack)
{
	long min_max[2];
	int i;

	//print_stacks(stack);
	i = stack_nb(stack->a);
	if (!stack->a[0])
		return;
	find_min_max(stack->a, min_max);
	while (stack->a[i] != min_max[0])
		best_rotate_a(stack, i, min_max[0]); //rra or ra / need a function to decide
	switch_pb(stack, 1);
	put_into_b(stack);
}

void put_into_a(t_stacks *stack, long median)
{
	long min_max[2];
	int i;

	//print_stacks(stack);

	i = stack_nb(stack->b);
	if (!stack->b[0])
		return;
	find_min_max(stack->b, min_max);
	//if (min_max[1] == median)
	//	;//there is only sorted mini number in b
	while (stack->b[i] != min_max[1])
		best_rotate_b(stack, i, min_max[1]); //rrb or rb / need a function to decide
	switch_pa(stack, 1);
	put_into_a(stack, median);
}

void second_algo(t_stacks *stack)
{

	split_half(stack);
	//print_stacks(stack);
	put_into_b(stack);
	//maybe put all of the big numbers in b to a before/ okay done
	put_into_a(stack, median_value(stack->b, stack->size));

}