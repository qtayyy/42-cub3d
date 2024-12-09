#------Colours------#
DEF_COLOR='\033[0;39m'
RESET = '\033[0;0m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'

NAME	= cub3D

CC		= cc
CFLAGS	= -Werror -Wextra -Wall #-g3 -fsanitize=address #-Werror -Wextra -Wall 

#--------Minilibx--------#
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

#---------Libft----------#
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

#---------Sources--------#
SRC_PATH = ./sources/
SRC		= 	main.c \
			init.c \
			init_2.c \
			check_validity.c \
			check_validity_utils.c \
			get_file_data.c \
			get_file_data_utils.c \
			get_file_data_utils_2.c \
			rendering.c \
			raycasting.c \
			raycasting_utils.c \
			utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

#---------Objects--------#
OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

#--------Includes--------#
INC			=	-I ./includes/ -I ./libft/ -I ./minilibx-linux/

#--------Main rule---------#
all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

#--------Objects directory rule---------#
$(OBJ_PATH):
	@ mkdir -p $(OBJ_PATH)

#--------Objects rule---------#
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ $(CC) $(CFLAGS) -c $< -o $@ $(INC)

#--------Project file rule---------#
$(NAME): $(OBJS)
	@ echo $(BLUE)"Compiling Cub3D..."$(RESET)
	@ $(CC) $(CFLAGS)  $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm
	@ echo $(GREEN)"Cub3D compiled"$(RESET)
	@ echo $(MAGENTA)"Your Program Name :"$(RESET)$(YELLOW)" $(NAME) "$(RESET)

#--------Libft rule--------#
$(LIBFT):
	@ echo $(MAGENTA)"Compiling Libft..."$(RESET)
	@ make -s -C $(LIBFT_PATH)
	@ echo $(GREEN)"Libft compiled"$(RESET)

#--------MLX rule--------#
$(MLX):
	@ echo $(YELLOW)"Compiling Minilibx..."$(RESET)
	@ make -s -C $(MLX_PATH) > /dev/null 2>&1
	@ echo $(GREEN)"Minilibx compiled"$(RESET)


clean:
	@ echo $(CYAN)"Cleaning Cube3D objects..."$(RESET)
	@ rm -rf $(OBJ_PATH)
	@ echo $(CYAN)"Cleaning Libft objects..."$(RESET)
	@ make -s -C $(LIBFT_PATH) clean
	@ echo $(CYAN)"Cleaning Minilibx objects..."$(RESET)
	@ make -s -C $(MLX_PATH) clean  > /dev/null 2>&1
	@ echo $(GREEN)"Objects cleaned"$(RESET)

fclean: clean
	@ echo $(RED)"Cleaning Progam..."$(RESET)
	@ rm -f $(NAME)
	@ make -s -C $(LIBFT_PATH) fclean
	@ echo $(GREEN)"Everything cleaned"$(RESET)

re: fclean all

norm:
	@ echo $(YELLOW)"Checking Norminette..."$(RESET)
	@ norminette $(SRCS) ./includes/*.h

play: all
	@ echo $(GREEN)"Playing Cub3D..."$(RESET)"|"$(MAGENTA)" Map : sponge.cub"$(RESET)
	@ ./$(NAME) maps/sponge.cub

.PHONY: all re clean fclean bonus
