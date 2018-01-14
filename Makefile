# Makefile for the Monster Game

SRC_DIR=src
DOC_DIR=Documentation

SRC_FILES=$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.cpp, %.o, $(SRC_FILES))

EXE_FILE=MonsterGame

## all       : Compile code and create executible 
.PHONY : all
all : $(EXE_FILE)

$(EXE_FILE) : $(OBJ_FILES)
	g++  $^ -o $@

## objs      : create object files
.PHONY : objs
objs : $(OBJ_FILES)

%.o : $(SRC_DIR)/%.cpp
	g++ -c -std=c++11 $<

## docs		: create documentation
.PHONY : docs
docs : $(SRC_FILES)
	doxygen Doxyfile



## clean     : remove auto generated files
.PHONY : clean
clean :
	rm -f $(OBJ_FILES)
	rm -f $(EXE_FILE)
	rm -r $(DOC_DIR)

## variables : Print variables
.PHONY :variables
variables:
	@echo SRC_DIR:   $(SRC_DIR)
	@echo SRC_FILES: $(SRC_FILES)
	@echo OBJ_FILES: $(OBJ_FILES)
	

## help      : Print help
.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<