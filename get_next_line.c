/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:11:20 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/01/21 19:28:58 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;

	if (saved)
	{
	 	if (ft_strchr(saved, '\n') != 0)
			return (out_and_save(&saved));
	}
	return (read_till_has_nl(fd, &saved));
}

char	*read_till_has_nl(int fd, char **saved)
{
	char	*temp;
	int		found_nl;
	int		read_chars;

	found_nl = 0;
	while (!found_nl)
	{
		temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		temp[BUFFER_SIZE] = '\0';
		read_chars = read(fd, temp, BUFFER_SIZE);
		if (read_chars == 0)
			break ;
		if ((*saved))
			*saved = ft_strjoin(*saved, temp);
		else
			*saved = ft_strdup(temp);
		free(temp);
		if (ft_strchr(*saved, '\n'))
			found_nl = 1;
	}
	if (found_nl)
		return (out_and_save(saved));
	return (out_no_nl(saved));
}

char	*out_and_save(char **saved)
{
	char	*out;
	char	*save_temp;
	int		i;

	i = 0;
	while ((*saved)[i] != '\n')
		i++;
	out = malloc((i + 2) * sizeof(char));
	ft_memcpy(out, (*saved), i + 1);
	save_temp = ft_strdup((*saved) + i + 1);
	free(*saved);
	*saved = save_temp;
	return (out);
}

char	*out_no_nl(char **saved)
{
	char	*out;

	out = ft_strdup(*saved);
	free(*saved);
	return (out);
}
