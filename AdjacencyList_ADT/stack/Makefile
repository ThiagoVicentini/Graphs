SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include

all: stackADT myapps

stackADT: \
	$(OBJ)/stack.o

myapps: \
	$(BIN)/test_stack

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
	$(BIN)/test_stack

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear