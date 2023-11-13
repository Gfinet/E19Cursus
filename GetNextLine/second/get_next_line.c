/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:09 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/13 17:30:46 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup_char(const char *src, int c)
{
	char		*p;
	size_t		len;
	size_t		i;

	if (!src)
		return (0);
	len = 0;
	while (src[len] != c && src[len])
		len++;
	p = (char *)malloc((len + 2) * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while ((&src[i]) != p + 1  && src[i] && i < len + 1)
	{
		p[i] = src[i];
		i++;
	}
	p[len + 1] = '\0';
	return (p);
}

char	*empty_res(char **rest, char **result)
{
	char	*p;

	p = ft_strchr(*rest, '\n');
	if (p)
	{
		*result = ft_strdup_char(p + 1, '\n');
		if (!*result)
			return (NULL);
		p = ft_strdup(p + 1);
		if (!p)
			return (free_all(*result, 0, 0));
		free(*rest);
		*rest = p;
		return (*result);
	}
	return ("a");
}

char	*end_call(char **buff, char **rest, int byte)
{
	char	*result;

	if (ft_strchr(*rest, '\n'))
	{
		result = ft_strdup_char(*rest, '\n');
		if (!result)
			result = NULL;
	}
	else
	{
		if (byte == -1)
		{
			result = ft_strdup(*rest);
			free(*rest);
		}
	}
	//free(*buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*result;
	char		*buff;
	char		*tmp;
	int			byte;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (rest != NULL)
	{
		result = empty_res(&rest, &result);
		if (result == NULL || ft_strchr(result, '\n'))
			return (result);
	}
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	byte = read(fd, buff, BUFFER_SIZE);
	while (byte > 0)
	{
		buff[byte] = '\0';
		tmp = ft_strjoin(rest, buff);
		if (!tmp)
			return (free_all(tmp, buff, 0));
		rest = ft_strdup(tmp);
		if (!rest)
			return (free_all(rest, tmp, buff));
			free(tmp);
		if (!ft_strchr(buff, '\n'))
			byte = read(fd, buff, BUFFER_SIZE);
		else
			byte = 0;
	}
	return (end_call(&buff, &rest, byte));
}