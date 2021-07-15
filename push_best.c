/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:32:28 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/15 22:49:15 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// void count_price(long *list, long value, int *i, int *result)
// {
// 	int before;
// 	int min_max[2];

// 	before = i[1];
// 	find_min_max(list, min_max);
// 	while(i[0] != stack_nb(list))
// 	{
// 		if ((list[i[0]] < value && list[before] > value) || (list[i[0]] == min_max[1] && value > min_max[1]) || (list[i[0]] == min_max[1] && value < min_max[0]))
// 			break;											
// 		index_plus(list, &before);
// 		i[0]++;
// 		result[0]--;
// 	}
// 	before = 0;
// 	while(i[1] != 0)
// 	{
// 		if ((list[i[1]] > value && list[before] < value) || (list[i[1]] == min_max[0] && value > min_max[1]) || (list[i[1]] == min_max[0] && value < min_max[0]))
// 			break;
// 		index_minus(list, &before);
// 		i[1]--;
// 		result[1]++;
// 	}
// }

// int	count_steps(long *list, long value)
// {
// 	int i[2];
// 	int result[2];
// 	int before;
// 	long min_max[2];

// 	i[0] = 0;
// 	i[1] = stack_nb(list);
// 	//before = i[1];
// 	result[0] = 0;
// 	result[1] = 0;
// 	count_steps_2(list, value, i, result);
// 	find_min_max(list, min_max);
// 	while(i[0] != stack_nb(list))
// 	{
// 		if ((list[i[0]] < value && list[before] > value) || (list[i[0]] == min_max[1] && value > min_max[1]) || (list[i[0]] == min_max[1] && value < min_max[0]))
// 			break;											
// 		index_plus(list, &before);
// 		i[0]++;
// 		result[0]--;
// 	}
// 	before = 0;
// 	while(i[1] != 0)
// 	{
// 		if ((list[i[1]] > value && list[before] < value) || (list[i[1]] == min_max[0] && value > min_max[1]) || (list[i[1]] == min_max[0] && value < min_max[0]))
// 			break;
// 		index_minus(list, &before);
// 		i[1]--;
// 		result[1]++;
// 	}
// 	return(ft_min(result[0], result[1]));
//}

//fait le total d'actions pour decaller b et a 

int		best_action(int count_a, int action_b) 
{
	if (count_a > 0 && action_b > 0)
		return (ft_abs(count_a) + ft_abs(action_b) - ft_min(count_a, action_b));
	else if (count_a < 0 && action_b < 0)
		return (ft_abs(count_a) + ft_abs(action_b) + ft_max(count_a, action_b));
	else
		return(ft_abs(count_a) + ft_abs(action_b));
	return (0);
}

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

void	insertion_loop(t_stacks *stacks, long best_value, int *min_a_b)
{
	if (min_a_b[1] > 0 && min_a_b[0] > 0 || (min_a_b[1] < 0 && min_a_b[0] < 0))
	rotate_both(stacks, min_a_b);
	rotate_simple(stacks, min_a_b);
	switch_pa(stacks, 1);
}

void	set_values(long *list_a, long *sorted, int *i, long *temp_prev)
{
	i[0] = stack_nb(list_a); //index for prev
	i[1] = stack_nb(list_a) - 1; //index for temp
	i[2] = 1;				// count
	temp_prev[0] = where_in(sorted, list_a[i[1]]);
	temp_prev[1] = where_in(sorted, list_a[0]);
}

int		find_cheaper_action(long *list_a, long c_index_b, long *sorted)
{
	int i[3];
	int pos;
	long temp_prev[2];
	//int end;
	
	//end = 0;
	set_values(list_a, sorted, i, temp_prev);
	pos = 0;
	while (list_a[i[0]] && (i[2] == 1 || i[1] != stack_nb(list_a) - 1)) //!end)
	{
		//  if (i[1] == -1)
		//  {
		//  	i[1] = stack_nb(list_a);
		//  	temp_prev[0] = where_in(sorted, list_a[i[1]]);
		//  	end = 1;
		//  }
		if ((c_index_b > temp_prev[1] && c_index_b < temp_prev[0]) || (temp_prev[1] > temp_prev[0] && (c_index_b < temp_prev[0] || c_index_b > temp_prev[1])))
			pos = i[2];
		i[0]--;
		index_minus(list_a, i + 1);
		//i[1]--;
		i[2]++;
		temp_prev[0] = where_in(sorted, list_a[i[1]]);
		temp_prev[1] = where_in(sorted, list_a[i[0]]);
	}
	if (pos > stack_size(list_a) / 2)
		pos -= stack_size(list_a);
	return (pos); 
}

void	push_best(t_stacks *stack, long *sorted)
{
	int i;
	int min_a_b[2];
	int best_case;
	int temp[2];
	int count_a_b[2];
	int action_b;

	count_a_b[1] = 0;
	i = stack_nb(stack->b);
	temp[1] = __INT_MAX__;
	while(i >= 0)
	{
		count_a_b[0] = find_cheaper_action(stack->a, where_in(sorted, stack->b[i]), sorted);
		action_b = count_a_b[1];
		if (count_a_b[1] > stack_size(stack->b) / 2)
			action_b -= stack_size(stack->b);
		temp[0] = best_action(count_a_b[0], action_b);
		if (temp[0] < temp[1])
		{
			temp[1] = temp[0];
			best_case = stack->b[i];
			min_a_b[0] = count_a_b[0];
			min_a_b[1] = action_b;
		}
		i--;
		count_a_b[1]++;
	}
	insertion_loop(stack, best_case, min_a_b);
}