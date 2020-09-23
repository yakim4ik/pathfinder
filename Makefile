NAME = libmx.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
INC_FILES = $(wildcard $(INC_DIR)/*.h)

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
AR = ar
AFLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $(AFLAGS) $@ $^
	@printf "\r\33[2K$@\t\033[32;1mcreated\033[0m\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
	@printf "\r\33[2K$(NAME)\033[33;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c=%)\r"

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEBIN)
	@@printf "$(NAME)\t \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

# .PHONY - это явное указание имен целей мейкфайла, например, если
# в папке будет файл clean и попытаться выполнить команду make clean,
# то make попытается выполнить файл clean, а не цель clean
.PHONY: all uninstall clean reinstall

