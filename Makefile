#We use a macro to set the program name
PROG=basics

SRC=$(wildcard *.cc)
OBJ=$(SRC:.cc=.o)

CXX=clang++ #g++ (you can use either clang++ or g++ in Unix/Linux/mac OS)
CXXFLAGS= -g -O2 -Wall -std=c++11 
CCFLAGS=
CXXLIBS=
CCLIBS=
LDFLAGS=

all: $(PROG)

$(PROG): $(OBJ)
	$(CXX) -o$@ $^ $(LDFLAGS) $(CXXLIBS) $(CCLIBS)
	@echo "...."
	@echo "'make help' to see other options"

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CCFLAGS) -c $< -o$@

clean:
	rm -f *.o *~

help: 
	@echo "...."
	@echo "'make clean' to delete the object files"
	@echo "'make mrproper' clean the executable as well"

mrproper: clean
	rm -f $(PROG) $(PROG).exe

.PHONY: all clean mrproper help
