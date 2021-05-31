/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/05/31 18:14:25 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

t_stacks	*convert_stack(int argc, char **argv)
{
	t_stacks	*stack;
	int			i;

	i = 0;
	stack = malloc(sizeof(t_stacks));
	stack->a = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	stack->b = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	stack->size = argc -1;
	argv++;
	while(*argv)
	{
		stack->a[i] = ft_atoi(*argv);
		argv++;
		i++;
	}
	return (stack);
}

int	check_error(int argc, char **argv)
{
	long temp;

	if (!argc)
		return (1);
	while(*argv)
	{
		if (other_than_num(*argv))
			return (1);
		temp = ft_atoi(*argv);
		if (temp > INT32_MAX || temp < INT32_MIN)
			return (1);
		argv++;
	}
	return (0);
}


void	ft_magic(t_stacks *stacks)
{
	
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