/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyazawa.kai.0823 <miyazawa.kai.0823@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:06:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/06/25 15:58:29 by miyazawa.ka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*free_buf(char *buf)
{
	free(buf);
	buf = NULL;
	return (buf);
}

void	*join_bufs(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*s3;

	if (!s1)
	{
		s3 = strndup(s2, ft_str_line_len(s2, 's'));
		if (s3 == NULL)
			return (NULL);
		return (s3);
	}
	s3 = calloc(ft_str_line_len(s1, 's') + ft_str_line_len(s2, 's') + 1,
			sizeof(char));
	if (s3 == NULL)
		return (free_buf(s1));
	i = 0;
	j = 0;
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	free_buf(s1);
	return (s3);
}

char	*ready_for_next(char *buf)
{
	size_t	i;
	size_t	j;
	char	*buf_next;

	if ((buf[ft_str_line_len(buf, 'l')] == '\0')
		|| (buf[ft_str_line_len(buf, 'l') + 1] == '\0'))
		return (free_buf(buf));
	buf_next = calloc((ft_str_line_len(buf, 's')
				- ft_str_line_len(buf, 'l')), sizeof(char));
	if (buf_next == NULL)
		return (free_buf(buf));
	i = ft_str_line_len(buf, 'l') + 1;
	j = 0;
	while (buf[i])
	{
		buf_next[j++] = buf[i++];
	}
	buf_next[j] = '\0';
	buf = free_buf(buf);
	return (buf_next);
}

char	*after_read(char **buf_p, char *buf_tmp, int flag_checking_line,
		ssize_t bytes)
{
	char	*buf_result;

	if (flag_checking_line == 1 || (*buf_p != NULL && bytes == 0))
	{
		buf_result = strndup(*buf_p, ft_str_line_len(*buf_p, 'l') + 1);
		*buf_p = ready_for_next(*buf_p);
		buf_tmp = free_buf(buf_tmp);
		return (buf_result);
	}
	if (bytes == 0 && *buf_p == NULL)
	{
		free_buf(buf_tmp);
		return (*buf_p);
	}
	else if (bytes < 0)
	{
		*buf_p = free_buf(*buf_p);
		free_buf(buf_tmp);
		return (*buf_p);
	}
	*buf_p = free_buf(*buf_p);
	free_buf(buf_tmp);
	return (*buf_p);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*buf_tmp;
	int			flag_checking_line;
	ssize_t		bytes;

	if ((fd < 3) && (fd != 0))
		return (NULL);
	buf_tmp = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf_tmp == NULL)
		return (NULL);
	flag_checking_line = 0;
	while (flag_checking_line == 0)
	{
		bytes = read(fd, buf_tmp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		if (ft_strsearch(buf_tmp, '\n'))
			flag_checking_line = 1;
		buf = join_bufs(buf, buf_tmp);
		if (buf == NULL)
			return (free_buf(buf_tmp));
		ft_buf_zero(buf_tmp);
	}
	return (after_read(&buf, buf_tmp, flag_checking_line, bytes));
}
