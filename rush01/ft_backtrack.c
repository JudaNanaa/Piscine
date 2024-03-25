/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:32:16 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:32:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_valid(char *str, int index, int size)
{
	int	i;
	int	line;

	i = 1;
	line = index / size;
	while ((index - i) / size == line && (index - i) >= 0)
	{
		if (str[index] == str[index - i++])
			return (0);
	}
	i = 1;
	while (index - (size * i) >= 0)
	{
		if (str[index] == str[index - (size * i++)])
			return (0);
	}
	return (1);
}

int	ft_is_valid_line(char *str, int size, char *argv, int index)
{
	if (ft_check_vision_left(str, argv, index, size) == 0)
		return (0);
	if (ft_check_vision_right(str, argv, index, size) == 0)
		return (0);
	return (1);
}

int	ft_is_valid_collunm(char *str, int size, char *argv, int index)
{
	if (ft_check_vision_down(str, index, size, argv) == 0)
		return (0);
	if (ft_check_vision_up(str, index, size, argv) == 0)
		return (0);
	return (1);
}

int	ft_backtrack(char *str, int size, char *argv)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		while (str[i] <= size + '0' && ft_is_valid(str, i, size) == 0)
			str[i]++;
		if (str[i] > size + '0')
		{
			if (i == 0)
				return (0);
			str[i--] = '1';
			str[i]++;
		}
		else
			i++;
		if ((i % size) == 0 && i > 0)
			i = ft_check_line(str, size, argv, i);
		if (i > size * size - size && i <= size * size)
			i = ft_check_collunm(str, size, argv, i);
	}
	return (1);
}
