/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:56:25 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/08 11:49:23 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void switch_rr(t_stacks *stack)
{
	write(STDOUT_FILENO, "rr\n", 3);
	switch_ra(stack, 0);
	switch_rb(stack, 0);
}

void switch_rb(t_stacks *stack, int write_it)
{
	int i;
	int temp;
	
	if (write_it)
		write(STDOUT_FILENO, "rb\n", 3);
	i = stack_nb(stack->b);
	temp = stack->b[stack_nb(stack->b)];
	while(i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
}

void switch_ra(t_stacks *stack, int write_it)
{
	int i;
	int temp;

	if (write_it)
		write(STDOUT_FILENO, "ra\n", 3);
	i = stack_nb(stack->a);
	temp = stack->a[stack_nb(stack->a)];
	while(i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
}

void switch_rrr(t_stacks *stack)
{
	write(STDOUT_FILENO, "rrr\n", 4);
	switch_rra(stack, 0);
	switch_rrb(stack, 0);
}

void switch_rrb(t_stacks *stack, int write_it)
{
	int i;
	int temp;

	if (write_it)
		write(STDOUT_FILENO, "rrb\n", 4);
	i = 0;
	temp = stack->b[0];
	while(i < stack_nb(stack->b))
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}

void switch_rra(t_stacks *stack, int write_it)
{
	int i;
	int temp;

	if (write_it)
		write(STDOUT_FILENO, "rra\n", 4);
	i = 0;
	temp = stack->a[0];
	while(i < stack_nb(stack->a))
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void switch_pb(t_stacks *stack, int write_it)
{
	if (write_it)
		write(STDOUT_FILENO, "pb\n", 3);
	if (!stack_nb(stack->a))
		return ;
	stack->b[stack_nb(stack->b) + 1] = stack->a[stack_nb(stack->a)];
	stack->a[stack_nb(stack->a)] = 0;
}

void switch_pa(t_stacks *stack, int write_it)
{
	if (write_it)
		write(STDOUT_FILENO, "pa\n", 3);
	if (!stack_nb(stack->b))
		return ;
	stack->a[stack_nb(stack->a) + 1] = stack->b[stack_nb(stack->b)];
	stack->b[stack_nb(stack->b)] = 0;
}

void switch_ss(t_stacks *stack)
{
	write(STDOUT_FILENO, "ss\n", 3);
	switch_sa(stack, 0);
	switch_sb(stack, 0);
}

void switch_sb(t_stacks *stack, int write_it)
{
	int temp;

	if (write_it)
		write(STDOUT_FILENO, "sb\n", 3);
	if (stack_nb(stack->b) <= 1)
		return ;
	temp = stack_nb(stack->b);
	stack->b[stack_nb(stack->b)] = stack->b[stack_nb(stack->b) -1];
	stack->b[stack_nb(stack->b) -1] = temp; 
}

void switch_sa(t_stacks *stack, int write_it)
{
	int temp;

	if (write_it)
		write(STDOUT_FILENO, "sa\n", 3);
	if (stack_nb(stack->a) <= 1)
		return ;
	temp = stack->a[stack->size];
	stack->a[stack->size] = stack->a[stack->size -1];
	stack->a[stack->size -1] = temp; 
}

int	stack_nb(long *stack)
{
	int i;

	i = 0;
	while(stack[i])
		i++;
	return(i);
}