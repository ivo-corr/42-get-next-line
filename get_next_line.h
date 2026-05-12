/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:44 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/11 19:34:27 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
// #define BUFFER_SIZE 5

// typedef struct s_list
// {
// 	char			content[2 * BUFFER_SIZE];
// 	struct s_list	*lcontent;
// 	int				fd_num;
// 	struct s_list	*next;
// }	t_list;

char	*get_next_line(int fd);
char	*ft_r_read_line(int fd, char *sbuff);
char	*expand_sbuff(char *current, char *buff, int bytes);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
