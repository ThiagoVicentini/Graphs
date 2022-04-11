SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include
FLAGS = -O3 -Wall

all: graphADT myapps

graphADT: \
	$(OBJ)/graph.o \
	$(OBJ)/list.o

myapps: \
	$(BIN)/test_graph

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
	$(BIN)/test_graph

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear