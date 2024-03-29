/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 18:41:31 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 11:05:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags			flags;
	t_box			box;
	t_folders		folders;
	struct stat		info;
	char			**farg;

	init_flags_struct(&flags);
/*	if (argc != 2 || ft_strcmp(argv[1], "./") == 0)
	{
		recursive_test(flags);
		return (0);
	}*/
	farg = parsing(&flags, argv);
	test_2(flags, farg, 0);
//	if (flags.f_R == 1)
//		test_1(flags, farg);

//	init_box_struct(&box);
//	recursive_test(flags);
//	test_2(flags, farg, 0);
	return (0);
}

/*
 *	Recuperation des flags utilises											OK
 *	Recuperation des noms de fichier dans un tableau a double dimension		OK
 *	Recuperation des noms de dossiers dans une liste chainee
 *	Affichage du contenu du dossier (ordre alpha ou inverse alpha)
 *	Recommencer dans l'un des dossiers contenu dans ./ (premier ou dernier)
*/
