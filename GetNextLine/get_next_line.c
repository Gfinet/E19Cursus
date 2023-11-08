/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:03:09 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/08 19:20:08 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char *tmp, char *result)
{
	free(tmp);
	free(result);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*result;
	char		*tmp;
	int			byte;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE * sizeof(char));
	byte = read(fd, buff, BUFFER_SIZE);
	while (byte)
	{
		tmp = ft_strnjoin(result, buff, BUFFER_SIZE);
		if (!tmp)
			return (free_all(tmp, result));
		result = ft_strjoin(result, tmp);
		if (!result)
			return (free_all(tmp, result));
		//free(tmp);
		byte = read(fd, buff, BUFFER_SIZE);
	}
	return (result);
}
