NAME = pathfinder
LIBMX_NAME = libmx

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBMX_DIR = libmx
LIBMX_INC = $(LIBMX_DIR)/inc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INC_DIR)/*.h)
LIBMX_FILES = $(wildcard ./$(LIBMX_NAME)/*.a)

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
AR = ar
AFLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

all: libmx $(NAME) 

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBMX_DIR) -lmx -o $@
	@printf "\r\33[2K$@\t\033[32;1mcreated\033[0m\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I$(LIBMX_INC)
	@printf "\r\33[2K$(NAME)\033[33;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c=%)\r"

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEBIN)
	@make -C $(LIBMX_DIR) uninstall
	@@printf "$(NAME)\t \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

@libmx: $(LIBMX_DIR)

$(LIBMX_DIR) :
	@make -C $@
	@printf "\r\33[2K$@\033[33;1m\t compile \033[0m\r"
# .PHONY - это явное указание имен целей мейкфайла, например, если
# в папке будет файл clean и попытаться выполнить команду make clean,
# то make попытается выполнить файл clean, а не цель clean
run: all
	@printf "\n"
	./pathfinder

oracle: 
	./oracle 

.PHONY: all uninstall clean reinstall libmx run oracle
