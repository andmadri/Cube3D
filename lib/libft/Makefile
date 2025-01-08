NAME	=	libft.a
CFLAGS	=	-Wall -Werror -Wextra -Wunused -Wuninitialized -Wunreachable-code -MMD
SRCDIR	=	src
SRC		=	src/ft_printf/chars.c	\
			src/ft_printf/printf.c	\
			src/ft_printf/numbers.c	\
			src/ft_printf/hex.c	\
			src/get_next_line/get_next_line_utils.c	\
			src/get_next_line/get_next_line.c	\
			src/libft/convert/ft_tolower.c	\
			src/libft/convert/ft_toupper.c	\
			src/libft/convert/ft_split.c	\
			src/libft/convert/ft_itoa.c	\
			src/libft/convert/ft_atoi.c	\
			src/libft/istype/ft_isalnum.c	\
			src/libft/istype/ft_isupper.c	\
			src/libft/istype/ft_isdigit.c	\
			src/libft/istype/ft_islower.c	\
			src/libft/istype/ft_isalpha.c	\
			src/libft/istype/ft_isspace.c	\
			src/libft/istype/ft_isprint.c	\
			src/libft/istype/ft_isascii.c	\
			src/libft/str/ft_strrchr.c	\
			src/libft/str/ft_strncmp.c	\
			src/libft/str/ft_strchr.c	\
			src/libft/str/ft_strcmp.c	\
			src/libft/str/ft_strndup.c	\
			src/libft/str/ft_strdup.c	\
			src/libft/str/ft_substr.c	\
			src/libft/str/ft_strlcat.c	\
			src/libft/str/ft_strmapi.c	\
			src/libft/str/ft_striteri.c	\
			src/libft/str/ft_strlen.c	\
			src/libft/str/ft_strnstr.c	\
			src/libft/str/ft_strtrim.c	\
			src/libft/str/ft_strjoin.c	\
			src/libft/str/ft_strlcpy.c	\
			src/libft/malloc/ft_dynstralloc.c	\
			src/libft/malloc/ft_bzero.c	\
			src/libft/malloc/ft_calloc.c	\
			src/libft/malloc/ft_free_strarr.c	\
			src/libft/mem/ft_memcmp.c	\
			src/libft/mem/ft_memmove.c	\
			src/libft/mem/ft_memset.c	\
			src/libft/mem/ft_memchr.c	\
			src/libft/mem/ft_memcpy.c	\
			src/libft/list/ft_lstadd_front.c	\
			src/libft/list/ft_lstsize.c	\
			src/libft/list/ft_lstdelone.c	\
			src/libft/list/ft_lstclear.c	\
			src/libft/list/ft_lstiter.c	\
			src/libft/list/ft_lstlast.c	\
			src/libft/list/ft_lstmap.c	\
			src/libft/list/ft_lstnew.c	\
			src/libft/list/ft_lstadd_back.c	\
			src/libft/put/ft_putnbr_fd.c	\
			src/libft/put/ft_putendl_fd.c	\
			src/libft/put/ft_putstr_fd.c	\
			src/libft/put/ft_putchar_fd.c
OBJDIR	=	obj
OBJ		=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM		=	rm	-rf
AR		=	ar	-rcs
DIR_DUP	=	mkdir	-p	$(@D)

.PHONY:	all	clean	fclean	re
.SILENT:

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(AR)	$(NAME)	$(OBJ)
	@printf "$(CREATED)" $@ $(CUR_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(DIR_DUP)
	@cc	$(CFLAGS)	-c	-o	$@	$<
	@printf "$(BUILDING)" $@ $(CUR_DIR)

clean:
	@$(RM)	$(OBJDIR)
	@printf "$(REMOVED)" $(OBJDIR) $(CUR_DIR)

fclean:	clean
	@$(RM)	$(NAME)
	@printf "$(REMOVED)" $(NAME) $(CUR_DIR)

info-%:
	$(info $($*))

re:	fclean	all

# ----------------------------------- colors --------------------------------- #

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

# ----------------------------------- messages ------------------------------- #

CUR_DIR 	:= $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED		:= \t$(RED)$(BOLD)REMOVED %s (%s) $(RESET)\n
CREATED		:= \t$(GREEN)$(BOLD)CREATED %s (%s) $(RESET)\n
BUILDING	:= \t$(BLUE)$(BOLD)BUILDING %s (%s) $(RESET)\n
UPDATED		:= \t$(BLUE)$(BOLD)CREATED OR UPDATED %s (%s) $(RESET)\n
