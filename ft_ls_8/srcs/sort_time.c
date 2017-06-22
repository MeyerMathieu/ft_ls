/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:39:14 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/22 18:33:19 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		next_time_sort(t_lst *begin, t_lst *content, char *name, char *path)
{
	struct stat			sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(path);
	if (content && stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(content->path);
	if (content && content->next
			&& stat(content->next->path, &(content->next->sb)) == -1
			&& lstat(content->next->path, &(content->next->sb)) == -1)
		perror(content->path);
	if (content && content->sb.st_mtime < sb.st_mtime)
		sub_next_1(content, name, path);
	else if ((sub_time_sort_conditions(content, name, path) == 1)
			|| (content && content->sb.st_mtime > sb.st_mtime
			&& !content->next))
		sub_time_sort_2(content, name, path);
	else if (content && content->sb.st_mtime == sb.st_mtime)
		next_nano_sort(begin, content, name, path);
	else if (content->next)
		next_time_sort(begin, content->next, name, path);
}

void		next_nano_sort(t_lst *begin, t_lst *content, char *name, char *path)
{
	struct stat		sb;
	t_lst			*new;
	t_lst			*tmp;

	tmp = NULL;
	new = NULL;
	sub_nano_sort_1(content, name, path, &sb);
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
				&& lstat(content->next->path, &(content->next->sb)) == -1)
			perror(content->next->path);
	}
	if (sub_nsrtconds(content, sb) == 1)
	{
		sub_nano_sort_mallocs(new, tmp);
		sub_next_1(content, name, path);
	}
	else if (sub_nsrtconds(content, sb) == 2 || sub_nsrtconds(content, sb) == 3)
		sub_nano_sort_2(content, name, path, sb);
	else if (content && content->sb.st_mtime == sb.st_mtime
			&& content->sb.st_mtimespec.tv_nsec == sb.st_mtimespec.tv_nsec)
		next_ascii_sort(begin, content, name, path);
	else if (content->next && content->next->sb.st_mtime == sb.st_mtime)
		next_nano_sort(begin, content->next, name, path);
}

void		next_ascii_sort(t_lst *bgin, t_lst *content, char *name, char *path)
{
	struct stat			sb;

	if (stat(set_path(name, path), &sb) == -1
			&& lstat(set_path(name, path), &sb) == -1)
		perror(set_path(name, path));
	if (content && stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(set_path(name, path));
	if (content && content->next)
	{
		if (stat(content->next->path, &(content->next->sb)) == -1
				&& lstat(content->next->path, &(content->next->sb)) == -1)
			perror(content->next->path);
	}
	if (sub_asciisrtconds(content, sb, name) == 1
			|| sub_asciisrtconds(content, sb, name) == 2
			|| sub_asciisrtconds(content, sb, name) == 3)
		sub_ascii_sort_1(content, name, path, sb);
	else if (sub_asciisrtconds(content, sb, name) == 4)
		next_ascii_sort(bgin, content->next, name, path);
}
