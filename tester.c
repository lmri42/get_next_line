/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luribero <luribero@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:51:46 by luribero          #+#    #+#             */
/*   Updated: 2024/03/30 00:51:41 by luribero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int		times;
    char	*line;
    int		round;
    int		fd;

    if(argc != 3)
    {
	printf("Error: Please provide 2 arguments.\n");
	printf("1 ARG: Path to file to read.\n");
	printf("2 ARG:: Number of lines..\n");
	return (1);
    }
    times = atoi(argv[2]);
    round = 1;
    fd = open(argv[1], O_RDONLY);
    while(times > 0)
    {
	line = get_next_line(fd);
	printf("-line: %d-\n", round);
	if(line == 0)
	{
	    printf("-END-\n");
	    return(1);
	}
	printf("%s\n", line);
	times--;
	round++;
    }
    return (0);
}
