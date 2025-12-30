CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ScavTrap

FILES = ClapTrap.cpp main.cpp ScavTrap.cpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
