/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:33:35 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/02 13:23:47 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_list **stack, t_list *target, char c)
{
	while (*stack != target)
	{
		if (target->above_med)
		{
			if (c == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (c == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	move_to(t_list **stack_src, t_list **stack_dst, char c)
{
	t_list	*cheap;

	cheap = cheapest(stack_src);
	if (c == 'b')
	{
		if (cheap->above_med && cheap->target->above_med)
			while (cheap != *stack_src && cheap->target != *stack_dst)
				rr(stack_src, stack_dst);
		else if (!(cheap->above_med) && !(cheap->target->above_med))
			while (cheap != *stack_src && cheap->target != *stack_dst)
				rrr(stack_src, stack_dst);
		prep_for_push(stack_src, cheap, 'a');
		prep_for_push(stack_dst, cheap->target, c);
	}
	if (c == 'a')
	{
		prep_for_push(stack_src, cheap, 'b');
		prep_for_push(stack_dst, cheap->target, c);
	}
	return ;
}

void	move_to_b(t_list **stack_a, t_list **stack_b, char c)
{
	update_nodes(stack_a, stack_b);
	move_to(stack_a, stack_b, c);
	pb(stack_a, stack_b);
	return ;
}

void	move_to_a(t_list **stack_a, t_list **stack_b, char c)
{
	update_nodes(stack_a, stack_b);
	move_to(stack_b, stack_a, c);
	pa(stack_a, stack_b);
	return ;
}

void	to_top(t_list **stack)
{
	t_list	*min;

	node_index(stack);
	min = low(stack);
	while (min != *stack)
	{
		if (min->above_med)
			ra(stack);
		else
			rra(stack);
	}
}
