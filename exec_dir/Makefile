# compilateur
CC=g++
CFlags=-Wall

# les dossiers
LIB_DIR=-L../lib_dir/target
INC_DIR=-I../lib_dir/include

# les fichiers
LIB=-lProjet
SRC=main.cpp
TRG=$(SRC:.cpp=)

# l'executable
all: $(TRG)

# compiler l'executable
$(TRG): $(SRC)
	$(CC) $^ -o $@ $(LIB) $(LIB_DIR) $(INC_DIR)

# executer l'executable
run: $(TRG)
	./$^

# supprimer l'executable
clean:
	rm -f $(TRG)