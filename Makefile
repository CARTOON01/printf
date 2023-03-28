
NAME = _printf

CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
CFLAGS += -g
CFLAGS += -Wno-format

RM = rm -f

SRCS = main.c \
		_printf.c \
		_puts.c \
		_putchar.c \
		print_char.c \
		print_string.c \
		print_integer.c \
		print_binary.c \
		print_octal.c \
		print_hex.c \
		print_unsigned.c \
		print_reverse.c \
		print_rot13.c \
		print_address.c \
		print_percent.c \
		print_string_non_printable.c \
		justifier.c \
		get_format.c \
		_itoa.c


OBJS = $(SRCS:.c=.o)
OBJDIR = build

INC = -I .
HEADER = main.h

all: $(NAME)
	@./$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
