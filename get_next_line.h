/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:02:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/25 17:30:24 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//	Libraries
# include <stdlib.h>
# include <unistd.h>

// Functions
	/* get_next_line.c functions */
char	*get_next_line(int fd);
char	*read_till_has_nl(int fd, char **saved);
char	*save_and_out(char **saved);
char	*out_no_nl(char **saved);
char	*read_out(char **saved);

	/* get_next_line_utils.c functions */
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
