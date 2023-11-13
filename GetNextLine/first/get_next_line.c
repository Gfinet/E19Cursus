/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:09 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/13 16:07:59 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strdup_char(const char *src, int c)
{
	char		*p;
	char		*d;
	size_t		len;
	size_t		i;

	if (!src)
		return (0);
	len = 0;
	while (src[len] != c && src[len])
		len++;
	d = ft_strchr(src, c);
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

char	*end_call(char **buff, char **rest)
{
	char	*result;

	if (ft_strchr(*rest, '\n'))
	{
		result = ft_strdup_char(*rest, '\n');
		if (!result)
			result = NULL;
	}
	else if (ft_strchr(*rest, '\0'))
	{
		result = ft_strdup_char(*rest, '\0');
		if (!result)
			result = NULL;
		free(*rest);
	}
	free(*buff);
	return (result);

}

int ft_empty_stat(char **rest, char **result, char **buff)
{
	char	*p;

	p = ft_strchr(*rest, '\n');
	if (p)
	{
		*result = ft_strdup_char(p + 1, '\n');
		if (!*result)
		{
			free_all(*buff, 0, 0);
			return (1);
		}
		p = ft_strdup(p + 1);
		if (!p)
		{
			free_all(*buff, *result, 0);
			return (1);
		}
		free(*rest);
		*rest = p;
		if ((*result)[0] == '\n' && ft_strlen(*result) == 1)
			return (1);
	}
	return (0);
}



char	*get_next_line(int fd)
{
	static char		*rest = NULL;
	char			*result;
	char			*buff;
	char			*tmp;
	int				byte;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	byte = 0;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (ft_empty_stat(&rest, &result, &buff))
		return (result);
	byte = read(fd, buff, BUFFER_SIZE);
	while (byte > 0)
	{
		buff[byte] = '\0';
		tmp = ft_strjoin(rest, buff);
		if (!tmp)
			return (free_all(tmp, buff, 0));
		//printf("\ntmp = %s", tmp);
		rest = ft_strdup(tmp);
		if (!rest)
			return (free_all(rest, tmp, buff));
		free(tmp);
		if (!ft_strchr(buff, '\n'))
			byte = read(fd, buff, BUFFER_SIZE);
		else
			byte = 0;
	}
	return (end_call(&buff, &rest));
}
