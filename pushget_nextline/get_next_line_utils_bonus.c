/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:56:14 by agallell          #+#    #+#             */
/*   Updated: 2023/02/24 23:56:19 by agallell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_putindex(const char *s, char c)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	num;

	num = 0;
	while (str[num] != '\0')
		num++;
	return (num);
}

char	*ft_strdup(const char *src)

{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(src);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	x;

	if (!s1)
		s1 = ft_strdup("");
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x])
		string[i++] = s2[x++];
	string[i] = 0;
	free(s1);
	return (string);
}
