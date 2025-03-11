
#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME			:=	sha256

SRC					:=									\
								sha256.c				\
								main.c					\

include make/definitions.mk
-include $(DEP)

#=============  LIBRARIES ===============#

LIBFT_DIR		:=	$(LIB_DIR)/libft
LIBFT				:=	$(LIBFT_DIR)/libft.a

$(LIBFT):
	@make -C $(LIBFT_DIR)

#============= COMPILATION ==============#

INCLUDE			:=	-I $(INC_DIR)							\
								-I $(LIBFT_DIR)/include

#========================================#
#============== RECIPIES  ===============#
#========================================#

.PHONY: all
all:$(DIR_LIST) $(NAME)

$(DIR_LIST):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ) compile_commands.json
	@echo ""
	@$(COMPILE) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(COMPILE) $(GREEN)$(INCLUDE) $(CYAN)$(notdir $(OBJ)) $(BLUE)$(LIBFT) $(RESET)-o $(NAME)"

.PHONY: compile_commands.json
compile_commands.json: $(OBJ)
	@(echo "["; cat $(OBJ:%=%.json); echo "]") > $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(COMPILE) -MJ $@.json $(INCLUDE) -MMD -o $@ -c $< 
	@echo "$(CYAN)COMPILE $(INFO_FL) $(notdir $(<:%.c=%))$(RESET)"

.PHONY: clean
clean: 
	@rm -rf $(OBJ_DIR)
	@rm -rf compile_commands.json
	@echo "$(RED)$(BOLD)CLEANING $(NAME)$(RESET)"

.PHONY: fclean
fclean: clean 
	@rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: echo
echo:
	@echo $(SRC) "\n"
	@echo $(OBJ) "\n"

#================= TEST =================#

include make/unit_test.mk

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean re echo compile_commands.json

.DEFAULT_GOAL := all

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
BLUE	:= \033[34;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m
