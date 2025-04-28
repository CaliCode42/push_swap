/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:11:12 by tcali             #+#    #+#             */
/*   Updated: 2025/03/21 10:56:53 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

//fct to check which nb to push. 
//Returns : 1 = ra then push
// 			2 = rra then push
int	cheaper_move(int min, int max, int list_size)
{
	if ((min <= (list_size / 2) && min < max)
		|| (max <= (list_size / 2) && max < min))
		return (1);
	else
		return (2);
}
/*
if ((min > (list_size / 2) && min > max)
	|| (max > (list_size / 2) && max > min))
*/

//fct to check order of stack B and choose between push_b and (reverse_)rotate_b
void	push_or_rotate_b(t_list **a, t_list **b)
{
	t_list	*min;

	push_b(a, b);
	min = find_min_lst(b);
	if (min->content.index == 1 && min->next)
		rotate_b(b);
	return ;
}

//fct to push_a then rotate_a when necessary.
void	push_rotate_a(t_list **a, t_list **b)
{
	push_a(a, b);
	if ((*a)->content.nb > (*a)->next->content.nb)
		rotate_a(a);
}

//Better to keep in stack A the biggest numbers and push the rest in revert
//order to stack B. This way when I push them back to stack A, everythiing
//will be sorted.
void	selection_sort(t_list **a, t_list **b)
{
	int		list_size;
	t_list	*min;
	t_list	*max;

	list_size = ft_lstsize(*a);
	while (list_size > 5)
	{
		min = find_min_lst(a);
		max = find_max_lst(a);
		while (min->content.index != 1 && max->content.index != 1)
		{
			if (cheaper_move(min->content.index, max->content.index, list_size)
				== 1)
				rotate_a(a);
			if (cheaper_move(min->content.index, max->content.index, list_size)
				== 2)
				reverse_rotate_a(a);
		}
		push_or_rotate_b(a, b);
		list_size--;
	}
	if (list_size <= 5 && !is_sorted(*a))
		sort_five(a, b);
	print_nodes_linkedlst(*b);
	while ((*b))
		push_rotate_a(a, b);
}

/*
void	selection_sort(t_list **a, t_list **b)
{
	int		list_size;
	t_list	*min;

	list_size = ft_lstsize(*a);
	while (list_size > 5)
	{
		min = find_min_lst(a);
		while (min->content.index != 1)
		{
			if (min->content.index <= (list_size / 2))
				rotate_a(a);
			if (min->content.index > (list_size / 2))
				reverse_rotate_a(a);
		}
		push_b(a, b);
		list_size--;
	}
	if (list_size <= 5 && !is_sorted(*a))
		sort_five(a, b);
	while ((*b))
		push_a(a, b);
}
*/