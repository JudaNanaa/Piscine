/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:29:21 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:29:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_size_tab(char **argv)
{
	int	size;
	int	len_arg;

	size = 1;
	len_arg = ft_strlen(argv[1]);
	while (size <= 9)
	{
		if (len_arg == (4 * size * 2) - 1)
			break ;
		size++;
	}
	if (size > 9 || argv[1][len_arg - 1] == ' ')
		return (0);
	return (size);
}

int	ft_good_number(char **argv, int size)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if ((i % 2) == 0)
		{
			if (argv[1][i] <= '0' || argv[1][i] > '0' + size)
				return (0);
		}
		if ((i % 2) == 1)
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i++;
	}
	return (size);
}

int	ft_check_args(int argc, char **argv)
{
	int	size;

	if (argc != 2)
		return (0);
	size = ft_size_tab(argv);
	if (size == 0)
		return (0);
	size = ft_good_number(argv, size);
	if (size == 0)
		return (0);
	return (size);
}
