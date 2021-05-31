/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:17:21 by earnaud           #+#    #+#             */
/*   Updated: 2021/05/31 05:00:00 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = (str[i] == '-') * -2 + 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * neg);
}

int	error(int ret)
{
	write(STDOUT_FILENO ,"Error\n", 6);
	return (ret);
}

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
	//stack->a = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	//stack->b = ft_bzero(malloc(sizeof(int) * (argc -1)), argc -1);
	stack->a = malloc(sizeof(int) * (argc -1));
	stack->b = malloc(sizeof(int) * (argc -1));
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
	if (!argc)
		return (1);
	//check argv
	return (0);
}

int main(int argc, char **argv)
{

	t_stacks *stacks;
	
	if (check_error(argc, argv))
		return (0);
	stacks = convert_stack(argc, argv);
	return (0);
}