/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/04/19 04:58:26 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean(char *buff, int times)
{
	while (times >= 0)
	{
		*buff = '\0';
		times--;
		buff++;
	}
}

char	*get_next_line(int fd)
{
	static char	*r;
	char		*t;
	char		*b;
	int			cread;
	char		buff [BUFFER_SIZE + 1];
	char		*line;

	b = 0;
	if ((fd < 0) || (BUFFER_SIZE < 1) || (BUFFER_SIZE > INT_MAX))
		return (0);
	if ((r != 0) && (*r != '\0'))
	{
		if (eloc(r) > -1)
		{
			line = ft_substr(r, 0, eloc(r));
			if ((eloc(r)) < ft_strlen(r))
			{
				t = r;
				r = ft_substr(r, eloc(r), ft_strlen(r) - eloc(r));
				free(t);
				t = 0;
			}
			else
			{
				free(r);
				r = 0;
			}
			return (line);
		}
		else
		{
			b = ft_substr(r, 0, ft_strlen(r));
			free(r);
			r = 0;
		}
	}
	clean(buff, BUFFER_SIZE);
	cread = read(fd, buff, BUFFER_SIZE);
	while ((cread == BUFFER_SIZE) && (eloc(buff) == -1))
	{
		if ((b != 0) && (*b != '\0'))
		{
			t = b;
			b = ft_strjoin(b, buff);
			free(t);
			t = 0;
		}
		else
			b = ft_substr(buff, 0, ft_strlen(buff));
		clean(buff, BUFFER_SIZE);
		cread = read(fd, buff, BUFFER_SIZE);
	}
	if (cread < 0)
	{
		if ((b != 0) && (*b != '\0'))
		{
			free(b);
			b = 0;
		}
		return (0);
	}
	else if (cread == 0)
	{
		if ((b != 0) && (*b != '\0'))
			return (b);
		else
			return (0);
	}
	else if ((cread > 0) && (cread < BUFFER_SIZE))
	{
		if ((b != 0) && (*b != '\0'))
		{
			line = ft_strjoin (b, buff);
			free(b);
			b = 0;
		}
		else
			line = ft_substr (buff, 0, ft_strlen(buff));
		if (eloc(line) > -1)
		{
			t = line;
			line = ft_substr (line, 0, eloc(line));
			if ((eloc(buff)) < ft_strlen(buff))
				r = ft_substr(t, eloc(t), ft_strlen(t) - eloc(t));
			free(t);
			t = 0;
		}
		return (line);
	}
	else
	{
		line = ft_substr(buff, 0, eloc(buff));
		if ((eloc(buff)) < (ft_strlen(buff)))
			r = ft_substr(buff, eloc(buff), ft_strlen(buff) - eloc(buff));
		if ((b != 0) && (*b != '\0'))
		{
			t = line;
			line = ft_strjoin(b, line);
			free(t);
			t = 0;
			free (b);
			b = 0;
		}
		return (line);
	}
}
