/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/12 09:20:53 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*sbuff;

	sbuff = NULL;
	sbuff = ft_r_read_line(fd, sbuff);
	return (sbuff);
}

int	main(void)
{
	int	myfile = open("README.md", O_RDONLY);
	int	i;

	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	get_next_line(myfile);
	close(myfile);
}