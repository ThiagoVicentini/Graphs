SRC = ./src
OBJ = ./obj
BIN = ./bin
APPS = ./apps
INCLUDE = ./include

all: queueADT myapps

queueADT: \
	$(OBJ)/queue.o

myapps: \
	$(BIN)/test_queue

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c $(OBJ)/*.o
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

init:
	mkdir $(BIN) $(OBJ)

run:
	$(BIN)/test_queue

clean:
	rm -rf $(BIN)/* $(OBJ)/*
	clear