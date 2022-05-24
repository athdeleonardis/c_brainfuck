EXE=bf_interpreter
CC=gcc
CFLAGS=--std=c99
OBJ_DIR=obj
SRC_DIR=src
BLD_DIR=build
OBJS = error.o stack.o linked_list.o bf.o
DEPS=$(addprefix $(OBJ_DIR)/,$(OBJS))

.PHONY: all clean pre-build build

all: pre-build build

pre-build:
	mkdir -p $(OBJ_DIR) $(BLD_DIR)

build: $(SRC_DIR)/main.c $(DEPS)
	$(CC) -o $(BLD_DIR)/$(EXE) $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f -r $(OBJ_DIR) $(BLD_DIR)