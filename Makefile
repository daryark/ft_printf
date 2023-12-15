NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c	ft_define_struct.c	\
		ft_flags_checker.c	ft_choose_format.c 
OBJS = $(SRCS:.c=.o)

LIBFT_NAME = libft.a
LIBFT_DIR = ../1_libft

all: $(NAME)

makelibft:
	cd $(LIBFT_DIR); make
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)

$(NAME): makelibft $(OBJS)
	ar rcs $@ $^

$(OBJS): $(SRCS)

clean:
	rm -f $(OBJS)
	cd $(LIBFT_DIR); make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR); make fclean

re: fclean all

.PHONY: all clean fclean re

# make -C $(LIBFT_DIR)
# make -C $(LIBFT_DIR) is and equivalent to: cd $(LIBFT_DIR); make 
# cp - means copy than specify $(src) $(dest)