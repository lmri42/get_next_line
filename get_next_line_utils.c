/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:10:16 by luribero          #+#    #+#             */
/*   Updated: 2024/04/17 17:42:39 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//STRING COPY: COPY X NUMBER OF CHARACTERS FROM A STRING TO ANOTHER
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	len;
	char	*s;

	s = (char *)src;
	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	s = s - len;
	while ((n > 1) && (*s != '\0'))
	{
		*dst = *s;
		dst++;
		s++;
		n--;
	}
	if (n > 0)
		*dst = '\0';
	return (len);
}

//STRING LENGHT: COUNTS THE TOTAL NUMBER OF CHARACTERS, DOESNT INCLUDE "\0"
int	ft_strlen(char *txt)
{
	int	count;

	count = 0;
	if ((txt == NULL) || (*txt == '\0'))
		return (count);
	while (*txt != '\0')
	{
		count++;
		txt++;
	}
	return (count);
}

//STRING JOIN: ALLOCATES A NEW STRING, WHICH IS THE CONCATENATION OF S1 AND S2
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

//END LOCATOR: SEARCH FOR THE POSITION OF FIRST "\N", OTHERWISE RETURNS -1
int	eloc(char *txt)
{
	int	count;

	count = 1;
	if ((txt == 0) || (*txt == 0))
		return (-1);
	while (*txt != '\0')
	{
		if (*txt != '\n')
		{
			count++;
			txt++;
		}
		else
			return (count);
	}
	return (-1);
}

//SUB-STRING: CREATE A SUBSTRING FROM A STRING
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*ptr;
	size_t			size;
	char			*error;

	i = 0;
	size = ft_strlen((char *)s);
	if (size + 1 <= (size_t)start)
	{
		error = (char *)malloc(1);
		if (error == NULL)
			return (NULL);
		*error = '\0';
		return (error);
	}
	while (s[start + i] != '\0' && len > 0)
	{
		i++;
		len--;
	}
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, (s + start), (i + 1));
	return (ptr);
}
