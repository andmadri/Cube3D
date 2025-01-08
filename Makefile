NAME			=	cub3D
NAME_BONUS		=	cub3D_bonus
NAME_CRAZY		=	cub3D_crazy
RM			=	rm -rf
CC			=	cc

SRCDIR		=	src
SRC			:=	$(shell find $(SRCDIR) -iname "*.c")

BUILD			=	.build
OBJDIR			=	$(BUILD)/all
OBJDIR_BONUS	=	$(BUILD)/bonus
OBJDIR_CRAZY	=	$(BUILD)/crazy
OBJ				=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_BONUS		=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR_BONUS)/%.o)
OBJ_CRAZY		=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR_CRAZY)/%.o)

LIBXDIR		:=	lib/minilibx
LIBFTDIR	:=	lib/libft
LIBFT		:=	$(LIBFTDIR)/libft.a
OS_UNAME	:=	$(shell uname -s)

ifeq ($(OS_UNAME),Linux)
	OS_TYPE		:=	LINUX
	LIBXDIR_SUB	:=	lib/minilibx_linux
	LIBX		:=	$(LIBXDIR)/libmlx_Linux.a
	LIBXFLAGS	:=	-Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	LIBXFLAGS_O	:=	-Imlx
else ifeq ($(OS_UNAME),Darwin)
	OS_TYPE		:= MACOS
	LIBXDIR_SUB	:=	lib/minilibx-mac-osx
	LIBX		:=	$(LIBXDIR)/libmlx.dylib
	LIBXFLAGS	:=	-L ./lib/minilibx -I /usr/local/include -L /usr/local/lib -framework OpenGL -framework AppKit -lmlx
	LIBXFLAGS_O	:=	-Imlx
	CFLAGS		+= -D LINUX=0
else
	OS_TYPE		:= Linux
	LIBXDIR_SUB	:=	lib/minilibx_linux
	LIBX		:=	$(LIBXDIR)/libmlx_Linux.a
	LIBXFLAGS	:=	-Lmlx_linux  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	LIBXFLAGS_O	:=	-Imlx
endif

SUBMOD		:=	$(LIBFTDIR)/Makefile	$(LIBXDIR_SUB)/Makefile

# MLXFLAGS	:=	-ldl -lglfw -pthread -lm
# // The flag (-O3 -ffast-math) is used for optimization.
# // The flag (-framework) is used to specify the required frameworks.
# // the flag (-lglfw) is for linking the glfw library
# // the flag (-L) is for the path to the glfw library
# // the flag (-o) is for the name of the executable file-lmlx_Linux

bonus:		CFLAGS		= -Wall -Werror -Wextra -g -D BONUS=1 -D CRAZY=0
bonus:		$(SUBMOD)	$(LIBX)	$(LIBFT)	$(NAME_BONUS)

crazy:		CFLAGS		= -Wall -Werror -Wextra -g -D BONUS=1 -D CRAZY=1
crazy:		$(SUBMOD)	$(LIBX)	$(LIBFT)	$(NAME_CRAZY)

all:		CFLAGS		= -Wall -Werror -Wextra -g -D BONUS=0 -D CRAZY=0
all:		$(SUBMOD)	$(LIBX)	$(LIBFT)	$(NAME)


$(NAME):	$(OBJ)
			@$(CC) $(OBJ) $(LIBX) $(LIBFT) $(LIBXFLAGS) $(CFLAGS) -o $(NAME)
			@printf "$(CREATED)" $@ $(CUR_DIR)

$(NAME_BONUS):	$(OBJ_BONUS)
			@$(CC) $(OBJ_BONUS) $(LIBX) $(LIBFT) $(LIBXFLAGS) $(CFLAGS) -o $(NAME_BONUS)
			@printf "$(CREATED)" $@ $(CUR_DIR)

$(NAME_CRAZY):	$(OBJ_CRAZY)
			@$(CC) $(OBJ_CRAZY) $(LIBX) $(LIBFT) $(LIBXFLAGS) $(CFLAGS) -o $(NAME_CRAZY)
			@printf "$(CREATED)" $@ $(CUR_DIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(LIBXFLAGS_O) -c $< -o $@
			@printf "$(UPDATED)" $@ $(CUR_DIR)

$(OBJDIR_BONUS)/%.o:	$(SRCDIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(LIBXFLAGS_O) -c $< -o $@
			@printf "$(UPDATED)" $@ $(CUR_DIR)

$(OBJDIR_CRAZY)/%.o:	$(SRCDIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(LIBXFLAGS_O) -c $< -o $@
			@printf "$(UPDATED)" $@ $(CUR_DIR)

$(SUBMOD):
			git	submodule	init
			git	submodule	update

$(LIBX):
			$(shell cp -r $(LIBXDIR_SUB) $(LIBXDIR))
			make -C $(LIBXDIR) all
			printf "$(MADE)" $@ $(dir $(abspath $(LIBXDIR)))

$(LIBFT):
			@$(MAKE) --no-print-directory -C $(@D) all
			@printf "$(MADE)" $@ $(dir $(abspath $(LIBFT)))

clean:
			$(RM) $(BUILD)
			@printf "$(REMOVED)" $(BUILD) $(CUR_DIR)

fclean: clean
			$(RM) $(NAME) $(NAME_BONUS) $(NAME_CRAZY)
			@printf "$(REMOVED)" $(NAME) $(CUR_DIR)
			@printf "$(REMOVED)" $(NAME_BONUS) $(CUR_DIR)
			@printf "$(REMOVED)" $(NAME_CRAZY) $(CUR_DIR)

re:			fclean all

info-%:
	$(info $($*))

.PHONY: all clean fclean re bonus crazy
# .SILENT:

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

CUR_DIR := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))
REMOVED	:= \t$(RED)$(BOLD)REMOVED %s (%s) $(RESET)\n
MADE	:= \t$(GREEN)$(BOLD)MAKE -C %s (%s) $(RESET)\n
CREATED	:= \t$(GREEN)$(BOLD)CREATED %s (%s) $(RESET)\n
UPDATED	:= \t$(BLUE)$(BOLD)CREATED OR UPDATED %s (%s) $(RESET)\n
SET		:= \t$(BLUE)$(BOLD)SET OPERATING SYSTEM$(RESET)\n
