# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 11:08:50 by vfurmane          #+#    #+#              #
#    Updated: 2021/11/04 09:57:55 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= microphone
SRCS		= Contact.cpp microphone.cpp PhoneBook.cpp
OBJS		= $(SRCS:.cpp=.o)
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

%.o:		%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
