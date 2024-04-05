/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:41:03 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/03 15:26:17 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = NULL;
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
	push_swap(&a);
	free_split(argv, argc);
	free_stack(&a);
	return (0);
}
