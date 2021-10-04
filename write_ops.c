/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:24:18 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/01 20:44:19 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_rotate_a(t_Astack **ahead_ref)
{
	rotate_a(ahead_ref);
	write(1, "ra\n", 3);
}

void	write_r_rotate_a(t_Astack **ahead_ref)
{
	r_rotate_a(ahead_ref);
	write(1, "rra\n", 4);
}

void	write_push_a(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	push_a(ahead_ref, bhead_ref);
	write(1, "pa\n", 3);
}

void	write_push_b(t_Astack **ahead_ref, t_Bstack **bhead_ref)
{
	push_b(ahead_ref, bhead_ref);
	write(1, "pb\n", 3);
}

void	write_swap_a(t_Astack **ahead_ref)
{
	swap_a(ahead_ref);
	write(1, "sa\n", 3);
}
