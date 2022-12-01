# compilateur
CC=g++
CFlags=-Wall

# les dosiers
SRC_DIR=./source
TRG_DIR=./target
INC_DIR=./include
BLD_DIR=./build

# les fichiers
SRC=$(wildcard $(SRC_DIR)/*.cpp)
BLD=$(subst $(SRC_DIR),$(BLD_DIR),$(SRC:.cpp=.o))
INC=$(wildcard $(INC_DIR)/*.h)
TRG=$(TRG_DIR)/libProjet.a

# le fichier cible
all: $(TRG)

# compilation de la librairie statique
$(TRG): $(BLD)
	ar crs $@ $^

# compilation des fichier .o
$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $^ -o $@ $(CFlags) -I$(INC_DIR)

# supprimer les fichiers de build
clean:
	rm -f $(TRG_DIR)/* $(BLD_DIR)/*