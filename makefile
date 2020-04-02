IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
# LDIR =../lib
#
# LIBS=-lm

# List all header files here
_DEPS = art.h endSim.h intro.h starter.h util.h battleUI.h pokeFiles.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# List all code files here as .o files
_OBJ = main.o art.o util.o intro.o starter.o endSim.o battleUI.o pokeFiles.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) #$(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
