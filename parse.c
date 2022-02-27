/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:16:12 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/27 16:32:41 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	count_arr(char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i] != NULL)
		i++;
	return (i);
}

int	check_repeat(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == arr[i + 1] && arr[i + 1])
		{
			write(1, "Error1\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_digit(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		if (!((arr[i][0] == '-' && ft_isdigit(arr[i][1])) \
		|| ft_isdigit(arr[i][0])))
		{
			write(1, "Error\n", 10);
			return (1);
		}
		j = 1;
		while (arr[i][j] != '\0')
		{
			if (!ft_isdigit(arr[i][j]))
			{
				write(1, "Error\n", 10);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*make_arr(char **char_arr)
{
	int		*int_arr;
	int		i;
	long	tmp;

	i = count_arr(char_arr);
	int_arr = malloc(sizeof(int) * (i));
	if (!int_arr)
		return (NULL);
	i = 0;
	while (char_arr[i] != NULL)
	{
		tmp = ft_atoi(char_arr[i]);
		if (tmp > INT_MIN && tmp < INT_MAX)
			int_arr[i] = (int)tmp;
		else
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (int_arr);
}

char	**parse_argv(int argc, char **argv)
{
	char	**arr;
	char	*str;
	char	*sp;
	char	*tmp;
	int		i;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (arr == NULL)
			return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			str = ft_strdup(argv[1]);
			i = 2;
			while (i < argc)
			{
				str = ft_strjoin(ft_strjoin(str, " "), argv[i]);
				i++;
			}
			arr = ft_split(str, ' ');
			if (arr == NULL)
				return (0);
		}
		free(str);
	}
	return (arr);
}

