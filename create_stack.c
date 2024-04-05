/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:40:05 by vbritto-          #+#    #+#             */
/*   Updated: 2024/03/27 14:43:01 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	link_stack(t_list *stack, t_list *new)
{
	stack->next = new;
	new->prev = stack;
}

t_list	*stack_node(int n)
{
	t_list	*node;

	node = NULL;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->number = n;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_list	*create_stack(t_list *stack, char **str)
{
	t_list	*new;
	t_list	*stack_a;
	int		n;

	n = 0;
	new = NULL;
	stack_a = NULL;
	n = ft_atoi(*str);
	stack = stack_node(n);
	stack_a = stack;
	str++;
	while (*str)
	{
		n = ft_atoi(*str);
		new = stack_node(n);
		link_stack(stack, new);
		stack = stack->next;
		str++;
	}
	return (stack_a);
}
