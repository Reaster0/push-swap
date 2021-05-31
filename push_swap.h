/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:24:50 by earnaud           #+#    #+#             */
/*   Updated: 2021/05/31 16:53:07 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stacks
{
	size_t *a;
	size_t *b;
	int size;
}	t_stacks;

int		stack_nb(int *stack);
void	switch_sa(t_stacks *stack, int write_it);
void	switch_sb(t_stacks *stack, int write_it);
void	switch_ss(t_stacks *stack);
void	switch_pa(t_stacks *stack, int write_it);
void	switch_pb(t_stacks *stack, int write_it);
void	switch_ra(t_stacks *stack, int write_it);
void	switch_rb(t_stacks *stack, int write_it);
void	switch_rr(t_stacks *stack);
void	switch_rra(t_stacks *stack, int write_it);
void	switch_rrb(t_stacks *stack, int write_it);
void	switch_rrr(t_stacks *stack);

int		ft_isdigit(int c);
int		other_than_num(const char *str);
long	ft_atoi(const char *str);
int		error(int ret);



#endif