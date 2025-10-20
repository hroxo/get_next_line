/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:02:22 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/20 18:09:31 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
size_t	has_nl(char *str);
void	clean_house(char **strs);
char	*read_file(char *stash, int fd);
char	*get_line(char *stash);
char	*update_stash(char *stash);
char	*get_next_line(int fd);

#endif
