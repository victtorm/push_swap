/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:39:48 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/02 13:23:04 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_nodes(t_list **stack_a, t_list **stack_b)
{
	node_index(stack_a);
	node_index(stack_b);
	target_a(stack_a, stack_b);
	target_b(stack_a, stack_b);
	cost_move(stack_a, stack_b);
	cost_move(stack_b, stack_a);
}

t_list	*cheapest(t_list **stack)
{
	t_list	*cheaper;
	t_list	*tmp;

	tmp = *stack;
	cheaper = tmp;
	while (tmp)
	{
		if (tmp->cost < cheaper->cost)
			cheaper = tmp;
		tmp = tmp->next;
	}
	return (cheaper);
}

void	node_index(t_list **stack)
{
	t_list	*tmp;
	int		med;
	int		i;

	tmp = *stack;
	med = ft_lstsize(*stack) / 2;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		if (i < med)
			tmp->above_med = true;
		else
			tmp->above_med = false;
		i++;
		tmp = tmp->next;
	}
}

t_list	*biggest(t_list **stack)
{
	t_list	*big;
	t_list	*tmp;

	tmp = *stack;
	big = tmp;
	while (tmp)
	{
		if (tmp->number > big->number)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_list	*low(t_list **stack)
{
	t_list	*low;
	t_list	*tmp;

	tmp = *stack;
	low = tmp;
	while (tmp)
	{
		if (tmp->number < low->number)
			low = tmp;
		tmp = tmp->next;
	}
	return (low);
}
