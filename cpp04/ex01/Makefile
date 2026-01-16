CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Brain

FILES = main.cpp  Dog.cpp Cat.cpp Animal.cpp Brain.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Dog.hpp Cat.hpp Animal.hpp Brain.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
