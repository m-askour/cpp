c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Base
files = main.cpp Base.cpp 
all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Base.hpp 
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all