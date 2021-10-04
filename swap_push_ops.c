/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:26:22 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/01 21:48:59 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_Astack **head_ref)
{
	t_Astack	*curr;
	int			new_node;

	curr = *head_ref;
	if (curr == NULL || curr->next == NULL)
		return ;
	new_node = curr->data;
	curr->data = curr->next->data;
	curr->next->data = new_node;
}

void	swap_b(t_Bstack	**head_ref)
{
	t_Bstack	*curr;
	int			new_node;

	curr = *head_ref;
	if (curr == NULL || curr->next == NULL)
		return ;
	new_node = curr->data;
	curr->data = curr->next->data;
	curr->next->data = new_node;
}

void	swap_both(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	swap_a(ahead_ref);
	swap_b(bhead_ref);
}

void	push_a(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	t_Bstack	*bcurr;
	t_Astack	*new_node;

	bcurr = *bhead_ref;
	new_node = malloc(sizeof(t_Astack));
	if (new_node == NULL)
		return ;
	if (bcurr == NULL)
		return ;
	new_node->data = bcurr->data;
	new_node->next = *ahead_ref;
	*ahead_ref = new_node;
	*bhead_ref = bcurr->next;
	free(bcurr);
	bcurr = NULL;
}

void	push_b(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	t_Bstack	*new_node;
	t_Astack	*acurr;

	new_node = malloc(sizeof(t_Bstack));
	if (new_node == NULL)
		return ;
	acurr = *ahead_ref;
	if (acurr == NULL)
		return ;
	new_node->data = acurr->data;
	new_node->next = *bhead_ref;
	*bhead_ref = new_node;
	*ahead_ref = acurr->next;
	free(acurr);
	acurr = NULL;
}
