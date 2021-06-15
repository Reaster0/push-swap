/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/15 19:31:09 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int i;
	int j;

	i = stack_nb(stacks->a);
	j = stack_nb(stacks->b);
	if (j > i)
	 i = j;

	while (i >= 0)
	{
		printf("   |%3ld|   |%3ld|\n", stacks->a[i], stacks->b[i]);
		//if (i)
			i--;
		//if (j)
		//	j--;
		//if (!i && !j)
			//printf("   |%3ld|   |%3ld|\n", stacks->a[i], stacks->b[i]);
	}
	printf("\n----------------------\n----------------------\n");
}

void	ft_magic(t_stacks *stacks, int nbr)
{
	//print_stacks(stacks);
	if (nbr == 3)
		algo_for_3(stacks);
	if (nbr == 5)
		algo_for_5(stacks);
	//second_algo(stacks); //algo for 100
	//print_stacks(stacks);

	//ft_magic(stacks);
}

int main(int argc, char **argv)
{

	t_stacks *stacks;
	
	if (check_error(argc, argv + 1))
		return (error(-1));
	stacks = convert_stack(argc, argv + 1);
	ft_magic(stacks,argc - 1);
	return (0);
}