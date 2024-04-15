# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luribero <luribero@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 00:10:28 by luribero          #+#    #+#              #
#    Updated: 2024/04/15 17:48:50 by luribero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		=	get_next_line.a
BSIZE		=	2
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=$(BSIZE)
FILES		=	get_next_line get_next_line_utils
CFILES		=	$(addsuffix .c, $(FILES))
HFILES		=	get_next_line.h
OFILES		=	$(addsuffix .o, $(FILES))
			
all: $(NAME)

$(NAME): $(OFILES)
	@echo "Creating library archive $@ with object files: $^"
	@ar rc $@ $^
	@echo "Indexing library $@"
	@ranlib $@


%.o: %.c $(HFILES) Makefile
	@echo "Compiling source file: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up object files and dependencies"
	@rm -f $(OFILES)

fclean: clean
	@echo "Cleaning up library and its object files"
	@rm -f $(NAME)

re: clean all
