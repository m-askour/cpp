c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Conversion
files = main.cpp ScalarConverter.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp ScalarConverter.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all