NAME		=	fdf

SRCS_FILES	= fdf.c errors.c map.c fill_data.c \
				draw.c preparing.c keys.c

SRCS		= 	$(SRCS_FILES)
SRCS_B		= 	$(SRCS_B_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

INCLUDE		=	-I.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
FRAEMWORKS	=	-framework OpenGL -framework AppKit
RM			=	rm -f

LIB = ./libft/libft.a
MLX = ./minilibx_macos/libmlx.a

.PHONY:		all libft clean fclean re bonus

all:		libft $(NAME)

libft:
	@$(MAKE) -C $(dir $(LIB))
	@$(MAKE) -C $(dir $(MLX))

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) $(LIB) $(MLX)
			$(CC) $(INCLUDE) $(LIB) $(MLX) -o $(NAME) $(OBJS) $(FRAEMWORKS)

clean:
			@$(RM) $(OBJS)
			@$(MAKE) -C $(dir $(LIB)) clean

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)

re:			fclean all
