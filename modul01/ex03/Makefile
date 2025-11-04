
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Attack
FILES = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re