SDIR			=		src
ODIR			=		obj
IDIR			=		include
#LDIR			=		lib
LIBS			=		-lm

CC				=		clang++ -std=c++17
OPTIMIZE	=		-O3 -Wall
CFLAGS		=		$(OPTIMIZE) -I$(IDIR)

_DEPS			=		template.h generate_grid.h
DEPS			=		$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ			=		generate_perlin_noise.o generate_grid.o 
OBJ				=		$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

perlin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~