SRCS_LIST=main.c ft_putnbr.c
OBJECT_LIST=$(patsubst %.c, %.o, $(SRCS_LIST))
CC=cc
CFLAGS=-Wall -Wextra -Werror

PROGRAMM_NAME=do-op

all: compile

compile: ${OBJECT_LIST}
	${CC} ${CFLAGS} ${OBJECT_LIST} -o ${PROGRAMM_NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJECT_LIST}

fclean: clean
	rm -f ${PROGRAMM_NAME}

re: fclean compile