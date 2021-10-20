_INC = ../include
_OBJ = ../obj/
_SRC = ../src/

CC = g++
CFLAGS = -Wsign-compare -Wall -g -c -I$(_INC)
OBJ = belt.o state.o transition.o graph.o main.o
BINARY = automata


OBJFULL = $(patsubst %,$(_OBJ)%,$(OBJ))

all: $(BINARY) execute

$(BINARY): $(OBJ)
	$(CC) -o $(BINARY) $(OBJFULL)


# $@ main.o
# $< main.cpp
%.o: $(_SRC)%.cpp
	$(CC) $(CFLAGS) $< -o $(_OBJ)$@


execute:
	@clear
	@echo "Ejecutando el programa...\n-----------------------------"
	@./$(BINARY)


.PHONY: clean # Por si alguna vez existe un fichero clean en esta carpeta
clean: 
	@clear
	rm -rf $(BINARY) 
	rm -rf $(_OBJ)*.o *.o