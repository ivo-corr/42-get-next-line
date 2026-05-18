/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/18 16:47:23 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *stash)
{
	char	*l;
	int		slen;

	slen = ft_strchr(stash, '\0') - stash;
	if (ft_strchr(stash, '\n'))
	{
		l = malloc((ft_strchr(stash, '\n') - stash) + 2 * sizeof(char));
		if (!l)
		{
			return (free_stash(stash));
		}
		ft_cpycat(l, stash, ft_strchr(stash, '\n') - stash + 1, 0);
		ft_cpycat(l, "\n", (ft_strchr(stash, '\n') - stash) + 2, 1);
		ft_cpycat(stash, ft_strchr(stash, NL) + 1, slen + 2, 0);
		return (l);
	}
	else
		return (stash);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static int		bread = BUFFER_SIZE;
	static char		*sbuff = NULL;

	if (bread <= 0)
	{
		bread = BUFFER_SIZE;
		return (NULL);
	}
	if ((sbuff && ft_strchr(sbuff, '\n')))
		return (extract_line(sbuff));
	sbuff = ft_r_read_line(fd, buff, sbuff, &bread);
	if (!sbuff || *sbuff == '\0' || bread == -1)
	{
		bread = BUFFER_SIZE;
		return (free_stash(sbuff));
	}
	return (extract_line(sbuff));
}
