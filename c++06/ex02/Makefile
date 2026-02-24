c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Base
files = main.cpp Base.cpp A.cpp B.cpp C.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all