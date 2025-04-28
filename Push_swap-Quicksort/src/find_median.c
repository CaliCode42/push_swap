/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:11:05 by tcali             #+#    #+#             */
/*   Updated: 2025/03/21 11:46:48 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

int	*list_to_tab(t_list **a, int *tab)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i++] = tmp->content.nb;
		tmp = tmp->next;
	}
	return (tab);
}

int	bubble_sort(t_list **a, int size, int *tab)
{
	int		temp;
	int		i;
	int		j;

	tab = list_to_tab(a, tab);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab[size / 2]);
}

int	find_median(t_list **a, int size)
{
	int	temp;
	int	*tab;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	temp = bubble_sort(a, size, tab);
	free(tab);
	return (temp);
}
