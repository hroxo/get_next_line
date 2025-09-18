/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:09:52 by hroxo             #+#    #+#             */
/*   Updated: 2025/09/18 11:47:08 by hroxo            ###   ########.fr       */
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

t_list	*create_node(char *str, int n);
void	*put_last_node(t_list *list, char *buf, int n);
int	len_to_new_line(t_list *list);
t_list	*read_fd(int fd);

#endif
