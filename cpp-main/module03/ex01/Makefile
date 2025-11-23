CC = c++

CFLAGSE = -Wall -Wextra -Werror -std=c++98

NAME = ClapTrap

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp


all:$(NAME)

$(NAME): $(FILES)
	$(CC) $(CFLAGSE) -o $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all
