
#========================================#
#============  DEFINITIONS  =============#
#========================================#

OBJ_DIR			:=	OBJ
SRC_DIR			:=	src
INC_DIR			:=	inc
LIB_DIR			:=	lib

OBJ					:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
SRC					:=	$(SRC:%=$(SRC_DIR)/%)
DEP					:=	$(OBJ:.o=.d)
DIR_LIST		:=	$(sort $(dir $(TOBJ) $(OBJ)))

#============= COMPILATION ==============#

CC					:=	clang++
CFL					:=	-Wall -Werror -Wextra -Wpedantic

ifdef FSAN
CFL					+=	-g -fsanitize=address,undefined
endif

ifdef DEBUG
CFL					+=	-g
endif

ifndef NOMSG
CFL					+=	-D MSG=1
endif

#=============  SHOW TIME  ==============#

COMPILE			:=	$(CC) $(CFL)

INFO_FL			:=	\
								$(if $(findstring -g,$(CFL)),-g)			\
								$(if $(findstring address,$(CFL)),addr)		\
								$(if $(findstring undefined,$(CFL)),undef)	\
								$(if $(findstring MSG,$(CFL)),msg)			\
								$(if $(findstring DEBUG,$(CFL)),debug)		\

