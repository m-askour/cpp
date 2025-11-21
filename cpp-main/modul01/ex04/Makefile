CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = read
FILES = main.cpp

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
