/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:10:42 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/19 14:25:09 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int	has_nl(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->str[i] == 0)
		{
			list = list->next;
			i = 0;
			continue ;
		}
		if (list->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	len_to_nl(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*out;
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	out = malloc(i + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

void	put_last_node(t_list **list, char *buf)
{
	t_list	*head;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->str = ft_strdup(buf);
	if (!new->str)
	{
		free(new);
		return ;
	}
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

void	clean_house(t_list **lst, t_list *new, char *buf)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	(*lst) = NULL;
	if (new->str[0])
		*lst = new;
	else
		free(new);
	free(buf);
}
