/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:14:34 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/25 16:12:01 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//split en deux stacks a partir du pivot
//remonter les plus petits nombres au dessus des deux pile et essayer d'opti en checkant si les deux doivent r ou rr pour le faire en meme temps
// 
//l'ordre utilisé c'est plus gros en bas et plus petit en haut

int best_rotate_ret(long *stack, int index, long goal)
{
	int ij[2];
	int index2;

	index2 = index;
	ij[0] = 0;
	ij[1] = 0;

	while (stack[index] != goal)
	{
		index--;
		ij[0]++;
		if (index == -1)
			index = stack_nb(stack);
	}
	while (stack[index2] != goal)
	{
		index2++;
		ij[1]++;
		if (index2 == stack_nb(stack) + 1)
			index2 = 0;
	}
	if (ij[0] < ij[1])
		return (R_);
	else
		return (RR_);
}

// long find_min_not_sort(long *stack)
// {
// 	long index;
// 	int min;
// 	int min_max[2];

// 	find_min_max(stack, min_max);
// 	min = *min_max;
// 	index = where_in(stack, *min_max);
// 	while (stack[index] != *min_max || min_max[1])
// 	{
// 		min_max[1] = 0;
// 		if (!index && find_next(stack, min) == stack[stack_nb(stack)])
// 			min = stack[stack_nb(stack)];
// 		else if (!index && find_next(stack, min) == stack[1])
// 			min = stack[stack_nb(stack)];
// 		else if (index == stack_nb(stack) && find_next(stack, min) == stack[stack_nb(stack) - 1])
// 			min = stack[stack_nb(stack)];
// 		else if (index == stack_nb(stack) && find_next(stack, min) == stack[0])
// 			min = stack[stack_nb(stack)];
// 		else if (index && index != stack_nb(stack) && find_next(stack, min) == stack[index + 1])  // || find_next(stack, min) == stack[index - 1]) enable it if i want to find in another order
// 			min = stack[stack_nb(stack)];
// 		else
// 			break ;
// 		index = where_in(stack, min) - 1;
// 		if (index == 0)
// 			index = stack_nb(stack);
// 	}
// 	return (min);
// }

long find_min_not_sort(long *stack)
{
	int i;
	long temp;
	long min_max[2];  // 52 and 49 are the impostor

	find_min_max(stack, min_max);
	i = where_in(stack, *min_max);
	if (i != 0 )
		temp = stack[i - 1];
	else
		temp = stack[stack_nb(stack)];
	while (temp == find_next(stack, stack[i]))
	{
		i--;
		if (i < 0)
			i = stack_nb(stack);
		if (i != 0)
			temp = stack[i - 1];
		else
			temp = stack_nb(stack);   //the bug is here
	}
	return (stack[i]);
}


// int set_min_top(long *stack)
// {
// 	int min_max[2];

// 	find_min_max(stack, min_max);
// 	if (stack[stack_nb(stack)] == min_max[0])
// 		min_max[0] == find_next(stack, min_max[0]);
// }

int	best_place(long *stack, long value, long index)
{
	long temp;
	
	if (index == -1)
		return (1);
	if (find_min(stack) == stack[index])
		return (1);
	temp = stack[index];
	index--;
	if (index == -1)
		index = stack_nb(stack);
	if (stack[index] < temp)
		return (0);
	return (best_place(stack, value, index));
}

long find_min_not_sort2(long *stack) //this one work
{
	long i;
	long min_max[2];
	long temp;

	find_min_max(stack, min_max);
	i = where_in(stack, min_max[0]);
	temp = stack[i];
	while (temp != min_max[1])
	{
		if (i == 0)
			i = stack_nb(stack);
		else 
			i--;
		if (stack[i] != find_next(stack, temp))
			break;
		temp = stack[i];
	}
	return (temp);
}

t_action action_to_sort(long *stack)
{
	long current;

	current = find_next(stack, find_min_not_sort2(stack));
	//current = find_next(stack, find_min_not_sort(stack));

	if (!best_place(stack, current, where_in(stack, current)))
	{
		if (where_in(stack, current) == stack_nb(stack) - 1)
			return (S_);
		else
			return (R_);
	}
	return(NOTHING);
}

void correct_rotate(t_stacks *stacks)
{
	while (stacks->a[stack_nb(stacks->a)] != find_min(stacks->a))
		best_rotate_a(stacks, stack_nb(stacks->a), find_min(stacks->a));
	while (stacks->b[stack_nb(stacks->b)] != find_min(stacks->b))
		best_rotate_b(stacks, stack_nb(stacks->b), find_min(stacks->b));
}

void end_of_third(t_stacks *stack)
{
	//print_stacks(stack);
	if (!stack->b[0])
		return ;
	if (stack->b[1])
		switch_rrb(stack, 1);
	switch_pa(stack, 1);
	//print_stacks(stack);
	end_of_third(stack);
}

void make_action(t_stacks *stack, t_action *action)
{
	if (action[0] == R_ && action[1] == R_)
	{
		switch_rr(stack);
		return ;
	}
	if (action[0] == S_ && action[1] == S_)
	{
		switch_ss(stack);
		return ;
	}
	if (action[0] == RR_ && action[1] == RR_)
	{
		switch_rrr(stack);
		return ;
	}
	if (action[0] == S_)
		switch_sa(stack, 1);
	else if (action[0] == R_)
		switch_ra(stack, 1);
	if (action[1] == S_)
		switch_sb(stack, 1);
	else if (action[1] == R_)
		switch_rb(stack, 1);
	if (action[0] == NOTHING && action[1]== NOTHING)
		end_of_third(stack);
}

void third_algo(t_stacks *stack)
{
	t_action action[2];
	int debug;

	debug = 0;
	split_half(stack);
	while (!check_sorted(stack))
	{
		if (debug)
			print_stacks(stack);
		action[0] = action_to_sort(stack->a);
		action[1] = action_to_sort(stack->b);
		if (action[0] == NOTHING && action[1] == NOTHING)
			correct_rotate(stack); //maybe opti there
		make_action(stack, action);
	}
}