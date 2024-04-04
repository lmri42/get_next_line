/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/04/04 22:41:07 by luribero         ###   ########.fr       */
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
    int	cread;
    static char	*remain;
   
    bag = 0;
    
    if((fd < 0) || (BUFFER_SIZE < 1) || (BUFFER_SIZE > INT_MAX))
	return (0);
    if (ft_strlen(remain) > 0)
    {
    	if(eloc(remain) > -1)
	{
	    if((eloc(remain) + 1) < ft_strlen(remain))
	    {
		line = ft_substr(remain, 0, eloc(remain) + 1); //line=malloc
		temp = remain;
		remain = ft_substr(remain, eloc(remain) + 1, ft_strlen(remain) - eloc(remain)); //new_remain=malloc
		free(temp); //old_remain=free
	    }
	    else
	    {
	    	line = ft_substr(remain, 0, eloc(remain) + 1); //line=malloc
		free(remain); //remain=free
		remain = 0;
	    }
	    return (line);
	}
	bag = ft_strdup(remain); //bag=malloc
    }
    cread = read(fd, buffer, BUFFER_SIZE);
    if(cread == -1)
    {
	return(0);
    }
    while(cread > 0)
    { 
	while ((eloc(buffer) == -1) && (eloc(bag) == -1))
    	{
	    if (eloc(buffer) == -1)
	    {
		if(ft_strlen(bag) != 0)
		{
	    		temp = bag;
			bag = ft_strjoin(bag,buffer); //new_bag=malloc
	    		free(temp); //old_bag=free
		}
		else
		{
		    bag = ft_strdup(buffer); //bag=malloc
		}
		cread = read(fd, buffer, BUFFER_SIZE);
		if(cread == -1)
		{
		    return(0);
		}
	    }
	}
	if (eloc(bag) > -1)
	{
	    line = ft_substr(buffer, 0, eloc(buffer) + 1); //line=malloc
	    if((eloc(bag) + 1) < ft_strlen(bag))
	    {
		remain = ft_substr(bag, eloc(bag) + 1, ft_strlen(bag) - eloc(bag)); //remain=malloc
	    }
	    else
	    {
		free(remain); //remain=free
		remain = 0;
	    }
	}
	else if ((eloc(buffer) > -1) && (ft_strlen(bag) > 0))
	{
	    temp = bag;
	    bag = ft_strjoin(bag,buffer); //new_bag=malloc
	    free(temp); //old_bag=free
	    line = ft_substr(bag, 0, eloc(bag) + 1); //line=malloc
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer)); //remain=malloc
	    }
	    else
	    {
		free(remain); //remain=free
		remain = 0;
	    }
	}
	else
	{
	    line = ft_substr(buffer, 0, eloc(buffer) + 1); //line=malloc
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer)); //remain=malloc
	    }
	    else
	    {
		free(remain); //remain=free
		remain = 0;
	    }
	}
	return (line);
    }
    free(remain); //remain=free
    remain = 0;
    return(0);
} 
