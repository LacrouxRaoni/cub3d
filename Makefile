NAME			=	cub3D

#PATH
LIBFT_PATH		= 	./libraries/libft/
MLX_PATH		= 	./libraries/minilibx/
SRC_PATH		= 	./src/
OBJ_PATH		= 	./obj/
INCLUDE_PATH	=	./include/

#HEADERS
LIBFT			= 	$(LIBFT_PATH)/libft.a
MLX				= 	$(MLX_PATH)/libmlx.a
HEADER			= 	$(INCLUDE_PATH)cub3d.h

#HEADRES PATH
I_OBJ			=	-I ./ \
					-I $(MLX_PATH) \
					-I $(LIBFT_PATH) \
					-I $(INCLUDE_PATH) \

#LINKING HEADRES
LINKS			=	-L $(LIBFT_PATH) -lft -L $(MLX_PATH) -lmlx -lXext -lX11 -lm

#COMPILATION
CC				= 	gcc
CFLAGS			= 	-g3

SRC				=	main.c\
					initial_validation.c\
					file_validation.c\
					map_header_validation.c\
					color_validation.c\
					color_validation_utils.c\
					map_validation.c\
					map_wall_validation.c\
					map_wall_validation_utils.c\
					built_map.c\
					ray_tracing.c\
					error.c\
					clean.c\
					key_events.c\
					rgb_to_int.c\
					init_game.c\
					ray_casting.c\
					image_setup.c\
					ray_y.c\
					ray_x.c\
					ray_x_utils.c\
					fill_ray_struct.c\
					game_looping.c\
					print_on_screen.c\
					move_player.c\

OBJ				= 	$(SRC:%.c=$(OBJ_PATH)%.o)

VPATH			=	$(SRC_PATH)\
					$(SRC_PATH)exit_error\
					$(SRC_PATH)validation\
					$(SRC_PATH)mini_map\
					$(SRC_PATH)ray_casting\
					$(SRC_PATH)init_game\
					$(SRC_PATH)screen_setup\

all:	$(NAME)

$(OBJ_PATH)%.o:	%.c $(HEADER)
	@printf "\nGenerating object...\n"
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(I_OBJ)

$(NAME):	$(LIBFT) $(MLX) $(OBJ) $(HEADER)
	@printf "\nGenerating cub_3d executable...\n"
	$(CC) $(CFLAGS) $(I_OBJ) $(OBJ) $(LINKS) -o $(NAME)


$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
		rm -rf $(NAME)
		make -C $(LIBFT_PATH) fclean

re: fclean all
