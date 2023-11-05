

NAME	= marvin
CC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++2a -g


SRC_D	= src-03
OBJ_D	= obj-03

SRCS	= $(wildcard $(SRC_D)/*.cpp)
OBJS	= $(patsubst $(SRC_D)/%.cpp, $(OBJ_D)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(OBJ_D)/%.o: $(SRC_D)/%.cpp
	@mkdir -p $(OBJ_D)
	$(CC) $(FLAGS) -c -o $@ $<
	@echo "Compiled $<"

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
