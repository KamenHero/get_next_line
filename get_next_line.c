/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:45:56 by oryadi            #+#    #+#             */
/*   Updated: 2022/11/10 00:45:58 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str, int fd)
{
	char	*BUFF;
	BUFF = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!BUFF)
		return (NULL);
	while (ft_strchr(str) != 0)
	{
		read(fd, BUFF, BUFFER_SIZE);
		str = ft_strjoin(str, BUFF);
	}
	free(BUFF);
	return (str);
}

char	*ft_spliter(char *str)
{
	int		i;
	char *line;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_first(char *line)
{
	char	*str;
	size_t 	i;
	size_t	lenline;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (lenline - i));
	while (line[i])
	{
		str[j] = line[j + i + 1];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_line(str, fd);
	line = ft_spliter(str);
	free(str);
	str = ft_first(line);
	return (line);
}

int main()
{
	FILE *f = fopen ("test.txt","w");
}
