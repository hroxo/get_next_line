/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:48:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/10 18:08:29 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

int has_nl(char *str);
size_t  ft_strlen(char *str);
char    *get_next_line(int fd);
char    *ft_strncat(char *new, char *original, size_t nb);
size_t	len_to_nl(char	*str);
char	*ft_strdup(char *str);

#endif
