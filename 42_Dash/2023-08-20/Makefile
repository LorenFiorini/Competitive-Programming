NAME	= bsq

FILES	= main.cpp
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	clang++ -g -std=c++17 -O3 -o $(NAME) $(FILES)

debug: $(FILES)
	clang++ -g -std=c++17 -O3 $(FLAGS) -o $(NAME) $(FILES) -D DEBUG

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
