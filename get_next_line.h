/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:02:02 by luribero          #+#    #+#             */
/*   Updated: 2024/03/05 00:17:45 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
// Include Libraries:
# include <stddef.h>		//size_t
# include <stdlib.h>		//malloc, free
# include <unistd.h>		//write
# include <limits.h>		//LONG_MIN, INT_MAX, ULONG_MAX, etc
# include <fcntl.h>		//open
# define FT_PRINTF_H

char	*get_next_line(int fd);

void	get_next_line_utils.c();

#endif
