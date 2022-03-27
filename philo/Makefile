NAME = philo


CC = @cc

FLAGS = -Wall -Wextra -Werror

RM = @rm -f

C_FILES = 	philo.c \
			actions.c \
			init.c \
			ft_atoi.c \
			threads_utils.c \
			utils_2.c \
			utils.c 

N_FLAG = -o

#  colors

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(C_FILES) 
	@echo "$(C_GREEN)["philo" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(N_FLAG) $(NAME)

clean :
	@echo "$(C_RED)["philo" REMOVED]$(C_RES)"
	$(RM) $(NAME)

fclean : clean

re : fclean all