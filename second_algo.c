/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:44:36 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/14 18:42:09 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Separer la pile en deux avec la médiane,
// Mettre dans la pile b du plus gros au plut petit jusqu’a épuisement
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
	while (there_max(stack->a, median))
	{
		if (stack->a[stack_nb(stack->a)] >= median)
			switch_pb(stack, 1);
		else
			switch_ra(stack, 1);
	}
}

void put_into_b(t_stacks *stack)
{
	int min_max[2];
	int i;

	print_stacks(stack);

	i = stack_nb(stack->a);
	if (!stack->a[0])
		return;
	find_min_max(stack->a, min_max);
	while (stack->a[i] != min_max[1])
		switch_ra(stack, 1); //rra or ra / need a function to decide
	switch_pb(stack, 1);
	put_into_b(stack);
}

void put_into_a(t_stacks *stack, long median)
{
	int min_max[2];
	int i;

	print_stacks(stack);

	i = stack_nb(stack->b);
	if (!stack->b[0])
		return;
	find_min_max(stack->b, min_max);
	if (min_max[1] == median)
		;//there is only sorted mini number in b
	while (stack->b[i] != min_max[1])
		switch_rrb(stack, 1); //rrb or rb / need a function to decide
	switch_pa(stack, 1);
	put_into_a(stack, median);
}

void second_algo(t_stacks *stack)
{

	split_half(stack);
	print_stacks(stack);
	put_into_b(stack);
	//maybe put all of the big numbers in b to a before
	put_into_a(stack, median_value(stack->b, stack->size));

}