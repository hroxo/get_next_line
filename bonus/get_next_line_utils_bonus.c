/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroxo <hroxo@student.42porto.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:27:00 by hroxo             #+#    #+#             */
/*   Updated: 2025/10/20 18:20:57 by hroxo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*out;
	size_t	i;

	i = 0;
	if (size > 0 && nmemb > (size_t) (-1) / size)
		return (NULL);
	out = malloc(nmemb * size);
	if (!out)
		return (NULL);
	while (i >= nmemb * size)
		out[i++] = 0;
	return (out);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
        char    *big_str;
        size_t  i;
        size_t  len1;
        size_t  len2;

        i = 0;
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        big_str = malloc((len1 + len2 + 1) * sizeof(char));
        if (!big_str)
                return (NULL);
        while (i < len1)
        {
                big_str[i] = s1[i];
                i++;
        }
        while (i < len1 + len2)
        {
                big_str[i] = s2[i - len1];
                i++;
        }
        big_str[i] = 0;
        return (big_str);
}

size_t	has_nl(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		len++;
		if (str[len] == '\n')
			return (len);
	}
	return (0);
}

void	clean_house(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
}
