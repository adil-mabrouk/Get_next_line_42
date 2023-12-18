/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:36:45 by amabrouk          #+#    #+#             */
/*   Updated: 2023/12/18 09:12:29 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*copy;
	int		i;

	if (!s)
		return (NULL);
	copy = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (s[++i])
		copy[i] = s[i];
	copy[i] = 0;
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2) + 1));
	if (!out)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		out[i] = s1[i];
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = 0;
	return (free(s1), s1 = NULL, out);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char	*put;
	int		i;

	if (!s || len == 0 || start > ft_strlen(s))
		return (NULL);
	i = 0;
	put = malloc(sizeof(char) * (len + 1));
	if (!put)
		return (NULL);
	while (s[start + i] && len--)
	{
		put[i] = s[i + start];
		i++;
	}
	put[i] = 0;
	return (put);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&s[i]);
	return (NULL);
}
