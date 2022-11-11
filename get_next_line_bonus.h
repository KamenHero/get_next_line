/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:36:42 by oryadi            #+#    #+#             */
/*   Updated: 2022/11/11 00:36:43 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s);
char	*ft_line(char *str, int fd);
char	*ft_spliter(char *line);
char	*ft_first(char *str);
char	*ft_strdup(char *s);

#endif
