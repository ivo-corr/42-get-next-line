/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:35 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/19 10:26:49 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_stash(char **sbuff)
{
	if (*sbuff)
		free(*sbuff);
	*sbuff = NULL;
	return (NULL);
}

char	*expand_sbuff(char *current, char *buff)
{
	char	*new;
	int		len;

	if (!current)
	{
		new = malloc((BUFFER_SIZE + 2) * sizeof(char));
		if (new)
			ft_cpycat(new, buff, BUFFER_SIZE + 2, 0);
	}
	else
	{
		len = (ft_strchr(current, '\0') - current);
		new = malloc((len + BUFFER_SIZE + 2) * sizeof(char));
		if (new)
		{
			ft_cpycat(new, current, len + BUFFER_SIZE + 1, 0);
			ft_cpycat(new, buff, len + BUFFER_SIZE + 1, 1);
		}
		free_stash(&current);
	}
	return (new);
}

char	*ft_r_read_line(int fd, char *buff, char *sbuff, int *bread)
{
	*bread = read(fd, buff, BUFFER_SIZE);
	if (*bread < 0)
		return (free_stash(&sbuff));
	buff[*bread] = '\0';
	if (*bread == 0)
		return (sbuff);
	if (ft_strchr(buff, NL))
	{
		sbuff = expand_sbuff(sbuff, buff);
		return (sbuff);
	}
	else
	{
		sbuff = expand_sbuff(sbuff, buff);
		sbuff = ft_r_read_line(fd, buff, sbuff, bread);
	}
	return (sbuff);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

void	ft_cpycat(char *dst, const char *src, size_t size, int m)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((m == 0 && !(size == 0)) && i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (m == 0 && size > 0)
		*(dst + i) = '\0';
	else if (m == 1)
	{
		i = ft_strchr(dst, '\0') - dst;
		j = 0;
		while (size != 0 && (i + j < size - 1) && src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
		if (i < size)
			dst[i + j] = '\0';
	}
}
