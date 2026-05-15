/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:24:27 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/15 16:25:29 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>

// int main(void)
// {
// 	int		fd;
// 	int		count;
// 	char	*next_line;

// 	count = 0;
// 	fd = open("files/test.txt", O_RDONLY);
// 	while (count < 10)
// 	{
// 		next_line = get_next_line(fd);
// 		count++;
// 		printf("[%d]: %s\n", count, next_line);
// 		if (!next_line)
// 			break ;
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
int	main(void)
{
	int	fd;
	
	fd = open("files/test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}