/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amabrouk <amabrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:22:49 by amabrouk          #+#    #+#             */
/*   Updated: 2023/12/17 11:13:32 by amabrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char	*s)
{
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || start > ft_strlen(s) || len == 0)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out_str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	out_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out_str)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		out_str[i] = s1[i];
	j = -1;
	while (s2[++j])
		out_str[i++] = s2[j];
	out_str[i] = '\0';
	return (free(s1), s1 = NULL, out_str);
}
