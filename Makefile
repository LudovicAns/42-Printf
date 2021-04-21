# Compilation
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Value
LIBNAME = libftprintf.a
SRCDIR = src
SRC = ft_printf.c ft_printf_utils_1.c flag_utils.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: $(LIBNAME)

$(LIBNAME): init $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

init:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCDIR)/.

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf ./$(LIBNAME)

re: fclean all

.PHONY: all clean fclean re init
