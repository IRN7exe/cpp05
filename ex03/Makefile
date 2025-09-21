ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

DEF					=	\033[0m
RED					=	\033[31m
GRE					=	\033[32m
YEL					=	\033[33m
BLU					=	\033[34m
MAG 				=	\033[35m
CYA			 		=	\033[36m
WHI 				=	\033[37m

TARGET				=	intern
override CXXFLAGS 	+= 	-Wall -Wextra -Werror -std=c++98

SRCS 				=	main.cpp \
						Intern.cpp \
						AForm.cpp \
						Bureaucrat.cpp \
						RobotomyRequestForm.cpp \
						ShrubberyCreationForm.cpp \
						PresidentialPardonForm.cpp

HEADERS 			= 	Intern.hpp \
		 				AForm.hpp \
						Bureaucrat.hpp \
		  				RobotomyRequestForm.hpp \
		  				ShrubberyCreationForm.hpp \
		  				PresidentialPardonForm.hpp

SRC_DIR				=	src/
INCLUDE_DIR			=	include/

SRC 				=	$(addprefix $(SRC_DIR), $(SRCS))
INCLUDE				=	$(addprefix $(INCLUDE_DIR), $(HEADERS))

all: $(TARGET)
 
$(TARGET): $(SRC) Makefile $(INCLUDE)
	@echo "$(YEL)Compiling [./$(TARGET)]...$(DEF)"
	@$(CXX) -I. $(CXXFLAGS) $(SRC) -o $@ 	
	@echo "$(GRE)Finished [./$(TARGET)]$(DEF)"

clean: 

fclean: clean
	@if [ -f "$(TARGET)" ]; then \
	$(RM) $(TARGET); \
	echo "$(BLU)Deliting $(TARGET) from /ex03...$(DEF)"; else \
	echo "No Executable file to remove from /ex03."; \
	fi; 

re: fclean all

.PHONY: all clean fclean re