/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:35 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/21 11:09:30 by icorrale         ###   ########.fr       */
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
		new = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!new)
			return (NULL);
		else
			ft_cpycat(new, buff, BUFFER_SIZE + 1, 0);
	}
	else
	{
		len = (ft_strchr(current, '\0') - current);
		new = malloc((len + BUFFER_SIZE + 1) * sizeof(char));
		if (!new)
			return (free(current), NULL);
		else
		{
			ft_cpycat(new, current, len + BUFFER_SIZE, 0);
			ft_cpycat(new, buff, len + BUFFER_SIZE + 1, 1);
		}
		free(current);
	}
	return (new);
}

char	*ft_r_read_line(int fd, char *buff, char *sbuff, int *bread)
{
	*bread = read(fd, buff, BUFFER_SIZE);
	if (*bread < 0)
		return (free(sbuff), NULL);
	if (*bread == 0)
		return (sbuff);
	buff[*bread] = '\0';
	sbuff = expand_sbuff(sbuff, buff);
	if (!sbuff)
		return (NULL);
	if (ft_strchr(buff, NL))
		return (sbuff);
	else
		sbuff = ft_r_read_line(fd, buff, sbuff, bread);
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
