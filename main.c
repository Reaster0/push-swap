/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/08/04 14:49:09 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_list(long *stack)
// {
// 	int	i;

// 	i = stack_nb(stack);
// 	while (i >= 0)
// 	{
// 		printf("|%3ld|\n", stack[i]);
// 		i--;
// 	}
// 	printf("\n--------------\n----------------\n");
// }

// void	print_stacks(t_stacks *stacks)
// {
// 	int	i;
// 	int	j;

// 	i = stack_nb(stacks->a);
// 	j = stack_nb(stacks->b);
// 	if (j > i)
// 		i = j;
// 	while (i >= 0)
// 	{
// 		if (j == -1)
// 			printf("   |%3ld|   |not|\n", stacks->a[i]);
// 		else
// 			printf("   |%3ld|   |%3ld|\n", stacks->a[i], stacks->b[i]);
// 		i--;
// 	}
// 	printf("\n----------------------\n----------------------\n");
// }

void	ft_magic(t_stacks *stacks, int nbr)
{
	if (nbr == 1 || check_sorted(stacks))
		return ;
	else if (nbr == 2)
		algo_for_2(stacks);
	else if (nbr == 3)
		algo_for_3(stacks);
	else if (nbr == 5)
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

	if (argc == 1)
		return (0);
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
	ft_magic(stacks, argc - 1);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
