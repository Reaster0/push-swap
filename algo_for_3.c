/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:40:26 by earnaud           #+#    #+#             */
/*   Updated: 2021/06/15 16:32:22 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo_for_3(t_stacks *stack)
{
	int min_max[2];

	if (check_sorted(stack))
		return ;
	find_min_max(stack->a, min_max);
	if (stack->a[2] == min_max[1])
		{
			switch_ra(stack, 1);
			if (!check_sorted(stack))
				switch_sa(stack, 1);
		}
	else if (stack->a[1] == min_max[1])
	{
		switch_ra(stack,1);
		if (!check_sorted(stack))
			switch_sa(stack, 1);
	}
	else if (stack->a[0] == min_max[1])
		switch_sa(stack, 1);
}