NAME = ex01
CXX = c++ -std=c++98
SRCS = main.cpp zombieHorde.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

${NAME}:${OBJS}
	${CXX} ${OBJS} ${CXXFLAGS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all