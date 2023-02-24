BDIR		=	bin
SDIR		=	src
ODIR		=	obj
IDIR		=	include

CC				=	clang++ -std=c++17 -ferror-limit=99
OPTIMIZE	=	-O3 -Wall -Wextra -pedantic
CFLAGS		=	$(OPTIMIZE) -I$(IDIR)
LIBS			=	-lm

_DEPS		=	template.hpp io.hpp flow_field.hpp perlin.hpp perlin_io.hpp \
          particle.hpp particle_io.hpp
DEPS		=	$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ		=	main.o flow_field.o perlin_public.o perlin_private.o \
          particle_public.o particle_private.o
OBJ 		=	$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/perlin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
