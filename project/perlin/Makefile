BDIR		=	bin
SDIR		=	src
ODIR		=	obj
IDIR		=	include

CC				=	clang++ -std=c++17 -ferror-limit=99
OPTIMIZE	=	-O3 -Wall -Wextra -pedantic
CFLAGS		=	$(OPTIMIZE) -I$(IDIR)
LIBS			=	-lm

_DEPS		=	template.hpp vector2d.hpp io.hpp \
          perlin.hpp perlin_io.hpp integrate.hpp particle.hpp
DEPS		=	$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ		=	main.o vector2d_arithmetic.o vector2d_io.o vector2d_useful.o \
          perlin_public.o perlin_private.o particle_public.o particle_private.o \
          integrate.o
OBJ 		=	$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/perlin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
