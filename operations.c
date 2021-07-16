/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:56:25 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 16:47:51 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_rr(t_stacks *stack)
{
	write(STDOUT_FILENO, "rr\n", 3);
	switch_ra(stack, 0);
	switch_rb(stack, 0);
}

void	switch_rb(t_stacks *stack, int write_it)
{
	int	i;
	int	temp;

	if (write_it)
		write(STDOUT_FILENO, "rb\n", 3);
	i = stack_nb(stack->b);
	temp = stack->b[stack_nb(stack->b)];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
}

void	switch_ra(t_stacks *stack, int write_it)
{
	int	i;
	int	temp;

	if (write_it)
		write(STDOUT_FILENO, "ra\n", 3);
	i = stack_nb(stack->a);
	temp = stack->a[stack_nb(stack->a)];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
}

void	switch_rrr(t_stacks *stack)
{
	write(STDOUT_FILENO, "rrr\n", 4);
	switch_rra(stack, 0);
	switch_rrb(stack, 0);
}

void	switch_rrb(t_stacks *stack, int write_it)
{
	int	i;
	int	temp;

	if (write_it)
		write(STDOUT_FILENO, "rrb\n", 4);
	i = 0;
	temp = stack->b[0];
	while (i < stack_nb(stack->b))
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}
