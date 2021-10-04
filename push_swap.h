/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:04:41 by dmylonas          #+#    #+#             */
/*   Updated: 2021/10/04 16:20:11 by dmylonas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 

// typedef struct s_stack
// {
// 	int				num;
// 	struct s_stack	*next;
// }					t_stack;

// typedef struct stacks
// {
// 	t_stack		*Astack;
// 	t_stack		*Bstack;
// }				t_all;

typedef struct Astack
{
	int				data;
	struct Astack	*next;
}					t_Astack;

typedef struct Bstack
{
	int				data;
	struct Bstack	*next;
}					t_Bstack;

int		main(int argc, char *argv[]);
void	main_sort(t_Astack **ahead, t_Bstack **bhead);

void	swap_a(t_Astack **head_ref);
void	swap_b(t_Bstack **head_ref);
void	swap_both(t_Astack **ahead_ref, t_Bstack **bhead_ref);

void	push_a(t_Astack **ahead_ref, t_Bstack **bhead_ref);
void	push_b(t_Astack **ahead_ref, t_Bstack **bhead_ref);

void	rotate_a(t_Astack **ahead_ref);
void	rotate_b(t_Bstack **bhead_ref);
void	rotate_both(t_Astack **ahead_ref, t_Bstack **bhead_ref);

void	r_rotate_a(t_Astack **ahead_ref);
void	r_rotate_b(t_Bstack **bhead_ref);
void	r_rotate_both(t_Astack **ahead_ref, t_Bstack **bhead_ref);

size_t	ft_strlen(const char *s);
int		append(t_Astack	**head_ref, int new_data);
int		is_valid(int argc, char *argv[]);
int		convert(char *argv);
int		checks(char *argv[], int i);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	printList(t_Astack	*node);

void	a_deallocate(t_Astack	**ahead);
void	b_deallocate(t_Bstack	**bhead);

int		list_size(t_Astack **ahead_ref);
int		find_min(t_Astack **ahead_ref, long int prev_min);
void	change_list_to_positives(t_Astack **ahead_ref, int *temp_ar);
int		index_finder(t_Astack **ahead_ref, long int min);
void	to_positive(t_Astack **ahead_ref);

void	sort(t_Astack **ahead_ref, t_Bstack **bhead_ref);
void	run_through_list(t_Astack **ahead_ref, t_Bstack **bhead_ref,
			int counter);
int		biggest_num_bin_size(t_Astack **ahead_ref);

void	write_rotate_a(t_Astack **ahead_ref);
void	write_r_rotate_a(t_Astack **ahead_ref);
void	write_push_a(t_Astack **ahead_ref, t_Bstack **bhead_ref);
void	write_push_b(t_Astack **ahead_ref, t_Bstack **bhead_ref);
void	write_swap_a(t_Astack **ahead_ref);

int		is_sorted(t_Astack **ahead_ref);

void	sort_three(t_Astack **ahead_ref);
int		find_min_for_sort_5(t_Astack **ahead_ref);
void	sort_five(t_Astack **ahead_ref, t_Bstack **bhead_ref);

#endif