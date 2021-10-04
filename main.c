/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:20:34 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/04 12:18:09 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sort(t_Astack **ahead, t_Bstack **bhead)
{
	if (is_sorted(ahead) == 1)
		return ;
	if (list_size(ahead) == 2)
	{
		write_swap_a(ahead);
		return ;
	}
	if (list_size(ahead) == 3)
	{
		sort_three(ahead);
		return ;
	}
	if (list_size(ahead) == 5)
	{
		sort_five(ahead, bhead);
		return ;
	}
	to_positive(ahead);
	sort(ahead, bhead);
	a_deallocate(ahead);
	b_deallocate(bhead);
	return ;
}

// i starts from 1 cause i dont care about the program name
int	main(int argc, char *argv[])
{
	int			i;
	t_Astack	*ahead;
	t_Bstack	*bhead;

	i = 1;
	if (argc <= 1)
		return (0);
	if (is_valid(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ahead = NULL;
	bhead = NULL;
	while (i < argc)
	{
		if (convert(argv[i]) == 0 && ft_strlen(argv[i]) > 2)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		append(&ahead, convert(argv[i]));
		i++;
	}
	main_sort(&ahead, &bhead);
}
