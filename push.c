/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:53:35 by vbritto-          #+#    #+#             */
/*   Updated: 2024/03/27 19:11:03 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_add, t_list **stack_lost)
{
	t_list	*push_node;

	push_node = *stack_lost;
	*stack_lost = (*stack_lost)->next;
	if (!stack_lost)
		(*stack_lost)->prev = NULL;
	push_node->prev = NULL;
	if (*stack_add == NULL)
	{
		*stack_add = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *stack_add;
		push_node->next->prev = push_node;
		*stack_add = push_node;
	}
	return ;
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
