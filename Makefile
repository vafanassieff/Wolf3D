# Compilation
CC =		clang
CFLAGS =	-Wall -Wextra -Werror -g -flto -O3
ADDFLAGS =	

# Precompiled header
PRECOMP =	stdafx.h

# Default rule
DEFRULE =	all

# Binary
NAME =		wolf3d
DST =

# Directories
SRCDIR =	sources
OBJDIR =	objects
ifeq ($(OS),Windows_NT)
	INCDIR =	includes\
				librairies/libft/includes\
	CFSDL =		
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		ID_UN := $(shell id -un)
		INCDIR =	includes\
					librairies/libft/includes\
					/Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.5/include/SDL2\
					/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.14/include/SDL2\
					/Users/$(ID_UN)/.brew/Cellar/sdl2_image/2.0.1_2/include/SDL2\
					-F -framework Cocoa 
		CFSDL =		
	endif
	ifeq ($(UNAME_S),Linux)
		INCDIR =	includes\
					librairies/libft/includes\
		CFSDL =		`sdl2-config --cflags`
	endif
endif
PREDIR =	includes

# Sources
SRC =		esdl/events.c\
			esdl/exit.c\
			esdl/fps.c\
			esdl/init.c\
			esdl/pixel.c\
			esdl/surface.c\
			wolf_events.c\
			display_wolf.c\
			raycasting.c\
			wolf_map.c\
			raycasting_util.c\
			raycasting_floor.c\
			main.c

OBJ =		$(SRC:.c=.o)

# Prefixes
ifeq ($(OS),Windows_NT)
	OPNCL =		-L/lib/ -lOpenCL
	LSDL2 =		-L/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image
	LMATH =		
	LPTHR =		
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		OPNCL =		-framework OpenCL
		LSDL2 =		-L/Users/$(ID_UN)/.brew/Cellar/sdl2/2.0.5/lib -lSDL2\
					-L/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf\
					-L/Users/$(ID_UN)/.brew/Cellar/sdl2_image/2.0.1_2/lib -lSDL2_image
		LMATH =		-lm
	endif
	ifeq ($(UNAME_S),Linux)
		OPNCL =		-L/usr/lib/x86_64-linux-gnu -lOpenCL
		LSDL2 =		`sdl2-config --libs` -lSDL2_ttf -lSDL2_image
		LMATH =		-lm
	endif
endif
LIBFT =		-Llibrairies/libft/ -lft

# Paths foreach
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCP =		$(foreach dir, $(INCDIR), -I$(dir))
PREP =		$(addprefix $(PREDIR)/, $(PRECOMP))
OBJS_DIRS = $(sort $(dir $(OBJP)))

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# **************************************************************************** #
# RULES
.SILENT:

# Main rules
default:
	@echo -e "$(LOG_BOLD)Default execution: rule $(DEFRULE)$(LOG_NOCOLOR)"
	@make $(DEFRULE)
	@echo -e "$(LOG_BOLD)Execution finished     $(LOG_NOCOLOR)ヽ(ヅ)ノ"

all: libcomp $(OBJDIR) $(NAME)

re: fclean all

# Compilation rules
libcomp:
	@make all -C librairies/libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)........................... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ $(INCP) $(CFSDL)

$(OBJDIR):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJS_DIRS)

$(NAME): $(OBJP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR)......................... $(LOG_YELLOW)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) $(LPTHR) -o $@ $^ $(OPNCL) $(LSDL2) $(LIBFT) $(LIBVEC) $(LMATH) $(INCP)
	@echo -e "--$(LOG_CLEAR)$(LOG_VIOLET)$(NAME)$(LOG_NOCOLOR) compiled.................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

# MrProper's legacy
.PHONY: fclean clean glu

clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libft$(LOG_NOCOLOR)"
	@make clean -C librairies/libft/


fclean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft$(LOG_NOCOLOR)"
	@make fclean -C librairies/libft/
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deletion............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deletion.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)

glu: re clean

# SDL2 brew

sdl2:
	brew install sdl2
	brew link sdl2
	brew install sdl2_ttf
	brew link sdl2_ttf
	brew install sdl2_image
	brew link sdl2_image
