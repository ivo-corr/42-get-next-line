/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icorrale <icorrale@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 09:57:44 by icorrale          #+#    #+#             */
/*   Updated: 2026/05/19 10:27:10 by icorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define NL '\n'

char	*get_next_line(int fd);
char	*ft_r_read_line(int fd, char *buff, char *sbuff, int *bread);
char	*expand_sbuff(char *current, char *buff);
char	*ft_strchr(const char *s, int c);
void	ft_cpycat(char *dst, const char *src, size_t size, int m);
void	*free_stash(char **sbuff);

#endif