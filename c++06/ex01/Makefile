c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Serialization
files = main.cpp Serializer.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Serializer.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all