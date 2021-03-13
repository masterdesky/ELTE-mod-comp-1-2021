BDIR		=	bin
SDIR		=	src
ODIR		=	obj
IDIR		=	include

CC				=	clang++ -std=c++17
OPTIMIZE	=	-O3 -Wall -Wextra -pedantic
CFLAGS		=	$(OPTIMIZE) -I$(IDIR)
LIBS			=	-lm

_DEPS		=	template.h generate_grid.h
DEPS		=	$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ		=	main.o generate_grid.o
OBJ 		=	$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/perlin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
