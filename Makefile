# Compilation
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Value
LIBNAME = libftprintf.a
SRCDIR = src
SRC = argument_type_utils.c \
		flag_utils.c \
		ft_printf_utils_1.c \
		ft_printf.c \
		identifier_utils.c \
		print_settings_utils_1.c \
		print_settings_utils_2.c \
		process_utils_1.c \
		process_utils_2.c \
		c_process.c \
		d_process.c \
		d_process_utils_1.c \
		i_process.c \
		p_process.c \
		percentage_process.c \
		s_process_utils_1.c \
		s_process.c \
		u_process_utils_1.c \
		u_process.c \
		x_process_utils_1.c \
		x_process.c \
		upperx_process_utils_1.c \
		upperx_process.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(LIBNAME)

$(LIBNAME): init $(OBJ)
	@ ar rc $@ $(OBJ)
	@ ranlib $@

bonus: all

init:
	@ mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCDIR)/.

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf ./$(LIBNAME)

re: fclean all

.PHONY: all clean fclean re init
