c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Span
files = main.cpp Span.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Span.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all