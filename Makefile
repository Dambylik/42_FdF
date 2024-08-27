NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	  check_map_errors.c \
	  check_map_errors2.c \
	  parse_map.c \
	  draw_grid.c \
	  transform_map_to_points.c \
	  handle_keyboard.c \
	  isometric_projection.c \
	  handle_screen.c \
	  clean_service.c \
	  

OBJS	= ${SRCS:.c=.o}

LIB_MINILIBX = -Lminilibx -lmlx -lXext -lX11 -lm -lz 
LIB_LIBFT	= libft/libft.a

MINILIBX = minilibx/
LIBFT = libft/

GREEN = '\033[0;32m'
CYAN = '\033[0;36m'
WHITE = '\033[0;37m'

all: $(NAME) lib

$(NAME): $(OBJS) lib
	$(CC) $(CFLAGS) $(OBJS) $(LIB_MINILIBX) $(LIB_LIBFT) -o $(NAME)
	@echo ✅ $(GREEN)"Project successfully compiled"

lib:
	@echo ⏳ $(GREEN)"Compilation in progress"$(WHITE)
	make -C $(MINILIBX)
	make -C $(LIBFT)

clean:
	@echo 🧹 $(CYAN)"Removing .o files"$(WHITE)
	rm -f ${OBJS}

fclean: clean
	@echo 🧹 $(CYAN)"Removing all"$(WHITE)
	rm -f ${NAME}
	make clean -C ${MINILIBX}
	make fclean -C ${LIBFT}

re: fclean all