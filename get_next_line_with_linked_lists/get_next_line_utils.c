/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:10:42 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/14 23:11:50 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_nl(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i = 0;
		while (list->str[i] != 0)
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	put_last_node(t_list **list, char *buf)
{
	t_list	*new;
	t_list	*last;

	last = ft_lstlast(*list);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*list = new;
	else
		last->next = new;
	new->str = buf;
	new->next = NULL;
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
	{
		free(new);
		free(buf);
	}
}
