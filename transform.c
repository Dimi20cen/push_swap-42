/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:11:13 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/01 14:40:07 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_Astack **ahead_ref)
{
	t_Astack	*curr;
	int			counter;

	curr = *ahead_ref;
	if (curr == NULL)
		return (0);
	counter = 1;
	while (curr->next != NULL)
	{
		curr = curr->next;
		counter++;
	}
	return (counter);
}

int	find_min(t_Astack **ahead_ref, long int prev_min)
{
	long int	curr_min;
	t_Astack	*curr;

	curr = *ahead_ref;
	curr_min = 3000000000;
	while (curr != NULL)
	{
		if (curr->data < curr_min && curr->data > prev_min)
			curr_min = curr->data;
		curr = curr->next;
	}
	return (curr_min);
}

int	index_finder(t_Astack **ahead_ref, long int min)
{
	int			i;
	t_Astack	*curr;

	curr = *ahead_ref;
	i = 0;
	while (curr->data != min)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	change_list_to_positives(t_Astack **ahead_ref, int *temp_ar)
{
	t_Astack	*curr;
	int			i;

	i = 0;
	curr = *ahead_ref;
	while (curr != NULL)
	{
		curr->data = temp_ar[i];
		curr = curr->next;
		i++;
	}
}

void	to_positive(t_Astack **ahead_ref)
{
	int			counter_size;
	long int	prev_min;
	int			*temp_ar;
	int			positive_num;

	temp_ar = malloc(list_size(ahead_ref) * sizeof(int));
	positive_num = 0;
	prev_min = -3000000000;
	counter_size = 0;
	while (counter_size != list_size(ahead_ref))
	{
		prev_min = find_min(ahead_ref, prev_min);
		temp_ar[index_finder(ahead_ref, prev_min)] = positive_num;
		counter_size++;
		positive_num++;
	}
	change_list_to_positives(ahead_ref, temp_ar);
	free(temp_ar);
}
