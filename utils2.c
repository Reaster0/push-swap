/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:19:18 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/08 14:34:23 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_bzero(void *str, size_t len)
{
	// 	size_t index;

	// index = 0;
	// while (index < len)
	// {
	// 	*(char *)(str + index) = 0;
	// 	index++;
	// }
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (str);
}

t_stacks	*convert_stack(int argc, char **argv)
{
	t_stacks	*stack;
	int			i;

	i = argc - 1;
	stack = malloc(sizeof(t_stacks));
	//stack->a = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	//stack->b = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	stack->a = malloc(sizeof(int) * (argc));
	stack->b = malloc(sizeof(int) * (argc));
	stack->size = argc -1;
	while(*argv)
	{
		stack->a[i] = ft_atoi(*argv);
		stack->b[i] = 0;
		argv++;
		i--;
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
		if (temp > 2147483647 || temp < -2147483648)
			return (1);
		argv++;
	}
	return (0);
}