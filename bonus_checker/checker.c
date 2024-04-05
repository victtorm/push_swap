/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:01:03 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:22 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(t_list **a, t_list **b, char *str)
{
	get_next_line(-1);
	free_stack(a);
	free_stack(b);
	free(str);
	write (2, "Error\n", 6);
	exit (1);
}

static void	made_command(t_list **a, t_list **b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3) && *b != NULL)
		pa(a, b);
	else if (!ft_strncmp(command, "pb\n", 3) && *a != NULL)
		pb(a, b);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b);
	else
		error(a, b, command);
}

void	checker( t_list **a, t_list **b)
{
	char	*next_line;

	next_line = NULL;
	next_line = get_next_line(0);
	while (next_line)
	{
		made_command(a, b, next_line);
		free (next_line);
		next_line = get_next_line(0);
	}
	if (sort_check(*a) && *b == NULL)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 2)
	{
		if (argc == 1)
			return (0);
		if (argv[1][0] == '\0')
			return (write(2, "Error\n", 6));
		argv = ft_split(argv [argc - 1], ' ');
	}
	else
		argv++;
	if (!check(argv))
	{
		free_split(argv, argc);
		write(2, "Error\n", 6);
		return (0);
	}
	a = create_stack(a, argv);
	free_split(argv, argc);
	checker(&a, &b);
	return (0);
}
