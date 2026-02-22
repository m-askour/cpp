c++ = g++
c++flags = -Wall -Werror -Wextra -std=c++98
name = Bureaucrat
files = main.cpp Bureaucrat.cpp AFrom.cpp Intern.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

all: $(name)
$(name):
	$(c++) $(c++flags) $(files) -o $(name)
%.o: %.cpp Bureaucrat.hpp AFrom.hpp Intern.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(c++) $(c++flags) -c $< -o $@
clean:
	rm -f $(name)
fclean: clean
re: fclean all