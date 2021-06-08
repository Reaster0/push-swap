/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/08 14:08:29 by earnaud          ###   ########.fr       */
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
	pivot = median_value(stacks->a, stacks->size);
	while(there_min(stacks->a, pivot)) //optimization here
	{
		if (stacks->a[stack_nb(stacks->a)] < pivot)
			switch_pb(stacks, 1);
		else
			switch_ra(stacks, 1);
	}
}

void	rotate_until_push_b(t_stacks *stacks)
{
	int pivot;

	if (check_sorted(stacks) && stacks->a[stacks->size])
		return ;
	pivot = median_value(stacks->b, stacks->size);
	while(there_min(stacks->b, pivot)) //optimization here
	{
		if (stacks->b[stack_nb(stacks->b)] < pivot)
			switch_pa(stacks, 1);
		else
			switch_rb(stacks, 1);
	}
}

void	print_stacks(t_stacks *stacks)
{
	int i;
	int j;

	i = stack_nb(stacks->a);
	j = stack_nb(stacks->b);

	while (i || j)
	{
		printf("   | %ld |   | %ld |\n", stacks->a[i], stacks->b[j]);
		if (i)
			i--;
		if (j)
			j--;
	}
}

void	ft_magic(t_stacks *stacks)
{
	int min_max[2];
	if (check_sorted(stacks))
		return ;
//	rotate_until_push_a(stacks);
//	rotate_until_push_b(stacks);
	print_stacks(stacks);
	ft_magic(stacks);
}

int main(int argc, char **argv)
{

	t_stacks *stacks;
	
	if (check_error(argc, argv + 1))
		return (error(-1));
	stacks = convert_stack(argc, argv + 1);
	ft_magic(stacks);
	return (0);
}