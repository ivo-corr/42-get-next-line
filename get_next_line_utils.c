/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:35 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/14 11:32:05 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*expand_sbuff(char *current, char *buff, int bytes)
{
	char	*new;
	int		len;

	if (!current)
	{
		new = malloc(2 * BUFFER_SIZE * sizeof(char));
		if (new)
			ft_strlcpy(new, buff, (2 * BUFFER_SIZE) + 1);
	}
	else
	{
		len = (ft_strchr(current, '\0') - current) + BUFFER_SIZE + 1;
		new = malloc(len * sizeof(char));
		if (new)
		{
			ft_strlcpy(new, current, len);
			ft_strlcat(new, buff, (ft_strchr(current, '\0') - current) + bytes);
		}
		free(current);
	}
	if (ft_strchr(new, '\n'))
		*(ft_strchr(new, '\n') + 1) = '\0';
	return (new);
}

char	*ft_r_read_line(int fd, char *buff, char *sbuff)
{
	// static char		buff[BUFFER_SIZE];
	int	bread;

	if (buff[0] && ft_strchr(buff, '\n'))
	{
		ft_strlcpy(buff, ft_strchr(buff, '\n') + 1, BUFFER_SIZE);
		sbuff = expand_sbuff(sbuff, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
			return (sbuff);
	}
	bread = read(fd, buff, BUFFER_SIZE);
	if ((bread <= 0) && (!buff[0] && !sbuff))
		return (NULL);
	if (ft_strchr(buff, '\n') || bread < BUFFER_SIZE)
		sbuff = expand_sbuff(sbuff, buff, bread);
	else
	{
		sbuff = expand_sbuff(sbuff, buff, bread);
		sbuff = ft_r_read_line(fd, buff, sbuff);
	}
	return (sbuff);
}

// char	*ft_r_read_line(int fd, char *sbuff)
// {
// 	static char		buff[BUFFER_SIZE];
// 	static int		curr_index = 0;
// 	char			next_char;

// 	next_char = 0;
// 	if ((read(fd, &next_char, 1) <= 0) && (!buff[0] && !sbuff))
// 		return (NULL);
// 	if (curr_index >= BUFFER_SIZE)
// 	{
// 		sbuff = expand_sbuff(sbuff, buff);
// 		curr_index = 0;
// 	}
// 	if (next_char == '\n' || next_char == 0)
// 	{
// 		buff[curr_index++] = next_char;
// 		sbuff = expand_sbuff(sbuff, buff);
// 		curr_index = 0;
// 	}
// 	else
// 	{
// 		buff[curr_index++] = next_char;
// 		sbuff = ft_r_read_line(fd, sbuff);
// 	}
// 	*buff = 0;
// 	return (sbuff);
// }

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
		*(dst + i) = *(src + i);
		i++;
	}
	if (size > 0)
		*(dst + i) = '\0';
	return ((ft_strchr(src, '\0') - src));
}
