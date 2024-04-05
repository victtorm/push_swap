/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:59:49 by vbritto-          #+#    #+#             */
/*   Updated: 2024/03/27 19:18:46 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_move(t_list **stack_src, t_list **stack_dst)
{
	t_list	*tmp_src;

	tmp_src = *stack_src;
	while (tmp_src != NULL)
	{
		if (tmp_src->above_med)
			tmp_src->cost = tmp_src->index;
		if (!tmp_src->above_med)
			tmp_src->cost = ft_lstsize(*stack_src) - tmp_src->index;
		if (tmp_src->target->above_med)
			tmp_src->cost += tmp_src->target->index;
		if (!tmp_src->target->above_med)
			tmp_src->cost += ft_lstsize(*stack_dst) - tmp_src->target->index;
		decrease_cost(tmp_src, stack_src, stack_dst);
		tmp_src = tmp_src->next;
	}
}

void	decrease_cost(t_list *t, t_list **s, t_list **d)
{
	if (t->above_med && t->target->above_med)
	{
		if (t->index < t->target->index)
			t->cost -= t->index;
		else
			t->cost -= t->target->index;
	}
	else if (!(t->above_med) && !(t->target->above_med))
	{
		if (ft_lstsize((*s)) - t->index < ft_lstsize((*d)) - t->target->index)
			t->cost -= ft_lstsize((*s)) - t->index;
		else
			t->cost -= ft_lstsize((*d)) - t->target->index;
	}
}

void	target_a(t_list **stack_src, t_list **stack_dst)
{
	t_list			*tmp_a;
	t_list			*tmp_b;
	t_list			*target_node;
	long			target;

	tmp_a = *stack_src;
	while (tmp_a)
	{
		target = -2147483649;
		tmp_b = *stack_dst;
		while (tmp_b)
		{
			if (tmp_b->number < tmp_a->number && tmp_b->number > target)
			{
				target = tmp_b->number;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (target == -2147483649)
			tmp_a->target = biggest(stack_dst);
		else
			tmp_a->target = target_node;
		tmp_a = tmp_a->next;
	}
}

void	target_b(t_list **stack_src, t_list **stack_dst)
{
	t_list		*tmp_a;
	t_list		*tmp_b;
	t_list		*target_node;
	long		target;

	tmp_b = *stack_dst;
	while (tmp_b)
	{
		target = 2147483648;
		tmp_a = *stack_src;
		while (tmp_a)
		{
			if (tmp_a->number > tmp_b->number && tmp_a->number < target)
			{
				target = tmp_a->number;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target == 2147483648)
			tmp_b->target = low(stack_src);
		else
			tmp_b->target = target_node;
		tmp_b = tmp_b->next;
	}
}
