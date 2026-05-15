/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/15 12:29:07 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static int		bread;
	char			*sbuff;
	int				len;

	sbuff = NULL;
	sbuff = ft_r_read_line(fd, buff, sbuff, &bread);
	if (!sbuff)
		return (NULL);
	len = ft_strchr(sbuff, '\0') - sbuff;
	if (bread == BUFFER_SIZE)
		ft_strlcat(sbuff, "\n", len + 2);
	if (ft_strchr(buff, NL))
		ft_strlcpy(buff, ft_strchr(buff, NL), BUFFER_SIZE);
	return (sbuff);
}
