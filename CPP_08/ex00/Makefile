NAME = ex00
CC = g++ -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

${NAME}:${OBJS}
	${CC} ${OBJS} ${CPPFLAGS} -o ${NAME}

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all