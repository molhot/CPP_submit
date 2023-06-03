NAME = ex02
CC = g++ -std=c++98
SRCS = main.cpp A.cpp B.cpp C.cpp func.cpp Base.cpp
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