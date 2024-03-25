/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:05:40 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:05:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_norminette(char **argv, int size, char *str)
{
	char	*true_argv;
	int		result;

	true_argv = ft_parsed_str(argv[1], size);
	if (true_argv == NULL)
		return (0);
	result = ft_backtrack(str, size, true_argv);
	free(true_argv);
	return (result);
}

int	main(int argc, char **argv)
{
	int		size;
	char	*str;
	int		result;

	while (1)
	{
		size = ft_check_args(argc, argv);
		if (size == 0)
			break ;
		str = ft_str_create(size);
		if (str == NULL)
			break ;
		result = ft_norminette(argv, size, str);
		if (result == 0)
			break ;
		result = ft_putstr_final(str, size);
		free(str);
		if (result == 0)
			break ;
		break ;
	}
	if (size == 0 || str == NULL || result == 0)
		ft_putstr("Error", 2);
}
