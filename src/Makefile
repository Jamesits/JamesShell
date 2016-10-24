SRC = builtin.c  exec.c  jsh.c  main.c
PROGRAM = jsh.out
OBJ = $(SRC:.c=.o)
CC = gcc
# INCLUDE = -I/usr/include/ncurses -I/usr/include/
#MINGW_PATH = C:\MinGW\lib\gcc\mingw32\4.8.1
#INCLUDE = -I"$(MINGW_PATH)/include/" \
			-I"$(MINGW_PATH)/lib/gcc/mingw32/4.5.2/include" \
			-I"$(MINGW_PATH)/lib/gcc/mingw32/4.5.2/include/c++" \
			-I"$(MINGW_PATH)/lib/gcc/mingw32/4.5.2/include/c++/backward" \
			-I"$(MINGW_PATH)/lib/gcc/mingw32/4.5.2/include/c++/mingw32" \
			-I"$(MINGW_PATH)/lib/gcc/mingw32/4.5.2/include-fixed"
# LINKPARAM = -lpthread -lncurses
CFLAGS = -O0 -Wall -Wextra -Wno-unused-parameter -g
# ARG = 1
# EXEC_PREFIX = 
RM_FLAGS = -I

: $(PROGRAM)

$(PROGRAM): $(OBJ)
	@echo "> Linking $(OBJ)..."
	@$(CC) -o $(PROGRAM) $(LINKPARAM) $(OBJ)

%.o: %.c
	@echo "> Compiling $<..."
	@$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

exec: $(PROGRAM)
	@echo "> Executing $(PROGRAM)"
	@echo "> =================================================="
	@$(EXEC_PREFIX) $(PROGRAM) $(ARG)
	@echo ""
	@echo "> =================================================="
	@echo "> Program finished."

clean:
	@echo "> Cleaning all binary files..."
	@echo "> List of files to be deleted:"
	@echo "> $(OBJ) $(PROGRAM)"
	@rm $(RM_FLAGS) $(OBJ) $(PROGRAM)

