/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:46:13 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/01 21:35:14 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_num_bin_size(t_Astack **ahead_ref)
{
	int	num;
	int	position_of_1;
	int	count;

	count = 0;
	position_of_1 = 0;
	num = list_size(ahead_ref);
	while (count != 32)
	{
		if ((num >> count & 1) == 1)
		{
			position_of_1 = count;
		}
		count++;
	}
	return (position_of_1);
}

void	run_through_list(t_Astack **ahead_ref,
			t_Bstack **bhead_ref, int counter)
{
	t_Astack	*curr;
	int			list_of_size;
	int			local_count;

	local_count = 0;
	list_of_size = list_size(ahead_ref);
	curr = *ahead_ref;
	while (local_count != list_of_size)
	{
		if (((curr->data >> counter) & 1) == 0)
		{
			write_push_b(ahead_ref, bhead_ref);
		}
		else
		{
			write_rotate_a(ahead_ref);
		}
		curr = *ahead_ref;
		local_count++;
	}
}

void	sort(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	int			counter;
	int			bigest_binary_size;
	t_Bstack	*bcurr;

	counter = 0;
	bigest_binary_size = biggest_num_bin_size(ahead_ref);
	while (counter <= bigest_binary_size)
	{
		run_through_list(ahead_ref, bhead_ref, counter);
		bcurr = *bhead_ref;
		while (bcurr != NULL)
		{
			write_push_a(ahead_ref, bhead_ref);
			bcurr = bcurr->next;
			bcurr = *bhead_ref;
		}
		counter++;
	}
}
