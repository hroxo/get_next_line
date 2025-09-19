/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:32:41 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/19 14:25:28 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	to_line_helper(t_list *lst, char *str)
{
	int		i;
	int		j;

	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = 0;
				return ;
			}
			str[j++] = lst->str[i++];
		}
		lst = lst->next;
	}
	str[j] = 0;
}

void	new_list(t_list **stash)
{
	t_list	*new_node;
	t_list	*last;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(BUF_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!buf || !new_node)
		return ;
	last = (*stash);
	while (last->next)
		last = last->next;
	while (last->str[i] && (last->str[i] != '\n'))
		i++;
	while (last->str[i])
		buf[j++] = last->str[++i];
	buf[j] = 0;
	new_node->str = buf;
	new_node->next = NULL;
	clean_house(stash, new_node, buf);
	free(new_node);
	//free(buf);
}

char	*to_line(t_list	*lst)
{
	char	*out;
	int		len;

	if (lst == NULL)
		return (NULL);
	len = len_to_nl(lst);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	to_line_helper(lst, out);
	return (out);
}

void	create_list(t_list **stash, int fd)
{
	char	*buf;
	int		bytes_read;

	while (!has_nl(*stash))
	{
		buf = malloc(BUF_SIZE + 1);
		if (!buf)
			return ;
		bytes_read = read(fd, buf, BUF_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = 0;
		put_last_node(stash, buf);
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUF_SIZE <= 0 || (read(fd, &line, 0) < 0))
		return (NULL);
	create_list(&stash, fd);
	if (!stash)
		return (NULL);
	line = to_line(stash);
	new_list(&stash);
	return (line);
}
