c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Bureaucrat
files = main.cpp Bureaucrat.cpp Form.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all