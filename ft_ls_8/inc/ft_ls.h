/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:49:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/20 15:06:13 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>			// Delete before last push
# include <stdio.h>			// Delete before last push
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define EXEC_NAME "a.out"		// set ft_ls before last push
# define DIFFERENCE 15736732

typedef struct			s_lst
{
	char				*name;
	char				*path;
	struct stat			sb;
	int					error;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_flags
{
	int					f_l;
	int					f_a;
	int					f_R;
	int					f_r;
	int					f_t;
}						t_flags;

typedef struct			s_fold
{
	DIR					*rep;
	struct dirent		*readfile;
}						t_fold;

typedef struct			s_info
{
	char				*name;
	char				*group;
}						t_info;

typedef struct			s_print
{
	int					today_date;
	int					highest_dep;
	int					longer_author_name;
	int					longer_group_name;
	int					highest_size;
}						t_print;

/*
**			INIT
*/

void					init_flags_struct(t_flags *flags);
void					init_fold_struct(t_fold *fold);
void					init_print_struct(t_print *print);

/*
**			PARSING
*/

t_lst					*parsing(char **argv, t_flags *flags);
void					get_flags(char *str, t_flags *flags);
void					first_elem(char *name, t_lst *list);
void					add_elem(char *name, t_lst *list);

/*
**			CORE
*/

void					submain(t_lst *fargs, t_flags flags);
void					core(char *path, t_flags flags);
t_lst					*open_directory(char *path, t_flags flags);
void					first(t_lst *content, char *name, char *path, int *tmp);
void					next(t_lst *content, char *name, char *path);
void					next_reverse(t_lst *content, char *name, char *path);

char					*set_path(char *name, char *path);
void					recursive_func(t_lst *content, t_flags flags);

/*
**			PRINT
*/

void					print_test(t_lst *list);		// PROVISOIRE

void					my_printf(t_lst *list, t_flags flags);
void					print_l_flag(t_lst *list, t_flags flags, t_print print);

void					print_type(char *path);

void					print_rights(char *path);
void					print_usr_rights(struct stat sb);
void					print_grp_rights(struct stat sb);
void					print_oth_rights(struct stat sb);

void					print_dependencies(t_lst *list, t_print *infos);
void					print_author(struct stat sb, t_print *infos);
void					print_group(struct stat sb, t_print *infos);
void					print_size(struct stat sb, t_print *infos);
void					print_time(struct stat sb, t_print *infos);

/*
**			ERRORS
*/

void					error(int a, char *str);

/*
**			OTHER
*/

char					*get_name(char *path);
void					rec_high(t_lst *list, int *max);
void					rec_longer_author_name(t_lst *list, int *max);
void					rec_longer_group_name(t_lst *list, int *max);
void					rec_highest_size(t_lst *list, int *max);
void					get_today_date(int *today_date);
void					free_lst(t_lst *list);
void					free_lst2(t_lst *list);

/*
**			SORTING
*/

t_lst					*sort_reverse(t_lst *list);
t_lst					*get_elem(t_lst *list, int index, int i);
void					get_size(t_lst *list, int *size);

void					next_conditions(t_lst *list, char *name, char *path,
						t_flags flags);
void					ft_putsec(t_lst **content, t_lst *new_elem);
void					ft_addbetween(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					put_front(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					put_nsec(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					ascii(t_lst **content, t_lst *new_elem, t_lst *begin,
						t_lst *previous);
void					ft_timestamp(t_lst *new_elem);
void					ft_addhead(t_lst **content, t_lst *new_elem);

#endif
