/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/07 19:40:53 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stacks stacks, long *stack)
{
	if (check_sorted(stacks.a) && stacks.a[stacks.size])
		return ;
	
	while()
}

void	ft_magic(t_stacks *stacks)
{
	int min_max[2];
	if (check_sorted(stacks))
		return ;
	int i = median_value(stacks->a, stacks->size);
	
}

int main(int argc, char **argv)
{

	t_stacks *stacks;
	
	if (check_error(argc, argv + 1))
		return (error(-1));
	stacks = convert_stack(argc, argv + 1);
	ft_magic(stacks);
	return (0);
}