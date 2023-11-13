/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:14:50 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/12 22:35:52 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include "fcntl.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char buffer;
	char	*res;
	int n = 13;

	fd = open("exemple.txt", O_RDONLY);
	while ((res = get_next_line(fd)) && n--)
	{
		printf("%s", res);
		//free(res);
	}
	// while (read(fd,&buffer,1))
	// 	write(1, &buffer, 1);
	close(fd);
	return (0);
}


/*


*/