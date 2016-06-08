# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/06/08 17:29:51 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol
INCLUDES =	libft/libft.a
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c event.c mandelbrot.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
fonly :
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
$(NAME) :
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)
norm :
			norminette $(SOURCES) fractol.h
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS)
fclean :	clean
			$(MKINC) fclean
			-rm -f $(NAME)
re :		fclean all
