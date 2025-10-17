NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_format.c ft_putnbr_fd.c ft_printf.c ft_pf_putchar.c ft_pf_puthexalow.c ft_pf_puthexaup.c\
ft_pf_putint.c ft_pf_putnbr.c ft_pf_putptr.c ft_pf_putstr.c ft_pf_putuint.c ft_pf_putunbr.c\
get_next_line_bonus.c get_next_line.c get_next_line_utils.c ft_strcmp.c free_array.c free_char.c
SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o) 

INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ)  
	@ar rcs $(NAME) $(OBJ)

# .c a .o
%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

ejecutarall:
	$(CC) $(CFLAGS) *.c
		./a.out

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
