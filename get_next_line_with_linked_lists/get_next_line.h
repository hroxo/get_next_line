/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:09:52 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/19 13:56:23 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create_list(t_list **stash, int fd);
char	*to_line(t_list	*lst);
void	new_list(t_list **stash);
void	to_line_helper(t_list *lst, char *str);
int		len_to_nl(t_list *lst);
int		has_nl(t_list *list);
t_list	*create_node(char *str, int n);
void	to_line_helper(t_list *lst, char *str);
void	clean_house(t_list **lst, t_list *new, char *buf);
void	put_last_node(t_list **list, char *buf);
char	*ft_strdup(char *str);

#endif
