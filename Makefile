##
## Makefile for rt1 in /home/alies_a/rendu/gfx_raytracer1
## 
## Made by alies_a
## Login   <alies_a@epitech.net>
## 
## Started on  Fri Jan 29 14:31:30 2016 alies_a
## Last update Sat Feb 13 11:19:30 2016 alies_a
##

NAME    =       rt1

CC	=	gcc -g

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC) \
		-W -Wall -Wextra

SRC	=	./src/

MY	=	./src/my/

OBJ	=	./src/objs/

MATH	=	./src/math/

DISP	=	./src/display/

SRCS	=	$(SRC)main.c \
		$(SRC)tekpixel.c \
		$(MATH)equ.c \
		$(MATH)norm.c \
		$(MATH)visible.c \
		$(MATH)scal.c \
		$(MATH)unit.c \
		$(DISP)display.c \
		$(DISP)render.c \
		$(DISP)shadow.c \
		$(OBJ)uni.c \
		$(OBJ)check.c \
		$(OBJ)sphere.c \
		$(OBJ)cylinder.c \
		$(OBJ)plane.c \
		$(MY)my_putchar.c \
		$(MY)my_putstr.c \
		$(MY)my_strcat.c \
		$(MY)my_strcpy.c \
		$(MY)my_strdup.c \
		$(MY)my_strlen.c \
		$(MY)my_str_to_nbr.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
