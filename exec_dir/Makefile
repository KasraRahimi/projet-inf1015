# compilateur
CC=g++
CFlags=-Wall -std=c++17

# les dossiers
LIB_DIR=-L../lib_dir/target
INC_DIR=-I../lib_dir/include

# les fichiers
LIB=-lProjet
SRC=main.cpp
TRG=$(SRC:.cpp=)
DBG=$(SRC:.cpp=_dbg)

# l'executable
all: $(TRG)

# compiler l'executable
$(TRG): $(SRC)
	$(CC) $^ -o $@ $(LIB) $(LIB_DIR) $(INC_DIR)

# executer l'executable
run: $(TRG)
	./$^

#compile debuggable executable
$(DBG): $(SRC)
	$(CC) -g $^ -static -o $@ $(LIB) $(LIB_DIR) $(INC_DIR)

#run debugger
debug: $(DBG)
	gdb $<

# supprimer l'executable
clean:
	rm -f $(TRG) $(DBG)