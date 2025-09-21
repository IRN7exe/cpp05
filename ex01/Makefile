ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM 	= rm -rf
endif

DEF					=	\033[0m
RED					=	\033[31m
GRE					=	\033[32m
YEL					=	\033[33m
BLU					=	\033[34m
MAG 				=	\033[35m
CYA			 		=	\033[36m
WHI 				=	\033[37m

TARGET				=	form
override CXXFLAGS 	+= 	-Wall -Wextra -Werror -std=c++98

SRCS 				=	main.cpp \
						Bureaucrat.cpp \
						Form.cpp

HEADERS 			= 	Bureaucrat.hpp \
	      				Form.hpp

SRC_DIR				=	src/
INCLUDE_DIR			=	include/

SRC					=	$(addprefix $(SRC_DIR), $(SRCS))
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
	echo "$(BLU)Deleting $(TARGET) from /ex01...$(DEF)"; else \
	echo "No Executable file to remove from /ex01."; \
	fi;

re: fclean all

.PHONY: all clean fclean re