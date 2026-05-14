/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/14 14:25:01 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	char			*sbuff;

	sbuff = NULL;
	sbuff = ft_r_read_line(fd, buff, sbuff);
	if (!sbuff)
		return (NULL);
	ft_strlcat(sbuff, "\n", ft_strchr(sbuff, '\0') - sbuff + 1);
	if (ft_strchr(buff, '\n'))
		ft_strlcpy(buff, ft_strchr(buff, '\n'), BUFFER_SIZE);
	return (sbuff);
}
