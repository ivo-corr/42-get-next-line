/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:35 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/15 12:21:09 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*expand_sbuff(char *current, char *buff, int bytes)
{
	char	*new;
	int		len;

	(void)bytes;
	if (!current)
	{
		new = malloc((BUFFER_SIZE + 2) * sizeof(char));
		if (new)
			ft_strlcpy(new, buff, BUFFER_SIZE + 2);
	}
	else
	{
		len = (ft_strchr(current, '\0') - current);
		new = malloc((len + BUFFER_SIZE + 2) * sizeof(char));
		if (new)
		{
			ft_strlcpy(new, current, len + BUFFER_SIZE + 1);
			if (ft_strchr(buff, '\n'))
				ft_strlcat(new, buff, len + ft_strchr(buff, '\n') - buff + 1);
			else
				ft_strlcat(new, buff, len + BUFFER_SIZE + 1);
		}
		free(current);
	}
	return (new);
}

char	*ft_r_read_line(int fd, char *buff, char *sbuff, int *bread)
{
	if (buff[0] && ft_strchr(buff, '\n'))
	{
		sbuff = expand_sbuff(sbuff, buff, BUFFER_SIZE);
		ft_strlcpy(buff, ft_strchr(buff, '\n') + 1, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
			return (sbuff);
	}
	*bread = read(fd, buff, BUFFER_SIZE);
	if ((*bread <= 0) && (!buff[0] && !sbuff))
		return (NULL);
	if (*bread == 0)
		return (sbuff);
	if (ft_strchr(buff, '\n') || *bread < BUFFER_SIZE)
		sbuff = expand_sbuff(sbuff, buff, *bread);
	else
	{
		sbuff = expand_sbuff(sbuff, buff, *bread);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (size != 0 && (i + j < size - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dst[i + j] = '\0';
		return (i + (ft_strchr(src, '\0') - src));
	}
	return (size + (ft_strchr(src, '\0') - src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return ((ft_strchr(src, '\0') - src));
	i = 0;
	while (i < (size - 1) && src[i])
	{
		if (*(src + i) == '\n')
			break ;
		*(dst + i) = *(src + i);
		i++;
	}
	if (size > 0)
		*(dst + i) = '\0';
	return ((ft_strchr(src, '\0') - src));
}
