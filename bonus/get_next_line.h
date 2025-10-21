/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:40:14 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/21 11:41:57 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*join_n_free(char *str, char *buf);
void	clean_house(char **strs);
char	*read_file(char *stash, int fd);
char	*get_the_line(char *stash);
char	*update_stash(char *stash);
char	*get_next_line(int fd);
size_t	has_nl(char *str);

#endif
