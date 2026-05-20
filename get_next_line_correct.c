/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:32 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/20 17:14:44 by icorrale         ###   ########.fr       */
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
			return (NULL);
		ft_cpycat(l, stash, ft_strchr(stash, '\n') - stash + 1, 0);
		ft_cpycat(l, "\n", (ft_strchr(stash, '\n') - stash) + 2, 1);
		ft_cpycat(stash, ft_strchr(stash, NL) + 1, slen + 1, 0);
		return (l);
	}
	else
	{
		l = malloc((ft_strchr(stash, '\0') - stash) + 1 * sizeof(char));
		if (!l)
			return (NULL);
		ft_cpycat(l, stash, slen + 1, 0);
		*stash = '\0';
		return (l);
	}
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1];
	static int		bread = BUFFER_SIZE;
	static char		*sbuff = NULL;
	char			*tmp;

	if ((sbuff && ft_strchr(sbuff, '\n')))
	{
		tmp = extract_line(sbuff);
		if (!tmp)
		{
			free(sbuff);
			sbuff = NULL;
			return (NULL);
		}
		return (tmp);
	}
	sbuff = ft_r_read_line(fd, buff, sbuff, &bread);
	if (!sbuff)
		return (NULL);
	if (*sbuff == '\0' || bread == -1)
	{
		bread = BUFFER_SIZE;
		return (free_stash(&sbuff));
	}
	tmp = extract_line(sbuff);
	if (!tmp)
	{
		free(sbuff);
		sbuff = NULL;
		return (NULL);
	}
	return (tmp);
}
