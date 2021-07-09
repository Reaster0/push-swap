/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:32:28 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/09 18:22:52 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int ft_min(int *duo)
{
	if (ft_abs(duo[0]) < ft_abs(duo[1]))
		return (duo[0]);
	return (duo[1]);
}

int ft_max(int *duo)
{
	if (ft_abs(duo[0]) > ft_abs(duo[1]))
		return (duo[0]);
	return (duo[1]);
}

// compte le nombre de steps pour mettre b dans a
//    |  0|   | 43|
//    |  0|   | 95|
//    |  0|   | 32|
//    |124|   |101|
//    |125|   | 22|
//    |126|   |105|
//    |132|   | 36|
//    |141|   |106|
//    |145|   | 55|
//    | 14|   | 49|
//    | 85|   | 47|
//    |100|   | 62|
//    |121|   | 51|
//fix the case max and min value for both if
int	count_steps(long *list, long value)
{
	int i[2];
	int result[2];
	int before;
	long min_max[2];

	i[0] = 0;
	i[1] = stack_nb(list);
	before = i[1];
	result[0] = 0;
	result[1] = 0;
	find_min_max(list, min_max);
	while(i[0] != stack_nb(list))
	{
		if ((list[i[0]] < value && list[before] > value) || (list[i[0]] == min_max[1] && value > min_max[1]) || (list[i[0]] == min_max[1] && value < min_max[0]))
			break;											
		index_plus(list, &before);
		i[0]++;
		result[0]++;
	}
	before = 0;
	while(i[1] != 0)
	{
		if ((list[i[1]] > value && list[before] < value) || (list[i[1]] == min_max[0] && value > min_max[1]) || (list[i[1]] == min_max[0] && value < min_max[0]))
			break;
		index_minus(list, &before);
		i[1]--;
		result[1]--; //maybe don't minus so i don't need to use abs later
	}
	return(ft_min(result));
}

int		where_to_insert(long *list, long value)
{
	int i[3];
	int pos;

	i[0] = 0;
	i[1] = stack_nb(list);
	i[2] = 1;
	pos = 0;
	while (list[i[0]])
	{
		if ((value > list[i[1]] && value < list[i[0]]) || (list[i[1]] > list[i[0]] && (value < list[i[0]] || value > list[i[1]])))
		pos = i[2];
		i[0]++;
		index_plus(list, i + 1);
		i[2]++;
	}
	if (pos > stack_nb(list) / 2)
		pos -= stack_nb(list);
	return (pos); 
}

// int		count_steps(long *list, long value)
// {
// 	int i[2];
// 	int before;
// 	int steps;

// 	i[0] = 0;
// 	i[1] = 1;
// 	steps = 0;
// 	before = i[0];
// 	index_minus(list, &before);
// 	while(list[i[0]] && before)
// 	{
// 		if ((value > list[before] && value < list[i[0]]) || (list[before] > list[i[0]] && value < list[i[0]] || value > list[before]))
// 			steps = i[1];
		
// 		i[0]++;
// 		before++;
// 		i[1]++;
// 	}
// 	if (steps > stack_nb(list) / 2)
// 		steps -= stack_nb(list);
// 	return (steps);
// }


//fait le total d'actions pour decaller b et a 
int		best_action(int *count_a_b) 
{
	if (count_a_b[0] > 0 && count_a_b[1] > 0)
		return (ft_abs(count_a_b[0]) + ft_abs(count_a_b[1] - ft_min(count_a_b)));
	else if (count_a_b[0] < 0 && count_a_b[1] < 0)
		return (ft_abs(count_a_b[0]) + ft_abs(count_a_b[1]) + ft_max(count_a_b));
	else
		return(ft_abs(count_a_b[0]) + ft_abs(count_a_b[1]));
	return (0);
}


void	rotate_both(t_stacks *stack, int *min_a_b)
{
	while (min_a_b[0] > 0 && min_a_b[1] > 0)
	{
		switch_rrr(stack);
		min_a_b[0]--;
		min_a_b[1]--;
	}
	while (min_a_b[0] < 0 && min_a_b[1] < 0)
	{
		switch_rr(stack);
		min_a_b[0]++;
		min_a_b[1]++;
	}
}

void	rotate_simple(t_stacks *stack, int *min_a_b)
{
	while (min_a_b[0] > 0)
	{
		switch_rra(stack, 1);
		min_a_b[0]--;
	}
	while (min_a_b[0] < 0)
	{
		switch_ra(stack, 1);
		min_a_b[0]++;
	}
	while (min_a_b[1] > 0)
	{
		switch_rrb(stack, 1);
		min_a_b[1]--;
	}
	while (min_a_b[1] < 0)
	{
		switch_rb(stack, 1);
		min_a_b[1]++;
	}
}

void	insertion_loop(t_stacks *stacks, long best_value, int *min_a_b)
{
	int debug = 0;

	if (min_a_b[1] > 0 && min_a_b[0] > 0 || (min_a_b[1] < 0 && min_a_b[0] < 0))
	rotate_both(stacks, min_a_b);
	rotate_simple(stacks, min_a_b);
	if (debug)
		print_stacks(stacks);
	switch_pa(stacks, 1);
}

void	push_best(t_stacks *stack)
{
	int i;
	int min_a_b[2];
	int result;
	int temp[2];
	int count_a_b[2];
	//int osef;

	i = 0;
	count_a_b[1] = 0;
	temp[1] = __INT_MAX__;
	while(stack->b[i])
	{
		count_a_b[0] = where_to_insert(stack->a, stack->b[i]);
		//osef = count_steps(stack->a, stack->b[i]);
		//count_a_b[0] = count_steps(stack->a, stack->b[i]);
		if (count_a_b[1] > stack_nb(stack->b) / 2)
		count_a_b[1] -= stack_nb(stack->b);
		temp[0] = best_action(count_a_b);
		if (temp[0] < temp[1])
		{
			temp[1] = temp[0];
			result = stack->b[i];
			min_a_b[0] = count_a_b[0];
			min_a_b[1] = count_a_b[1];
		}
		i++;
		count_a_b[1]++;
	}
	if (min_a_b[1] >=0 && result != stack->b[stack_nb(stack->b)])
		min_a_b[1]++;
	insertion_loop(stack, result, min_a_b);
}