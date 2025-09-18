/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:32:41 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/18 15:46:52 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*new_list(t_list *list)
{
	t_list	*new_list;
	int		len;
	int		i;

	i = 0;
	len = len_to_new_line(list);
	if (len == -1)
	{
		clean_lst(&list);
		return (NULL);
	}
	while (len)
	{
		if (list->str[i] == 0)
		{
			i = 0;
			list = list->next;
		}
		i++;
		len--;
	}
	new_list = create_node(&list->str[i], BUF_SIZE);
	new_list->next = list->next;
	return (new_list);
}

char	*to_line(t_list	*list)
{
	char	*out;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = len_to_new_line(list);
	if (len == -1)
	{
		clean_lst(&list);
		return (NULL);
	}
	out = malloc(len + 2);
	if (!out)
		return (NULL);
	while (j < len)
	{
		if (list->str[i] == 0)
		{
			i = 0;
			list = list->next;
		}
		out[j++] = list->str[i++];
	}
	out[j++] = '\n';
	out[j] = 0;
	return (out);
}

t_list	*read_fd(int fd)
{
	char	buf[BUF_SIZE];
	t_list	*head;
	int		bytes_read;

	head = NULL;
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read)
	{
		if (bytes_read < 0)
		{
			clean_lst(&head);
			return (NULL);
		}
		head = put_last_node(head, buf, bytes_read);
		if (!head)
		{
			clean_lst(&head);
			return (NULL);
		}
		bytes_read = read(fd, buf, BUF_SIZE);
	}
	return (head);
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0)
		return (NULL);
	if (!stash)
	{
		stash = read_fd(fd);
		if (!stash)
			return (NULL);
	}
	line = to_line(stash);
	if (!line)
	{
		clean_lst(&stash);
		return (NULL);
	}
	stash = new_list(stash);
	if (!stash)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
