/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/14 14:47:20 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*sbuff;
	int				len;

	sbuff = NULL;
	sbuff = ft_r_read_line(fd, buff, sbuff);
	if (!sbuff)
		return (NULL);
	len = ft_strchr(sbuff, '\0') - sbuff;
	ft_strlcat(sbuff, "\n", len + BUFFER_SIZE);
	if (ft_strchr(buff, '\n'))
		ft_strlcpy(buff, ft_strchr(buff, '\n'), BUFFER_SIZE);
	return (sbuff);
}
