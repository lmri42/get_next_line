/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/04/15 18:36:41 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> 
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*temp;
	char		*bag;
	int			cread;
	char		buffer [BUFFER_SIZE + 1];
	char		*line;

	bag = 0;
//	printf ("Remains from previous:\n\"%s\"\n", remain);
	if ((fd < 0) || (BUFFER_SIZE < 1) || (BUFFER_SIZE > INT_MAX))
		return (0);
	if ((remain != 0) && (*remain != '\0'))
	{
		if (eloc(remain) > -1)
		{
			line = ft_substr(remain, 0, eloc(remain)); //CHECK
			if ((eloc(remain) + 1) < ft_strlen(remain))
			{
				temp = remain;
				remain = ft_substr(remain, eloc(remain) + 1, ft_strlen(remain) - eloc(remain));
				free(temp);
				temp = 0;
			}
			else
			{
				free(remain);
				remain = 0;
			}
//			printf ("Remains for next time:\n\"%s\"\n", remain);
			return (line);
		}
		else
		{
			bag = ft_substr(remain, 0, ft_strlen(remain)); //CHECK
			free(remain);
			remain = 0;
		}
	}
	cread = read(fd, buffer, BUFFER_SIZE);	
//	printf ("Buffer:\n\"%s\"\n", buffer);
	while ((cread == BUFFER_SIZE) && (eloc(buffer) == -1))
	{
		if ((bag != 0) && (*bag != '\0'))
		{
			temp = bag;
			bag = ft_strjoin(bag, buffer);
			free(temp);
			temp = 0;
		}
		else
			bag = ft_substr(buffer, 0, ft_strlen(buffer)); //CHECK
		cread = read(fd, buffer, BUFFER_SIZE);
//		printf ("Buffer:\n\"%s\"\n", buffer);
	}
	if (cread < 0)
	{
		if ((bag != 0) && (*bag != '\0'))
		{
			free(bag);
			bag = 0;
		}
		return (0);
	}
	else if (cread == 0)
	{
		if ((bag != 0) && (*bag != '\0'))
			return (bag);
		else
			return (0);
	}
	else if ((cread > 0) && (cread < BUFFER_SIZE))
	{
		if ((bag != 0) && (*bag != '\0'))
		{
			line = ft_strjoin(bag, buffer);
			free (bag);
			bag = 0;
		}
		else
			line = ft_substr(buffer, 0, ft_strlen(buffer)); //CHECK
		return (line);
	}
	else
	{
		line = ft_substr(buffer, 0, eloc(buffer)); //CHECK
		if ((eloc(buffer) + 1) < (ft_strlen(buffer)))
//		{
			remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer));
//			printf ("Remains for next time:\n\"%s\"\n", remain);
//		}
		if ((bag != 0) && (*bag != '\0'))
		{
			temp = line;
			line = ft_strjoin(bag, line);
			free(temp);
			temp = 0;
			free (bag);
			bag = 0;
		}
		return (line);
	}
}
