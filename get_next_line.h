/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:02:02 by luribero          #+#    #+#             */
/*   Updated: 2024/03/27 16:09:28 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// Include Libraries:
# include <stdlib.h>		//malloc, free
# include <unistd.h>		//write
# include <limits.h>		//LONG_MIN, INT_MAX, ULONG_MAX, etc
# include <fcntl.h>			//open
# define BUFFER_SIZE 42 		 	// buffer size
# define GET_NET_LINE_H

//STRING COPY: COPY X NUMBER OF CHARACTERS FROM A STRING TO ANOTHER
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

//STRING LENGHT: COUNTS THE TOTAL NUMBER OF CHARACTERS, DOESNT INCLUDE "\0"
int		ft_strlen(char *txt);

//SUBSTRING: CREATE A SUBSTRING FROM A STRING
char	*ft_substr(char const *s, unsigned int start, size_t len);

//END LOCATOR: SEARCH FOR THE POSITION OF FIRST "\N", OTHERWISE RETURNS -1
int		eloc(char *txt);

//ALLOCATE SPACE FOR NEW STRING WITH THE CONTENT FROM A PREVIOUS STRING
char	*ft_strdup(const char *s1);

//READS FROM A FILE 
char	*reader(int fd);

//GETS NEXT LINE FROM A FILE DESCRIPTOR
char	*get_next_line(int fd);

#endif
