/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:51:46 by luribero          #+#    #+#             */
/*   Updated: 2024/04/15 18:21:08 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		times;
	char	*line;
	int		round;
	int		fd;	

	if (argc != 3)
	{
		printf ("Error!\n\tPlease provide 2 arguments.\n");
		printf ("\tA1:\tPath to file to read.\n");
		printf ("\tA2:\tNumber of lines to read.\n");
		return (1);
	}
	times = atoi(argv[2]);
	round = 1;
	fd = open(argv[1], O_RDONLY);
	while (times > 0)
	{
		printf ("\nSTART!\n");
		line = get_next_line(fd);
		printf ("-line: %d-\n", round);
		if (line == 0)
		{
			printf ("-END-\n");
			return (1);
		}
		printf("%s", line);
		times--;
		round++;
	}
	close(fd);
	return (0);
}
