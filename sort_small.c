/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 20:39:00 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/04 16:17:50 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_Astack **ahead_ref)
{
	int			f;
	int			s;
	int			t;

	f = (*ahead_ref)->data;
	s = (*ahead_ref)->next->data;
	t = (*ahead_ref)->next->next->data;
	if (f  > s&& s < t && t > f)
		write_swap_a(ahead_ref);
	if (f > s && s > t && t < f)
	{
		write_swap_a(ahead_ref);
		write_r_rotate_a(ahead_ref);
	}
	if (f > s && s < t && t < f)
		write_rotate_a(ahead_ref);
	if (f < s && s > t && t > f)
	{
		write_swap_a(ahead_ref);
		write_rotate_a(ahead_ref);
	}
	if (f < s && s > t && t < f)
		write_r_rotate_a(ahead_ref);
}

int	find_min_for_sort_5(t_Astack **ahead_ref)
{
	t_Astack	*curr;
	long int	curr_min;

	curr = *ahead_ref;
	curr_min = 3000000000;
	while (curr != NULL)
	{
		if (curr->data < curr_min)
			curr_min = curr->data;
		curr = curr->next;
	}
	return (curr_min);
}

void	sort_five(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	int	min;

	min = find_min_for_sort_5(ahead_ref);
	while ((*ahead_ref))
	{
		if ((*ahead_ref)->data == min)
		{
			write_push_b(ahead_ref, bhead_ref);
			break ;
		}
		write_rotate_a(ahead_ref);
	}
	min = find_min_for_sort_5(ahead_ref);
	while ((*ahead_ref))
	{
		if ((*ahead_ref)->data == min)
		{
			write_push_b(ahead_ref, bhead_ref);
			break ;
		}
		write_rotate_a(ahead_ref);
	}
	sort_three(ahead_ref);
	write_push_a(ahead_ref, bhead_ref);
	write_push_a(ahead_ref, bhead_ref);
}
