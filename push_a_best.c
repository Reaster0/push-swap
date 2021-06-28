/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:32:28 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/28 19:14:54 by earnaud          ###   ########.fr       */
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

	i[0] = 0;
	i[1] = stack_nb(list);
	before = i[1];
	result[0] = 0;
	result[1] = 0;
	while(i[0] != stack_nb(list))
	{
		if ((list[i[0]] < value && list[before] > value) || (list[i[0]] > value && list[before] > value) || (list[i[0]] < value && list[before] < value))
			break;
																			
		index_plus(list, &before);
		i[0]++;
		result[0]++;
	}
	before = 0;
	while(i[1] != 0)
	{
		index_minus(list, &before);
		if ((list[i[1]] > value && list[before] < value) || (list[i[1]] > value && list[before] > value) || (list[i[0]] < value && list[before] < value))
			break;
		i[1]--;
		result[1]--;
	}
	return(ft_min(result));
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
	return(0);
}

long	push_best(t_stacks *stack)
{
	int i;
	int steps_a;
	int min;
	int result;
	int temp;
	int count_a_b[2];

	i = 0;
	count_a_b[1] = 0;
	min = __INT_MAX__;
	while(stack->b[i])
	{
		count_a_b[0] = count_steps(stack->a, stack->b[i]); //issue here when stack->[i] == 6
		if (count_a_b[1] > stack_nb(stack->b) / 2)
		count_a_b[1] -= stack_nb(stack->b);
		temp = best_action(count_a_b);
		if (temp < min)
		{
			result = stack->b[i];
			min = temp;
		}
		i++;
		count_a_b[1]++;
	}
	return (result);
}