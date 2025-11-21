CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Zombie

FILES = main.cpp Zombie.cpp Zombie.hpp zombieHorde.cpp 

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cppv Zombie.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

