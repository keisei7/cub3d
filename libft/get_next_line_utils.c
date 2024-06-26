/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:49:37 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/09 08:46:22 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_str_line_len(char *str, char c)
{
	size_t	i;

	i = 0;
	if (c == 's')
	{
		while (str[i])
			i++;
		return (i);
	}
	else if (c == 'l')
	{
		while ((str[i] != '\n') && (str[i] != '\0'))
			i++;
		return (i);
	}
	return (0);
}

int	ft_strsearch(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_buf_zero(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		buf[i] = '\0';
		i++;
	}
}
