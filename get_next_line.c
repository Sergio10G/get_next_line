/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:09:58 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/24 20:17:41 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (saved != 0)
	{
		if (ft_strchr(saved, '\n') != 0)
			return (save_and_out(&saved));
	}
	return (read_till_has_nl(fd, &saved));
}

char	*read_till_has_nl(int fd, char **saved)
{
	char	*temp;
	int		read_chars;

	read_chars = -1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (0);
	while (read_chars != 0)
	{
		read_chars = read(fd, temp, BUFFER_SIZE);
		if (read_chars < 1)
			break ;
		if (*saved)
			*saved = ft_strjoin(*saved, temp);
		else
			*saved = ft_substr(temp, 0, ft_strlen(temp));
	}
	free(temp);
	if (!saved || !*saved)
		return (0);
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
	if (*saved)
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
