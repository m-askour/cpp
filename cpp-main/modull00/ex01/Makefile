CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook
FILES = Contact.cpp main.cpp PhoneBook.cpp
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp headar.hpp Contact.hpp PhoneBook.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
