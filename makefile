OBJ_DIR := obj
LIB_DIR := lib
INCL_DIR := include
SRC_DIR := src

CC := gcc
CFLAGS := -Wall -Wextra -I$(INCL_DIR)

PFase2.exe: $(OBJ_DIR)/main.o lib.dll | $(OBJ_DIR)
	$(CC) $< -o $@ -L. -llib

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INCL_DIR)/header.h | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

lib.dll: $(OBJ_DIR)/lib.o $(OBJ_DIR)/lib_aux.o | $(LIB_DIR)
	$(CC) -shared -o $@ $^

$(OBJ_DIR)/lib.o: $(LIB_DIR)/lib.c $(INCL_DIR)/header.h | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/lib_aux.o: $(LIB_DIR)/lib_aux.c $(INCL_DIR)/header.h | $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	mkdir $@

$(LIB_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) PFase2.exe lib.dll
