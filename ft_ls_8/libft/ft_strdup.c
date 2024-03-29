/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:43:49 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/19 11:08:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (0);
	while (s1[j])
	{
		s2[j] = s1[j];
		j++;
	}
	while (s2[j])
	{
		s2[j] = '\0';
		j++;
	}
	return (s2);
}
