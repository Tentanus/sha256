
#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME			:=	sha256

OBJ_DIR			:=	OBJ
SRC_DIR			:=	src
INC_DIR			:=	inc
LIB_DIR			:=	lib

SRC					:=									\
								main.c					\
								sha256.c				\

OBJ					:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
SRC					:=	$(SRC:%=$(SRC_DIR)/%)
DEP					:=	$(OBJ:.o=.d)
DIR_LIST		:=	$(sort $(dir $(OBJ)))

-include $(DEP)

#=============  LIBRARIES ===============#

LIBFT_DIR		:=	$(LIB_DIR)/libft
LIBFT				:=	$(LIBFT_DIR)/libft.a

$(LIBFT):
	@make -C $(LIBFT_DIR)

#============= COMPILATION ==============#

INCLUDE			:=	-I $(INC_DIR)							\
								-I $(LIBFT_DIR)/include		\

CC					:=	clang
CFL					:=	-Wall -Werror -Wextra -Wpedantic

ifdef FSAN
CFL					+=	-g -fsanitize=address,undefined
endif

ifdef DEBUG
CFL					+=	-g -fstandalone-debug
CFL					+=	-D DEBUG=1
endif

ifndef NOMSG
CFL					+=	-D MSG=1
endif

#=============  SHOW TIME  ==============#

ifdef SHOW
CFL					+=	-D SHOW=1
endif

COMPILE			:=	$(CC) $(CFL)

INFO_FL			:=	\
					$(if $(findstring -g,$(CFL)),-g)			\
					$(if $(findstring address,$(CFL)),addr)		\
					$(if $(findstring undefined,$(CFL)),undef)	\
					$(if $(findstring MSG,$(CFL)),msg)			\
					$(if $(findstring DEBUG,$(CFL)),debug)		\


#========================================#
#============== RECIPIES  ===============#
#========================================#

all:$(DIR_LIST) $(NAME)

$(DIR_LIST):
	@mkdir -p $@

$(NAME): $(LIBFT) $(OBJ) compile_commands.json
	@echo ""
	@$(COMPILE) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(COMPILE) $(INCLUDE) $(CYAN)$(notdir $(OBJ))$(RESET) -o $(NAME)"

compile_commands.json: $(OBJ)
	@(echo "["; cat $(OBJ:%=%.json); echo "]") > $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@$(COMPILE) -MJ $@.json $(INCLUDE) -MMD -o $@ -c $< 
	@echo "$(CYAN)COMPILE $(INFO_FL) $(notdir $(<:%.c=%))$(RESET)"

clean: 
	@rm -rf $(OBJ_DIR)
	@rm -rf compile_commands.json
	@echo "$(RED)$(BOLD)CLEANING $(NAME)$(RESET)"

fclean: clean 
	@rm -f $(NAME)

re: fclean all

echo:
	@echo $(SRC) "\n"
	@echo $(OBJ) "\n"

#========================================#
#================= TEST =================#
#========================================#

.PHONY: utest
utest: $(NAME)
	



#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.DEFAULT_GOAL := all

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m
