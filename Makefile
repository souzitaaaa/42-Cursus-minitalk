# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 17:20:10 by dinoguei          #+#    #+#              #
#    Updated: 2023/01/16 14:08:36 by dinoguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CLIENT = client
SERVER = server

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -rf

all: $(CLIENT) $(SERVER)

$(CLIENT):
	@$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client

$(SERVER):
	@$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

bonus:
	@$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) ft_strjoinserver.c client_bonus.c $(LIBFT) -o client_bonus
	$(CC) $(CFLAGS) ft_strjoinserver.c server_bonus.c $(LIBFT) -o server_bonus

clean:
	$(MAKE) clean -C ./libft
	rm -rf client server client_bonus server_bonus

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all
