/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:42:43 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/20 14:03:29 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_rra(t_stacks *stack, int write_it)
{
	int	i;
	int	temp;

	if (write_it)
		write(STDOUT_FILENO, "rra\n", 4);
	i = 0;
	temp = stack->a[0];
	while (i < stack_nb(stack->a))
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void	switch_pb(t_stacks *stack, int write_it)
{
	if (write_it)
		write(STDOUT_FILENO, "pb\n", 3);
	if (stack_nb(stack->a) == -1)
		return ;
	stack->b[stack_size(stack->b)] = stack->a[stack_nb(stack->a)];
	stack->a[stack_nb(stack->a)] = END_STACK;
}

void	switch_pa(t_stacks *stack, int write_it)
{
	if (write_it)
		write(STDOUT_FILENO, "pa\n", 3);
	if (stack_nb(stack->b) == -1)
		return ;
	stack->a[stack_size(stack->a)] = stack->b[stack_nb(stack->b)];
	stack->b[stack_nb(stack->b)] = END_STACK;
}
