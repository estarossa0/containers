NAME = containers
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = ./srcs
HEADER_FOLDER = ./includes
OBJECT_FOLDER = ./objects

BONUS_SRC_FOLDER = ./bonus_src
BONUS_OBJECT_FOLDER = ./bonus_objects
BONUS_HEADER_FOLDER = ./bonus_header

LIBS =

RED = \033[0;31m
GREEN = \033[0;32m
GOLD = \033[0;33m
RESET = \033[0m

SRC_FILES =

OBJECT_FILES = $(SRC_FILES:.cpp=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
BONUS_OBJECT_FILES = $(BONUS_SRC_FILES:.c=.o)
BONUS_OBJECT_FILES := $(addprefix $(BONUS_OBJECT_FOLDER)/, $(BONUS_OBJECT_FILES))

.PHONY = all bonus clean fclean re credit

all: credit $(NAME)

bonus: credit $(BONUS_OBJECT_FILES)
	@ar rcs $(NAME)_bonus.a $(BONUS_OBJECT_FILES)
	@echo
	@echo "library $(NAME)_bonus created $(GREEN){OK}$(RESET)"

$(BONUS_OBJECT_FOLDER)/%.o: $(BONUS_SRC_FOLDER)/%.c
	@(mkdir $(BONUS_OBJECT_FOLDER) 2> /dev/null && echo "creating "$(BONUS_OBJECT_FOLDER)" folder $(GOLD){OK}$(RESET)") || true
	@clang++ $(FLAGS) -g -I $(BONUS_HEADER_FOLDER) -I $(LIBFT_HEADER) -o $@ -c $< && echo "creating" $< "object $(GOLD){OK}$(RESET)"

$(NAME): $(OBJECT_FILES)
	@ar rcs $(NAME).a $(OBJECT_FILES)
	@echo
	@echo "library $(NAME) created $(GREEN){OK}$(RESET)"

$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating "$(OBJECT_FOLDER)" folder $(GREEN){OK}$(RESET)") || true
	@clang++ $(FLAGS) -g -I $(HEADER_FOLDER) -I $(LIBFT_HEADER) -o $@ -c $< && echo "creating" $< "object $(GREEN){OK}$(RESET)"

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true
	@(rm $(BONUS_OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(BONUS_OBJECT_FILES)) || true
	@(rm -r $(BONUS_OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(BONUS_OBJECT_FOLDER)) || true

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true
	@(rm $(NAME)_bonus 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)_bonus) || true

re: fclean $(NAME)

credit:
	@printf "					$(RED)_$(NAME) made by:_$(RESET)\n"
	@echo "███████╗ ██████╗████████╗ █████╗ ██████╗  █████╗  ██████╗ ██████╗ █████╗"
	@echo "██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗"
	@echo "█████╗  ╚█████╗    ██║   ███████║██████╔╝██║  ██║╚█████╗ ╚█████╗ ███████║"
	@echo "██╔══╝   ╚═══██╗   ██║   ██╔══██║██╔══██╗██║  ██║ ╚═══██╗ ╚═══██╗██╔══██║"
	@echo "███████╗██████╔╝   ██║   ██║  ██║██║  ██║╚█████╔╝██████╔╝██████╔╝██║  ██║"
	@echo "╚══════╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"
