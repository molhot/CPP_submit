NAME = RPN
CC = g++ -std=c++98
SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

${NAME}:${OBJS}
	${CC} ${OBJS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all