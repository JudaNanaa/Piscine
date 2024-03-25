/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:33 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:22:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_line(char *str, int size, char *argv, int i)
{
	if (ft_is_valid_line(str, size, argv, i) == 0)
	{
		--i;
		str[i]++;
		if (str[i] > size + '0')
		{
			str[i] = '1';
			--i;
			str[i]++;
		}
	}
	return (i);
}

char	*ft_parsed_str(char *str, int size)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	dest = malloc(sizeof(char) * ((size * size) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			dest[j] = str[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
