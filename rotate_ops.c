/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:28:32 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/29 23:52:34 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_Astack **ahead_ref)
{
	t_Astack	*current;
	t_Astack	*current_1;

	current = *ahead_ref;
	if (current == NULL || current->next == NULL)
		return ;
	current_1 = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *ahead_ref;
	*ahead_ref = current_1->next;
	current_1->next = NULL;
}

void	rotate_b(t_Bstack **bhead_ref)
{
	t_Bstack	*current;
	t_Bstack	*current_1;

	current = *bhead_ref;
	if (current == NULL || current->next == NULL)
		return ;
	current_1 = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *bhead_ref;
	*bhead_ref = current_1->next;
	current_1->next = NULL;
}

void	rotate_both(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	rotate_a(ahead_ref);
	rotate_b(bhead_ref);
}
