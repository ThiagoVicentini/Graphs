SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include

all: listADT myapps

listADT: \
	$(OBJ)/list.o

myapps: \
	$(BIN)/test_list

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
	$(BIN)/test_list

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear