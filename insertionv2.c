/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:02:02 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/25 01:02:57 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//trouver la plus grosse suite de nombre eparse danse la liste a et mettre tout le reste dans b, puis insertion sort into a

void index_minus(long *stack, int*index)
{
	(*index)--;
	if (*index > stack_nb(stack))
		*index = 0;
	else if (*index < 0)
		*index = stack_nb(stack);
}

// int is_in_suite(long *stack, long value, long index)
// {
// 	int ret;

// 	ret = 0;
// 	index++;
// 	fix_index(stack, &index);
// 	index -= 2;
// 	fix_index(stack, &index);
// 	if (stack[index] > value)
// 		ret++;
// 	if (ret == 2)
// 		return (1);
// 	return (0);
// }

// int there_only_suites(long *stack)
// {
// 	int i;

// 	i = 0;
// 	while (stack[i])
// 	{
// 		if (!is_in_suite(stack, stack[i], i))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void put_unsorted_b(t_stacks *stack)
// {
// 	int debug = 1;
	
// 	while (!there_only_suites(stack->a))
// 	{
// 		if (debug)
// 			print_stacks(stack);
// 		if (!is_in_suite(stack->a, stack->a[stack_nb(stack->a)], stack_nb(stack->a)))
// 			switch_pb(stack, 1);
// 		else
// 			switch_ra(stack, 1);
// 	}
// }
void reset_list(long *list, long size)
{
	long i;

	i = 0;
	while(i <= size)
	{
		list[i] = 0;
		i++;
	}
}

void copy_list(long *dest, long *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void copy_one(long *list, long nbr)
{
	if (stack_nb(list) == -1)
		list[0] = nbr;
	else
		list[stack_nb(list) + 1] = nbr;
}


// int	big_epars_list(t_stacks *stack, long *result, int index)
// {
// 	int i;
// 	int j;

// 	j = index;
// 	index_minus(stack->a, &j);
// 	i = 0;
// 	reset_list(result, stack->size);
// 	copy_one(result, stack->a[j]);
// 	index_minus(stack->a, &j);
// 	while (j != index)
// 	{
// 		if (stack->a[j] > result[stack_nb(result)])
// 		{
// 			copy_one(result, stack->a[j]);
// 			i++;
// 		}
// 		index_minus(stack->a, &j);
// 	}
// 	return (i);
// }

int long_consecutive(t_stacks *stack, int index, long *list)
{
	long index_max;
	int i;
	int count;

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

int long_consecutive_start(t_stacks *stack)
{
	long max_values;
	int index;
	long temp;
	int i;

	i = 0;
	index = 0;
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

void push_b_unsorted(t_stacks *stack, long *list)
{
	int i;

	i = stack_nb(stack->a);
	while (stack_nb(stack->a) > stack_nb(list))
	{
		if (where_in(list, stack->a[stack_nb(stack)]) == -1)
			switch_pb(stack, 1);
		else
		{
			
		}
	}
}

void insertionv2(t_stacks *stack, long size)
{
	int best_index;
	long list[size];
	
	reset_list(list, size);
	best_index = long_consecutive_start(stack);
	long_consecutive(stack, best_index, list);
	push_b_unsorted(stack, list);
	//print_list(list);
}