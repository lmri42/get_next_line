/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:02:02 by luribero          #+#    #+#             */
/*   Updated: 2024/04/15 17:27:51 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// Include Libraries:
# include <stdlib.h>					//malloc, free
# include <unistd.h>					//write
# include <limits.h>					//LONG_MIN, INT_MAX, ULONG_MAX, etc
# include <fcntl.h>						//open
//# define BUFFER_SIZE 1000 		 	// buffer size
# define GET_NEXT_LINE_H

//STRING COPY: COPY X NUMBER OF CHARACTERS FROM A STRING TO ANOTHER
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

//STRING LENGHT: COUNTS THE TOTAL NUMBER OF CHARACTERS, DOESNT INCLUDE "\0"
int		ft_strlen(char *txt);

//STRING JOIN: ALLOCATES A NEW STRING, WHICH IS THE CONCATENATION OF S1 AND S2
char	*ft_strjoin(char const *s1, char const *s2);

//END LOCATOR: SEARCH FOR THE POSITION OF FIRST "\N", OTHERWISE RETURNS -1
int		eloc(char *txt);

//SUB-STRING: CREATE A SUBSTRING FROM A STRING
char	*ft_substr(char const *s, unsigned int start, size_t len);

//GETS NEXT LINE FROM A FILE DESCRIPTOR
char	*get_next_line(int fd);

#endif
