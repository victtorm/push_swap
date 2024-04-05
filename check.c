/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:10:18 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/03 18:28:40 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_3(char **str)
{
	int long	n;

	while (*str)
	{
		n = ft_atol(*str);
		if ((n < INT_MIN) || (n > INT_MAX))
			return (0);
		str++;
	}
	return (1);
}

int	check_2(char **str)
{
	int		j;
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_3(str))
		return (0);
	return (1);
}

int	check(char **str)
{
	int		i;
	int		j;

	j = 0;
	if (str[j] == NULL)
		return (0);
	while (str[j] != NULL)
	{
		i = 0;
		if ((str[j][0] == 43 || str[j][0] == 45) &&
		(str[j][1] >= 48) && (str[j][1] <= 57))
			i++;
		if (str[j][i] == '\0')
			return (0);
		while (str[j][i] != '\0')
		{
			if (str[j][i] < 48 || str[j][i] > 57)
				return (0);
			i++;
		}
		j++;
	}
	if (!check_2(str))
		return (0);
	return (1);
}

void	free_split(char **str, int n)
{
	int	i;

	i = 0;
	if (n == 2)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return ;
}
