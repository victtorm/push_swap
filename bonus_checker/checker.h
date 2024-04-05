/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbritto- <vbritto-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:11:13 by vbritto-          #+#    #+#             */
/*   Updated: 2024/04/03 16:41:08 by vbritto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include "../push_swap.h"

// CHECKER

void		checker( t_list **a, t_list **b);
void		free_split(char **str, int n);

// GET NEXT LINE

char		*get_next_line(int fd);
size_t		ft_strlenl(const char *s);
char		*ft_strchrl(const char *s, int c);
char		*ft_strjoinl(char *s1, const char *s2);

#endif