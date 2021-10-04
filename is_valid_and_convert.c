/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_and_convert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:16:19 by dmylonas          #+#    #+#             */
/*   Updated: 2021/09/30 08:20:00 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// is_valid1 checks that the input is valid,
// it doesnt check the range of the int
// I do that in function transform
int	checks(char *argv[], int i)
{
	size_t	j;
	int		z;

	if ((argv[i][0] != '-' && (argv[i][0] < '0' || argv[i][0] > '9'))
		|| (ft_strlen(argv[i]) > 11))
		return (0);
	j = 1;
	while (j < ft_strlen(argv[i]))
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (0);
		j++;
	}
	z = i - 1;
	while (z > 0)
	{
		if (ft_strcmp(argv[i], argv[z]) == 0)
			return (0);
		z--;
	}
	return (1);
}

//converts
// and checks that no number bigger than integers
// and not something like long int
int	convert(char *argv)
{
	int	num;

	num = ft_atoi(argv);
	if (num == 0 && ft_strlen(argv) > 2)
		return (0);
	return (num);
}

//is the function that calls all other input validation funs
int	is_valid(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (checks(argv, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	append(t_Astack	**head_ref, int new_data)
{
	t_Astack	*new_node;
	t_Astack	*curr;

	new_node = malloc(sizeof(t_Astack));
	new_node->next = NULL;
	new_node->data = new_data;
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return (1);
	}
	curr = *head_ref;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	return (1);
}
