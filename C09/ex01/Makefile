SRCS_DIR=srcs
SRCS_LIST=ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJECT_LIST=$(addprefix $(SRCS_DIR)/, $(patsubst %.c, %.o, $(SRCS_LIST)))
INCLUDES_DIR=includes
INCLUDES_LIST=ft.h
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(INCLUDES_DIR)

all: libft.a

libft.a: $(OBJECT_LIST)
	ar rcs $@ $^

%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f ${OBJECT_LIST}

fclean: clean
	rm -f libft.a

re: fclean libft.a