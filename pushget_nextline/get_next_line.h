/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:43:48 by agallell          #+#    #+#             */
/*   Updated: 2023/02/24 23:43:57 by agallell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);
int				ft_putindex(const char *s, char c);
char			*ft_strdup(const char *src);

#endif
