/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/03/30 00:41:17 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	p;
	size_t	s;
	char	*ptr;

	p = ft_strlen((char *)s1);
	s = ft_strlen((char *)s2);
	ptr = (char *)malloc(p + s + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, (p + 1));
	ft_strlcpy((ptr + p), s2, (s + 1));
	return (ptr);
}

char *get_next_line(int fd)
{
    char *line;
    char buffer[BUFFER_SIZE + 1];
    char *bag;
    char *temp;
    static char	*remain;
   
    bag = 0;
    if (ft_strlen(remain) > 0)
    {
    	if(eloc(remain) > -1)
	{
	    if((eloc(remain) + 1) < ft_strlen(remain))
	    {
		line = ft_substr(remain, 0, eloc(remain));
		temp = remain;
		remain = ft_substr(remain, eloc(remain) + 1, ft_strlen(remain) - eloc(remain));
		free(temp);
	    }
	    else
	    {
	    	line = ft_substr(remain, 0, eloc(remain));
		free(remain);
		remain = 0;
	    }
	    return (line);
	}
	bag = ft_strdup(remain);
    }
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    { 
	while ((eloc(buffer) == -1) && (eloc(bag) == -1))
    	{
	    if (eloc(buffer) == -1)
	    {
		if(ft_strlen(bag) != 0)
		{
	    		temp = bag;
			bag = ft_strjoin(bag,buffer);
	    		free(temp);
		}
		else
		{
		    bag = ft_strdup(buffer);
		}
		read(fd, buffer, BUFFER_SIZE);
	    }
	}
	if (eloc(bag) > -1)
	{
	    line = ft_substr(buffer, 0, eloc(buffer));
	    if((eloc(bag) + 1) < ft_strlen(bag))
	    {
		remain = ft_substr(bag, eloc(bag) + 1, ft_strlen(bag) - eloc(bag));
	    }
	    else
	    {
		free(remain);
		remain = 0;
	    }
	}
	else if ((eloc(buffer) > -1) && (ft_strlen(bag) > 0))
	{
	    temp = bag;
	    bag = ft_strjoin(bag,buffer);
	    free(temp);
	    line = ft_substr(bag, 0, eloc(bag));
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer));
	    }
	    else
	    {
		free(remain);
		remain = 0;
	    }
	}
	else
	{
	    line = ft_substr(buffer, 0, eloc(buffer));
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer));
	    }
	    else
	    {
		free(remain);
		remain = 0;
	    }
	}
	return (line);
    }
    free(remain);
    remain = 0;
    return(0);
} 
