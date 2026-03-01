c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = whatever
files = main.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp whatever.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all