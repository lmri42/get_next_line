/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:50:43 by luribero          #+#    #+#             */
/*   Updated: 2024/03/27 15:55:02 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"





char	*reader(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*bag;
	char		*output;
	int			reading;
	static char	*remain;

	if ((ft_strlen(remain) == 0) || (remain == NULL)) //IF VARIABLE REMAIN IS EMPTY OR NULL
	{
		reading = read(fd, buff, BUFFER_SIZE); //READ INSIDE BUFFER
		if (reading <= 0) //IF NOTHING ELSE TO READ OR ERROR
			return (NULL);
		if (reading < BUFFER_SIZE) //IF THIS IS THE LAST READING
			{
				buff[reading] = '\0';//CLOSE LAST STRING
				output = ft_strdup(buff); //OUTPUT BECOMES LAST COPY
				return (output); //RETURNS LAST COPY >> NEED TO FREE!
		}
		else //IF THERE ARE STILL CONTENT TO READ
		{
			buff[BUFFER_SIZE] = '\0';//CLOSE FULL STRING
			if (eloc(buff) != -1) //IF THERE IS A '\N' INSIDE BUFFER
			{
				output = ft_substr(buff, eloc(buff), ft_strlen(buff);//OUTPUT UNTIL '\N'
				if ((eloc(buff) + 1) < ft_strlen(b)))//IF THERE IS EXTRA CONTENT INSIDE BUFFER AFTER '\N'
					remain = ft_substr((buff + eloc(buff) + 1), (ft_strlen(buff) - eloc(buff) - 1), ft_strlen(buff));
				else//IF THERE IN NO EXTRA CONTENT INSIDE BUFFER
					remain == NULL;
				return (output);
			}
			else //IF THERE IS NO '\N' INSIDE BUFFER
			{
				if (ft_strlen(bag) != 0) //CHECK IF BAG IS EMPTY
				//IF NOT EMPTY. ADD TO BAG.
				else
					bag = ft_strdup(buff); //CREATE BAG


char *get_next_line(int fd)
{
	char	*line;
	char	*end;

	end = "\n";
	line = reader(fd);
	if (line == NULL)
	{
		return (end);
	}
	else
		return (line);
}
