/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:40:46 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 17:39:12 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_ss(t_stacks *stack)
{
	write(STDOUT_FILENO, "ss\n", 3);
	switch_sa(stack, 0);
	switch_sb(stack, 0);
}

void	switch_sb(t_stacks *stack, int write_it)
{
	long	temp;

	if (write_it)
		write(STDOUT_FILENO, "sb\n", 3);
	if (stack_nb(stack->b) <= 1)
		return ;
	temp = stack->b[stack_nb(stack->b)];
	stack->b[stack_nb(stack->b)] = stack->b[stack_nb(stack->b) - 1];
	stack->b[stack_nb(stack->b) - 1] = temp;
}

void	switch_sa(t_stacks *stack, int write_it)
{
	long	temp;

	if (write_it)
		write(STDOUT_FILENO, "sa\n", 3);
	if (stack_nb(stack->a) <= 1)
		return ;
	temp = stack->a[stack_nb(stack->a)];
	stack->a[stack_nb(stack->a)] = stack->a[stack_nb(stack->a) - 1];
	stack->a[stack_nb(stack->a) - 1] = temp;
}

int	stack_size(long *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack[i])
		i++;
	return (i);
}

int	stack_nb(long *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	if (!stack[i] && i)
		i--;
	if (!stack[i])
		return (-1);
	return (i);
}
