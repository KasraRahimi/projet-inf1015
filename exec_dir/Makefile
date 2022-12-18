# compilateur
CC=g++
CFlags=-Wall -std=c++17

# les dossiers
LIB_DIR=../lib_dir
LIB_TRG_DIR=../lib_dir/target
INC_DIR=../lib_dir/include

# les fichiers
LIB=Projet
SRC=main.cpp
TRG=$(SRC:.cpp=)
DBG=$(SRC:.cpp=_dbg)

# l'executable
all: $(TRG)

# compiler la librairie
$(LIB_TRG_DIR)/lib$(LIB).a:
	cd $(LIB_DIR) && make

# compiler l'executable
$(TRG): $(SRC) $(LIB_TRG_DIR)/lib$(LIB).a
	$(CC) $^ -o $@ -l$(LIB) -L$(LIB_TRG_DIR) -I$(INC_DIR)

# executer l'executable
run: $(TRG)
	./$^

#compile debuggable executable
$(DBG): $(SRC)
	$(CC) -g $^ -static -o $@ -l$(LIB) -L$(LIB_TRG_DIR) -I$(INC_DIR)

#run debugger
debug: $(DBG)
	gdb $<

# supprimer l'executable
clean:
	rm -f $(TRG) $(DBG)