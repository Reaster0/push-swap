/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnaud <earnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:24:50 by earnaud           #+#    #+#             */
/*   Updated: 2021/07/22 16:01:33 by earnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define END_STACK 3333333333

typedef struct s_stacks
{
	long	*a;
	long	*b;
	int		size;
}			t_stacks;

int			stack_nb(long *stack);
void		switch_sa(t_stacks *stack, int write_it);
void		switch_sb(t_stacks *stack, int write_it);
void		switch_ss(t_stacks *stack);
void		switch_pa(t_stacks *stack, int write_it);
void		switch_pb(t_stacks *stack, int write_it);
void		switch_ra(t_stacks *stack, int write_it);
void		switch_rb(t_stacks *stack, int write_it);
void		switch_rr(t_stacks *stack);
void		switch_rra(t_stacks *stack, int write_it);
void		switch_rrb(t_stacks *stack, int write_it);
void		switch_rrr(t_stacks *stack);

int			ft_isdigit(int c);
int			other_than_num(const char *str);
long		ft_atoi(const char *str);
int			error(int ret);
//void		*ft_bzero(void *str, size_t len);
t_stacks	*convert_stack(int argc, char **argv);
int			check_error(int argc, char **argv);
void		index_plus(long *stack, int *index);
void		index_minus(long *stack, int *index);

int			stack_size(long *stack);
void		find_min_max(long *stack, long *min_max);
long		find_min(long *stack);
long		where_in(long *stack, long nbr);
long		find_next(long *stack, long current);
int			check_sorted(t_stacks *stacks);
int			there_min(long *stack, long pivot);
void		print_stacks(t_stacks *stacks);
void		print_list(long *stack);
void		best_rotate_a(t_stacks *stack, int index, long goal);
void		find_sort(long *stack, int size, long *sorted);
int			ft_abs(int x);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

void		algo_for_2(t_stacks *stack);
void		algo_for_3(t_stacks *stack);
void		algo_for_5(t_stacks *stack);
void		insertionv2(t_stacks *stack, long size);
void		push_best(t_stacks *stack, long *sorted);
int			best_action(int count_a, int action_b);
int			find_cheaper_action(long *list_a, long c_index_b, long *sorted);
void		best_rotate_a(t_stacks *stack, int index, long goal);

#endif