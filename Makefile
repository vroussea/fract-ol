# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/06/14 18:59:57 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol
INCLUDES =	libft/libft.a
HEADER =	fractol.h
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c event.c mandelbrot.c julia.c burningship.c draw.c
OBJS =		$(SOURCES:.c=.o)

all :		$(NAME)
$(NAME) :	$(OBJS) $(HEADER) Makefile
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
