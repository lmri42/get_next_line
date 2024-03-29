/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/03/30 00:10:53 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

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
   
    sleep(3); //	
    printf("\n\n\nSTART\n"); //
    bag = 0;
    if (ft_strlen(remain) > 0)
    {
    	printf("There is content inside the static variable remain!\n"); //
	printf("\"%s\"\n", remain); //
	if(eloc(remain) > -1)
	{
	    printf("End of line FOUND inside remain.\n"); //
	    printf("REMAIN: End of line FOUND in position %d.\n", eloc(remain));
	    printf("REMAIN: String has %d characters.\n", ft_strlen(remain));
	    if((eloc(remain) + 1) < ft_strlen(remain))
	    {
		line = ft_substr(remain, 0, eloc(remain));
		printf("Line made with substr from remain to end of line\n"); //
		temp = remain;
		remain = ft_substr(remain, eloc(remain) + 1, ft_strlen(remain) - eloc(remain));
		free(temp);
		printf("Content from remain saved in static variable remain!\n"); //
		printf("Remains:\n\"%s\"\n", remain); //
	    }
	    else
	    {
	    	line = ft_substr(remain, 0, eloc(remain));;
		printf("Line made with substr from remain to end of line\n"); //
		remain = 0;
		printf("Cleaning remaining\n");
	    }
	    printf("Returning this line:\n\"%s\".\n\n", line); //
	    return (line);
	}
	bag = ft_strdup(remain);
	printf("Bag created from the content inside of remain!\n");//
	printf("Bag content is:\n\"%s\".\n", bag); //
    }
    else
    {
	printf("Nothing remaining from previous reading!\n");
    }
    while (read(fd, buffer, BUFFER_SIZE) > 0)
    { 
    	printf("Reading!\n");
	printf("The buffer says:\n\"%s\"\n", buffer); //
	printf("Eloc(buffer) = %d\nEloc(bag) = %d\n", eloc(buffer), eloc(bag)); //
    	while ((eloc(buffer) == -1) && (eloc(bag) == -1))
    	{
	    printf("End of Line not found inside Buffer or Bag.\n");
	    if (eloc(buffer) == -1)
	    {
		printf("End of Line not found on buffer!\n"); //
		if(ft_strlen(bag) != 0)
		{
			printf("The bag has already %d characters.\n", ft_strlen(bag)); //
	    		printf("The bag contains this:\n\"%s\".\n", bag); //
	    		temp = bag;
			bag = ft_strjoin(bag,buffer);
			printf("The new bag has %d characters.\n", ft_strlen(bag)); //
	   		printf("The new bag contains this:\n\"%s\".\n", bag); //
	    		free(temp);
		}
		else
		{
			printf("Creating a bag\n"); //
			bag = ft_strdup(buffer);
			printf("The new bag has %d characters.\n", ft_strlen(bag)); //
			printf("The bag contains this:\n\"%s\"\n", bag); //
	  	  }
		  read(fd, buffer, BUFFER_SIZE);
		  printf("Reading again!\nNew buffer says:\n\"%s\".\n", buffer);//
	    }
	    printf("CHECKPOINT!\n");
	    printf("Eloc(buffer) = %d\nEloc(bag) = %d\n", eloc(buffer), eloc(bag)); //
	}
	if (eloc(bag) > -1)
	{
	    line = ft_substr(buffer, 0, eloc(buffer));
	    printf("End of line FOUND inside bag.\nDoing substr from buffer until end of line\n"); //
	    if((eloc(bag) + 1) < ft_strlen(bag))
	    {
		remain = ft_substr(bag, eloc(bag) + 1, ft_strlen(bag) - eloc(bag));
		printf("BAG: End of line FOUND in position %d.\n", eloc(bag));
		printf("BAG: String has %d characters.\n", ft_strlen(bag));
		printf("Content from bag saved in static variable remain!\n"); //
		printf("Remains:\n\"%s\"\n", remain); //
	    }
	    else
	    {
		free(remain);
		remain = 0;
		printf("Cleaning remaining\n");
	    }
	}
	else if ((eloc(buffer) > -1) && (ft_strlen(bag) > 0))
	{
	    temp = bag;
	    bag = ft_strjoin(bag,buffer);
	    free(temp);
	    line = ft_substr(bag, 0, eloc(bag));
	    printf("End of line FOUND inside buffer.\nDoing strjoin of bag + buffer.\nDoing substr from bag until end of line.\n"); //
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer));
		printf("BUFFER: End of line FOUND in position %d.\n", eloc(buffer));
		printf("BUFFER: String has %d characters.\n", ft_strlen(buffer));
		printf("Content from buffer saved in static variable remain!\n"); //
		printf("Remains:\n\"%s\"\n", remain); //
	    }
	    else
	    {
		free(remain);
		remain = 0;
		printf("Cleaning remaining\n");
	    }
	}
	else
	{
	    line = ft_substr(buffer, 0, eloc(buffer));
	    printf("End of line FOUND inside buffer.\nDoing strjoin of bag + buffer.\nDoing substr from bag until end of line.\n"); //
	    if((eloc(buffer) + 1) < ft_strlen(buffer))
	    {
		remain = ft_substr(buffer, eloc(buffer) + 1, ft_strlen(buffer) - eloc(buffer));
		printf("BUFFER: End of line FOUND in position %d.\n", eloc(buffer));
		printf("BUFFER: String has %d characters.\n", ft_strlen(buffer));
		printf("Content from buffer saved in static variable remain!\n"); //
		printf("Remains:\n\"%s\"\n", remain); //
	    }
	    else
	    {
		free(remain);
		remain = 0;
		printf("Cleaning remaining\n");
	    }
	}
	printf("Returning this line:\n\"%s\".\n\n", line); //
	return (line);
    }
    printf("Nothing else to print\n");
    free(remain);
    remain = 0;
    return("\n");
} 
