/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:20:57 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/27 18:15:24 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*saved[MAX_FDS];

	if (fd < 0 || fd > MAX_FDS || BUFFER_SIZE < 1)
		return (0);
	if (saved[fd] != 0 && ft_strchr(saved[fd], '\n') != 0)
		return (save_and_out(saved + fd));
	return (read_till_has_nl(fd, saved));
}

char	*read_till_has_nl(int fd, char **saved)
{
	char	*temp;
	int		read_chars;

	read_chars = 1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (0);
	while (read_chars > 0)
	{
		read_chars = read(fd, temp, BUFFER_SIZE);
		if (read_chars == -1)
			break ;
		temp[read_chars] = '\0';
		if (read_chars < 1)
			break ;
		if (saved[fd])
			saved[fd] = ft_strjoin(saved[fd], temp);
		else
			saved[fd] = ft_substr(temp, 0, read_chars);
		if (ft_strchr(saved[fd], '\n') != 0)
			break ;
	}
	free(temp);
	return (read_out(saved + fd));
}

char	*read_out(char **saved)
{
	if (!*saved || (*saved)[0] == '\0')
	{
		free(*saved);
		*saved = 0;
		return (0);
	}
	if (ft_strchr(*saved, '\n') != 0)
		return (save_and_out(saved));
	return (out_no_nl(saved));
}

char	*save_and_out(char **saved)
{
	char	*temp;
	char	*out;
	int		nl_index;

	nl_index = 0;
	while ((*saved)[nl_index] && (*saved)[nl_index] != '\n')
		nl_index++;
	out = ft_substr(*saved, 0, nl_index + 1);
	temp = ft_substr(*saved, nl_index + 1, ft_strlen(*saved));
	if (!out || !temp)
		return (0);
	free(*saved);
	*saved = ft_substr(temp, 0, ft_strlen(temp));
	free(temp);
	return (out);
}

char	*out_no_nl(char **saved)
{
	char	*out;

	out = ft_substr(*saved, 0, ft_strlen(*saved));
	free(*saved);
	*saved = 0;
	return (out);
}
