NAME		:= libft.a

CC			:= gcc

CFLAGS		:= -Wall -Werror -Wextra

SRC			:= 	ft_atoi.c \
				ft_atoi_base.c\
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_str_superjoin.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_get_next_line.c \
				ft_split_free.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
              	ft_lstlast.c \
			  	ft_lstlast.c \
			  	ft_lstadd_back.c \
              	ft_lstdelone.c \
			  	ft_lstclear.c \
			  	ft_lstiter.c \
              	ft_lstmap.c \

SRC_BONUS	:=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
              	ft_lstlast.c \
			  	ft_lstlast.c \
			  	ft_lstadd_back.c \
              	ft_lstdelone.c \
			  	ft_lstclear.c \
			  	ft_lstiter.c \
              	ft_lstmap.c \

OBJ			:= $(SRC:.c=.o)

OBJ_BONUS	:= $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) 
	ar rcs $(NAME) $(OBJ)
	
%.o:	%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re:fclean all
