CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Zombie

FILES = main.cpp Zombie.cpp zombieHorde.cpp 

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

