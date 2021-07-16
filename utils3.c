/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:27:26 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/16 17:00:07 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_plus(long *stack, int *index)
{
	(*index)++;
	if (*index > stack_nb(stack))
		*index = 0;
	else if (*index < 0)
		*index = stack_nb(stack);
}

void	index_minus(long *stack, int *index)
{
	(*index)--;
	if (*index > stack_nb(stack))
		*index = 0;
	else if (*index < 0)
		*index = stack_nb(stack);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
