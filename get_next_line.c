/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/04/17 13:39:53 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //testing
#include "get_next_line.h"

void clean(char *buff, int times)
{
	while(times >= 0)
	{
		*buff = '\0';
		times--;
		buff++;
	}
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*temp;
	char		*bag;
	int			cread;
	char		buffer [BUFFER_SIZE + 1];
	char		*line;

	bag = 0;
//	printf ("Remains from previous:\n\"%s\"\n", remain);//testing
	if ((fd < 0) || (BUFFER_SIZE < 1) || (BUFFER_SIZE > INT_MAX))
		return (0);
	if ((remain != 0) && (*remain != '\0'))
	{
//		printf("REMAIN FOUND!\n"); //testing
		if (eloc(remain) > -1)
		{
//			printf("END OF LINE FOUND IN REMAIN!\n"); //testing
//			printf("Eloc (remain) in \"%d\"\n", eloc(remain)); //testing
			line = ft_substr(remain, 0, eloc(remain));
//			printf("1.Line says \"%s\"\n", line); //testing

			if ((eloc(remain) + 1) < ft_strlen(remain))
			{
//				printf("CREATING REMAIN FROM REMAIN!\n"); //testing
				temp = remain;
				remain = ft_substr(remain, eloc(remain), ft_strlen(remain) - eloc(remain));
				free(temp);
				temp = 0;
//				printf ("Remains for next time:\n\"%s\"\n", remain);//testing
			}
			else
			{
//				printf("FREE REMAIN!\n"); //testing
				free(remain);
				remain = 0;
			}
			return (line);
		}
		else
		{
//			printf ("CREATING BAG FROM REMAIN"); //testing
			bag = ft_substr(remain, 0, ft_strlen(remain));
//			printf("Strlen(remain) is \"%d\"\n", ft_strlen(remain)); //testing
//			printf("Bag says \"%s\"\n", bag); //testing
			free(remain);
			remain = 0;
		}
	}
	clean(buffer, BUFFER_SIZE);
	cread = read(fd, buffer, BUFFER_SIZE);	
//	printf ("Buffer:\n\"%s\"\n", buffer); //testing
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
		{
			bag = ft_substr(buffer, 0, ft_strlen(buffer));
//			printf("Bag says \"%s\"\n", bag); //testing
//			printf("Strlen(buffer) is \"%d\"\n", ft_strlen(buffer)); //testing
		}
		clean(buffer, BUFFER_SIZE);
		cread = read(fd, buffer, BUFFER_SIZE);
//		printf ("New Buffer:\n\"%s\"\n", buffer); //testing
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
	else if ((cread > 0) && (cread < BUFFER_SIZE)) // CHECK
	{
		if ((bag != 0) && (*bag != '\0'))
		{
			line = ft_strjoin (bag, buffer);
			free(bag);
			bag = 0;
		}
		else
			line = ft_substr (buffer, 0, ft_strlen(buffer));
		if (eloc(line) > -1)
		{
			temp = line;
			line = ft_substr (line, 0, eloc(line));
			if((eloc(buffer) + 1) < ft_strlen(buffer))
				remain = ft_substr(temp, eloc(temp), ft_strlen(temp) - eloc(temp));
			free(temp);
			temp = 0;
		}
		return (line);
	}
	else
	{
		line = ft_substr(buffer, 0, eloc(buffer));
//		printf("3.Line says \"%s\"\n", line); //testing
//		printf("Eloc(buffer) is \"%d\"\n", eloc(buffer)); //testing
		if ((eloc(buffer) + 1) < (ft_strlen(buffer)))
		{
			remain = ft_substr(buffer, eloc(buffer), ft_strlen(buffer) - eloc(buffer));
//			printf ("Remains for next time:\n\"%s\"\n", remain);//testing
		}
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
