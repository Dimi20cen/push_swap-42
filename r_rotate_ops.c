/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:29:41 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/29 23:53:20 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_Astack **ahead_ref)
{
	t_Astack	*curr;
	t_Astack	*temp;
	t_Astack	*last_node;
	t_Astack	*new_node;

	curr = *ahead_ref;
	temp = *ahead_ref;
	if (curr == NULL || curr->next == NULL)
		return ;
	new_node = malloc(sizeof(t_Astack));
	if (new_node == NULL)
		return ;
	while (curr->next != NULL)
		curr = curr->next;
	new_node->data = curr->data;
	new_node->next = *ahead_ref;
	*ahead_ref = new_node;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	free(last_node);
}

void	r_rotate_b(t_Bstack **bhead_ref)
{
	t_Bstack	*curr;
	t_Bstack	*temp;
	t_Bstack	*new_node;
	t_Bstack	*last_node;

	curr = *bhead_ref;
	temp = *bhead_ref;
	if (curr == NULL || curr->next == NULL)
		return ;
	new_node = malloc(sizeof(t_Bstack));
	if (new_node == NULL)
		return ;
	while (curr->next != NULL)
		curr = curr->next;
	new_node->data = curr->data;
	new_node->next = *bhead_ref;
	*bhead_ref = new_node;
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	free(last_node);
}

void	r_rotate_both(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	r_rotate_a(ahead_ref);
	r_rotate_b(bhead_ref);
}
