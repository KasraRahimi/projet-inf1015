# compilateur
CC=g++ -std=c++17
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
	mkdir -p $(TRG_DIR)
	ar crs $@ $^

# compilation des fichier .o
$(BLD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	mkdir -p $(BLD_DIR)
	$(CC) -g -c $< -o $@ $(CFlags) -I$(INC_DIR)

# supprimer les fichiers de build
clean:
	rm -f $(TRG_DIR)/* $(BLD_DIR)/*