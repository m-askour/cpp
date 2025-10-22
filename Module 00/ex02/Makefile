CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone
FILES = megaphone.cpp

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
