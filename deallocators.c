/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:15:34 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/30 08:16:03 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_deallocate(t_Astack	**ahead)
{
	t_Astack	*curr;
	t_Astack	*curr_we_free;

	curr = *ahead;
	while (curr != NULL)
	{
		curr_we_free = curr;
		curr = curr->next;
		free(curr_we_free);
	}
	*ahead = NULL;
}

void	b_deallocate(t_Bstack	**bhead)
{
	t_Bstack	*curr;
	t_Bstack	*curr_we_free;

	curr = *bhead;
	while (curr != NULL)
	{
		curr_we_free = curr;
		curr = curr->next;
		free(curr_we_free);
	}
	*bhead = NULL;
}
