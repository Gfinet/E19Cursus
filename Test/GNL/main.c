#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd = open(argv[argc - 1], O_RDONLY);
	//int fd2 = open(argv[argc - 1], O_RDONLY);
	char *temp = get_next_line(fd);
	int i = 1;
	while (temp)
	{
		// printf("%i: %s\n", i++, temp);
		// free(temp);
		// temp = get_next_line(fd2);
		printf("%i: %s\n", i++, temp);
		free(temp);
		temp = get_next_line(fd);
	}
	return (0);
}

// int main(int argc, char **argv)
// BONUS BONUS BONUS
// {
// 	int fd = open(argv[argc - 1], O_RDONLY);
// 	int fd2 = open(argv[argc - 1], O_RDONLY);
// 	char *temp = get_next_line(fd);
// 	int i = 1;
// 	while (temp)
// 	{
// 		printf("%i: %s\n", i++, temp);
// 		free(temp);
// 		temp = get_next_line(fd2);
// 		printf("%i: %s\n", i++, temp);
// 		free(temp);
// 		temp = get_next_line(fd);
// 	}
// 	return (0);
// }