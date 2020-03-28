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
		src/component/2716.cpp 	\
		src/component/4001.cpp 	\
		src/component/4008.cpp 	\
		src/component/4011.cpp 	\
		src/component/4013.cpp 	\
		src/component/4017.cpp 	\
		src/component/4030.cpp 	\
		src/component/4040.cpp 	\
		src/component/4069.cpp 	\
		src/component/4071.cpp 	\
		src/component/4081.cpp 	\
		src/component/4094.cpp 	\
		src/component/4503.cpp 	\
		src/component/4512.cpp 	\
		src/component/4514.cpp 	\
		src/error_handler.cpp 	\
		src/main.cpp

OBJ 	=	$(SRC:.cpp=.o)

NAME =  nanotekspice

CPP = g++ -I./includes -I./includes/component

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

debug:	FLAGS += -g3
debug:	fclean all