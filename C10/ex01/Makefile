SRCS_LIST=main.c
OBJECT_LIST=$(patsubst %.c, %.o, $(SRCS_LIST))
CC=cc
CFLAGS=-Wall -Wextra -Werror

PROGRAMM_NAME=ft_cat

all: $(PROGRAMM_NAME)

$(PROGRAMM_NAME): ${OBJECT_LIST}
	${CC} ${CFLAGS} ${OBJECT_LIST} -o ${PROGRAMM_NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJECT_LIST}

fclean: clean
	rm -f ${PROGRAMM_NAME}

re: fclean $(PROGRAMM_NAME)