/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:12:28 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 21:00:48 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_values(long *list_a, long *sorted, int *i, long *temp_prev)
{
	i[0] = stack_nb(list_a);
	i[1] = stack_nb(list_a) - 1;
	i[2] = 1;
	temp_prev[0] = where_in(sorted, list_a[i[1]]);
	temp_prev[1] = where_in(sorted, list_a[0]);
}

int	find_cheaper_action(long *list_a, long c_index_b, long *sorted)
{
	int		i[3];
	int		pos;
	long	temp_prev[2];

	set_values(list_a, sorted, i, temp_prev);
	pos = 0;
	while (list_a[i[0]] && (i[2] == 1 || i[1] != stack_nb(list_a) - 1))
	{
		if ((c_index_b > temp_prev[1] && c_index_b < temp_prev[0])
			|| (temp_prev[1] > temp_prev[0] && (c_index_b < temp_prev[0]
					|| c_index_b > temp_prev[1])))
			pos = i[2];
		i[0]--;
		if (i[0] == -1)
			break;
		index_minus(list_a, i + 1);
		i[2]++;
		temp_prev[0] = where_in(sorted, list_a[i[1]]);
		temp_prev[1] = where_in(sorted, list_a[i[0]]);
	}
	if (pos > stack_size(list_a) / 2)
		pos -= stack_size(list_a);
	return (pos);
}

int	best_action(int count_a, int action_b)
{
	if (count_a > 0 && action_b > 0)
		return (ft_abs(count_a) + ft_abs(action_b) - ft_min(count_a, action_b));
	else if (count_a < 0 && action_b < 0)
		return (ft_abs(count_a) + ft_abs(action_b) + ft_max(count_a, action_b));
	else
		return (ft_abs(count_a) + ft_abs(action_b));
	return (0);
}

void	best_rotate_a(t_stacks *stack, int index, long goal)
{
	int	ij[2];
	int	index2;

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
