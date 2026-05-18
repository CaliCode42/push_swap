/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:57:32 by tcali             #+#    #+#             */
/*   Updated: 2025/03/27 10:09:55 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"
#include <stdio.h>

//Convert standard input to str.
char	*stdin_to_str(int arg_nb, char **args)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 1;
	tmp = NULL;
	str = ft_strdup("");
	while (i < arg_nb)
	{
		tmp = ft_strjoin(str, args[i]);
		free(str);
		str = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (str);
}
