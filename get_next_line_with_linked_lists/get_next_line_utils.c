/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:10:42 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/18 15:42:15 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	clean_lst(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		(*lst) = next;
	}
	free(next);
}

t_list	*create_node(char *str, int n)
{
	t_list	*node;
	int	i;

	i = 0;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->str = malloc(sizeof(char) * n + 1);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	while (i < n && str[i])
	{
		node->str[i] = str[i];
		i++;
	}
	node->str[i] = 0;
	node->next = NULL;
	return (node);
}

void	*put_last_node(t_list *list, char *buf, int n)
{
	t_list	*node;
	t_list	*new;

	new = create_node(buf, n);
	if (!new)
	{
		clean_lst(&list);
		return (NULL);
	}
	if (!list)
	{
		list = new;
		return (list);
	}
	node = list;
	while (node->next)
		node = node->next;
	node->next = new;
	return (list);
}

int	len_to_new_line(t_list *list)
{
	int	len;
	int	i;

	if (!list)
		return (-1);
	len = 0;
	i = 0;
	while ((list->str[i] != '\n') && list)
	{
		if (list->str[i] == 0)
		{
			i = 0;
			list = list->next;
		}
		len++;
		i++;
	}
	return (len);
}
/*
#include <stdio.h> 
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	t_list *next;
	t_list	*list = read_fd(fd);
	while (list)
	{
		printf("list str: %s\n", list->str);
		next = list->next;
		free(list);
		list = next;
	}
	return (0);
}
*/
