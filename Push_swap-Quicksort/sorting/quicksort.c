/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:49:04 by tcali             #+#    #+#             */
/*   Updated: 2025/03/24 14:12:15 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

void	quicksort(t_list **a, t_list **b, int size)
{
	if (!a || !*a)
		return ;
	while (!is_sorted(*a) || *b)
		sort_a(a, b, size);
}

void	sort_a(t_list **a, t_list **b, int size)
{
	int	pushed;

	if (size <= 5)
	{
		mini_sort(a, b);
		return ;
	}
	pushed = 0;
	printf("sort_a\n");
	quicksort_a(a, b, size);
	sort_b(b, a, pushed);
	while (pushed--)
		push_a(a, b);
}

void	sort_b(t_list **b, t_list **a, int size)
{
	int	pushed;

	if (size <= 5)
	{
		mini_sort(b, a);
		while (size--)
			push_a(a, b);
		return ;
	}
	pushed = 0;
	printf("sort_b\n");
	quicksort_b(b, a, size);
	sort_a(a, b, pushed);
	while (pushed--)
		push_b(b, a);
}

void	quicksort_a(t_list **a, t_list **b, int size)
{
	int	i;
	int	pivot;
	int	pushed;

	i = 0;
	pivot = find_median(a, size);
	pushed = 0;
	printf("quicksort_a\n");
	while (i < size)
	{
		//printf("pivot : %d\n", pivot);
		//printf("nb : %d\n", (*a)->content.nb);
		if ((*a)->content.nb < pivot)
		{
			push_a(a, b);
			(pushed)++;
		}
		else
			rotate(a);
		i++;
	}
}

void	quicksort_b(t_list **b, t_list **a, int size)
{
	int	i;
	int	pivot;
	int	pushed;

	i = 0;
	pivot = find_median(b, size);
	pushed = 0;
	printf("quicksort_b\n");
	while (i < size)
	{
		printf("pivot : %d\n", pivot);
		printf("nb : %d\n", (*b)->content.nb);
		if ((*b)->content.nb >= pivot)
		{
			push_b(a, b);
			(pushed)++;
		}
		else
			rotate(b);
		i++;
	}
}
