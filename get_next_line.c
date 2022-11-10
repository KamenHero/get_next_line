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
	char	*s;
	int		i;

	i = 1;
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (ft_strchr(str) == 0 && i != 0)
	{
		i = read(fd, s, BUFFER_SIZE);
		s[i] = 0;
		str = ft_strjoin(str, s);
	}
	free(s);
	return (str);
}

char	*ft_spliter(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
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
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(line) - i));
	while (line[j + i + 1])
	{
		str[j] = line[j + i + 1];
		j++;
	}
	free (line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_line(str, fd);
	line = ft_spliter(str);
	str = ft_first(str);
	return (line);
}

int main()
{
	char *s;
	char *d;
	int fd;
	fd  = fileno(fopen ("test.txt","r"));
	s = get_next_line(fd);
	d = get_next_line(fd);
	printf("%s",s);
	printf("%s",d);
}
