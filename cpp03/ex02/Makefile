CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap
 
FILES = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
