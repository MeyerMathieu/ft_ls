/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:57:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/25 17:10:45 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int			find_index(t_flags flags, char **str)
{
	int		index;

	index = 0;
	while (str[index][0] == '.' && flags.f_a == 0)
		index++;
	return (index);
}
