/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/20 15:12:31 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(long *stack)
{
	int	i;

	i = stack_nb(stack);
	while (i >= 0)
	{
		printf("|%3ld|\n", stack[i]);
		i--;
	}
	printf("\n--------------\n----------------\n");
}

void	print_stacks(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stack_nb(stacks->a);
	j = stack_nb(stacks->b);
	if (j > i)
		i = j;
	while (i >= 0)
	{
		if (j == -1)
			printf("   |%3ld|   |not|\n", stacks->a[i]);
		else
			printf("   |%3ld|   |%3ld|\n", stacks->a[i], stacks->b[i]);
		i--;
	}
	printf("\n----------------------\n----------------------\n");
}

void	ft_magic(t_stacks *stacks, int nbr)
{
	if (nbr == 3)
		algo_for_3(stacks);
	if (nbr == 5)
		algo_for_5(stacks);
	else
		insertionv2(stacks, stacks->size);
}

int	check_double_in_a(t_stacks *stacks)
{
	long	temp;
	int		i;
	int		j;

	j = stack_nb(stacks->a);
	while (j >= 0)
	{
		i = stack_nb(stacks->a);
		temp = stacks->a[j];
		while (i >= 0)
		{
			if (temp == stacks->a[i] && i != j)
				return (1);
			i--;
		}
		j--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (check_error(argc, argv + 1))
		return (error(-1));
	stacks = convert_stack(argc, argv + 1);
	if (check_double_in_a(stacks))
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		return (error(-1));
	}
	print_stacks(stacks);
	ft_magic(stacks, argc - 1);
	print_stacks(stacks);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
