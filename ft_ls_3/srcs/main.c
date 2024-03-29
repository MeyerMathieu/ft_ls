/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:32 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 13:26:39 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	char			**fargs;
	char			**sorted;
	int				i;

	i = 0;
	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	while (fargs[i])
	{
		// Need to make 2 function : One that works with the -a flag, one that
		// works without it.
//		if (flags.f_a == 1)
//			ft_putchar('a');
//		else
			recursive_func(fargs[i], 0, flags);
		i++;
	}

	// Need to make a function that frees every single allocated stuff
	return (0);
}
