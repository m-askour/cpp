CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = refrence
FILES = main.cpp

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(FILES)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all
