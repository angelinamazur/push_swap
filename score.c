/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:30:12 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/02/21 13:56:28 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	count_score_rb(t_env *env)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = env->list_b;
	while (tmp)
	{
		tmp->score_rb = i;
		tmp = tmp->next;
		i++;
	}
}	

void	count_score_rrb(t_env *env)
{
	int		i;
	t_list	*tmp;

	tmp = env->list_b;
	while (tmp)
	{
		tmp->score_rrb = i;
		tmp = tmp->next;
		i--;
	}
}

void	count_score_ra(t_env *env)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	tmp = env->list_b;
	while (tmp)
	{
		first = env->list_a;
		last = ft_lstlast(env->list_a);
		tmp->score_ra = 0;
		if (!(first->value > tmp->value && last->value < tmp->value))
		{
			while (first->next)
			{
				last = first;
				first = first->next;
				tmp->score_ra++;
				if (first->value > tmp->value && last->value < tmp->value)
					break ;
			}
		}
		tmp = tmp->next;
	}
}

void	count_score_rra(t_env *env)
{
	t_list	*tmp;
	int		len;

	len = ft_lstsize(env->list_a);
	tmp = env->list_b;
	while (tmp)
	{
		tmp->score_rra = len - tmp->score_ra;
		tmp = tmp->next;
	}
}