/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:54:50 by snegi             #+#    #+#             */
/*   Updated: 2023/11/30 15:54:52 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*res;
	int		i;
	int		j;

	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total + 1));
	if (!res)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int ch )
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str != ch && *str != 0)
		str++;
	if (*str == ch)
		return (str);
	else
		return (NULL);
}
