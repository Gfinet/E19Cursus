/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:09 by gfinet            #+#    #+#             */
/*   Updated: 2024/01/24 21:45:10 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_char(const char *src, int c)
{
	char		*p;
	size_t		len;
	size_t		i;

	if (src == NULL)
		return (0);
	len = 0;
	while (src[len] != c && src[len])
		len++;
	if (c == '\n')
		len++;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while ((&src[i]) != p + 1 && src[i] && i < len)
	{
		p[i] = src[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}

char	*read_one_line(char **rest, int *byte, int fd)
{
	char		*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (free_all(&(*rest), 0));
	*byte = read(fd, buff, BUFFER_SIZE);
	while (*byte > 0)
	{
		buff[*byte] = '\0';
		*rest = ft_strjoin(*rest, buff);
		if (!*rest)
			return (free_all(&(*rest), &buff));
		if (ft_strchr(buff, '\n'))
			break ;
		*byte = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (*rest);
}

void	empty_res(char **rest, char **result, int byte)
{
	char	*p;

	if (byte == -1)
	{
		free(*rest);
		*rest = NULL;
	}
	else
	{
		p = ft_strchr(*rest, '\n');
		*result = ft_strdup_char(*rest, '\n');
		if (*result == NULL)
		{
			free(*rest);
			*rest = NULL;
		}
		if (p && *rest != NULL)
		{
			p = ft_strdup(p + 1);
			free(*rest);
			if (p == NULL && *result != NULL)
				free_all(&(*result), 0);
			*rest = p;
		}
	}
}

char	*end_call(char **rest, int byte)
{
	char	*result;

	result = NULL;
	if (*rest == NULL)
		return (result);
	if (ft_strchr(*rest, '\n'))
		empty_res(rest, &result, byte);
	else
	{
		if (*rest != NULL && (*rest)[0] != '\0' && byte != -1)
			result = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	int			byte;

	if (BUFFER_SIZE < 1 || fd < 0 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	if (rest && ft_strchr(rest, '\n'))
		return (end_call(&rest, 1));
	if (read_one_line(&rest, &byte, fd))
		return (end_call(&rest, byte));
	else
		return (NULL);
}
