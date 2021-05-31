/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:56:25 by earnaud           #+#    #+#             */
/*   Updated: 2021/05/31 04:00:06 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_rr(t_stacks stack)
{
	switch_ra(stack);
	switch_rb(stack);
}

void switch_rb(t_stacks stack)
{
	int i;
	int temp;

	i = 0;
	temp = stack.b[stack_nb(stack.b)];
	while(i)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[i] = temp;
}

void switch_ra(t_stacks stack)
{
	int i;
	int temp;

	i = 0;
	temp = stack.a[stack_nb(stack.a)];
	while(i)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[i] = temp;
}

void switch_rrr(t_stacks stack)
{
	switch_rra(stack);
	switch_rrb(stack);
}

void switch_rrb(t_stacks stack)
{
	int i;
	int temp;

	i = 0;
	temp = stack.b[0];
	while(i < stack_nb(stack.b))
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[i] = temp;
}

void switch_rra(t_stacks stack)
{
	int i;
	int temp;

	i = 0;
	temp = stack.a[0];
	while(i < stack_nb(stack.a))
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[i] = temp;
}

void switch_pb(t_stacks stack)
{
		if (!stack_nb(stack.a))
		return ;
	stack.b[stack_nb(stack.b) + 1] = stack.a[stack_nb(stack.a)];
	stack.a[stack_nb(stack.a)] = 0;
}

void switch_pa(t_stacks stack)
{
	if (!stack_nb(stack.b))
		return ;
	stack.a[stack_nb(stack.a) + 1] = stack.b[stack_nb(stack.b)];
	stack.b[stack_nb(stack.b)] = 0;
}

void switch_ss(t_stacks stack)
{
	switch_sa(stack);
	switch_sb(stack);
}

void switch_sb(t_stacks stack)
{
	int temp;
	if (stack_nb(stack.b) <= 1)
		return ;
	temp = stack_nb(stack.b);
	stack.b[stack_nb(stack.b)] = stack.b[stack_nb(stack.b) -1];
	stack.b[stack_nb(stack.b) -1] = temp; 
}

void switch_sa(t_stacks stack)
{
	int temp;
	if (stack_nb(stack.a) <= 1)
		return ;
	temp = stack.a[stack.size];
	stack.a[stack.size] = stack.a[stack.size -1];
	stack.a[stack.size -1] = temp; 
}

int	stack_nb(int *stack)
{
	int i;

	i = 0;
	while(stack[i])
		i++;
	return(i);
}