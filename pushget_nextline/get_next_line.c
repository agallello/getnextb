/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:30:32 by agallell          #+#    #+#             */
/*   Updated: 2023/02/24 23:49:36 by agallell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_forline(char *backup)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	if (*backup == '\0')
		return (NULL);
	while (backup[len] && backup[len] != '\n')
		len++;
	if (backup[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_back(char *backup)
{
	char	*str;
	int		start;
	int		j;

	start = 0;
	while (backup[start] && backup[start] != '\n')
		start++;
	if (backup[start] == '\n')
		start++;
	if (backup[start] == '\0')
	{
		free(backup);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(backup) - start + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (backup[start])
		str[j++] = backup[start++];
	str[j] = '\0';
	free(backup);
	return (str);
}

static char	*read_forline(char *backup, int fd)
{
	int		byte;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_putindex(backup, '\n') == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (BUFFER_SIZE == 0)
	{
		exit(1);
		return (NULL);
	}
	backup = read_forline(backup, fd);
	if (!backup)
		return (NULL);
	line = get_forline(backup);
	backup = get_back(backup);
	return (line);
}
