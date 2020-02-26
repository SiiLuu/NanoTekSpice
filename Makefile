##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	src/circuit.cpp			\
		src/action.cpp			\
		src/component.cpp		\
		src/gate.cpp			\
		src/parse.cpp			\
		src/factory.cpp			\
		src/component/4081.cpp 	\
		src/error_handler.cpp 	\
		src/main.cpp

OBJ 	=	$(SRC:.cpp=.o)

NAME =  nanotekspice

CPP = g++ -I./includes

FLAGS += -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		@echo "Compiling..."
		@$(CPP) -o $(NAME) $(OBJ) $(FLAGS)

%.o : %.cpp
		@echo "Compiling $@..."
		@$(CPP) -o $@ -c $< $(FLAGS)

clean:
	@echo "removing *.o..."
	@rm -f src/*.o
	@rm -f src/component/*.o
	@rm -f *.o

fclean:	clean
	@echo "removing $(NAME)..."
	@rm -f $(NAME)

re: 	fclean all

debug:	CFLAGS += -g3
debug:	fclean all