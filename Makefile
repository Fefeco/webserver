# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 11:46:34 by shurtado          #+#    #+#              #
#    Updated: 2025/03/25 17:21:03 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Web_Server
CC			=	c++
CPPFLAGS	=	-std=c++98 -g -Wall -Werror -Wextra -MMD -MP -pedantic #-fsanitize=address

SRC			=	src/main.cpp \
				src/ConfigFile/Location.cpp src/ConfigFile/Server.cpp \
				src/HTTP/HttpRequest.cpp

OBJS		=	$(SRC:%.cpp=obj/%.o)
DEPS		=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

obj/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf obj

f fclean: clean
	rm -f $(NAME)

re: fclean all

v: $(NAME)
	clear
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

r: $(NAME)
	clear
	@./$(NAME)


-include $(DEPS)

.PHONY: all clean fclean re r f v
