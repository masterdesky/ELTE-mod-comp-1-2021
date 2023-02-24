BDIR		=	bin
SDIR		=	src
ODIR		=	obj
IDIR		=	include

CXX				=	g++ -std=c++17
OPTIMIZE	=	-O3 -Wall -Wextra -pedantic
CFLAGS		=	$(OPTIMIZE) -I$(IDIR)
LDFLAGS		=	-lm

_DEPS		=	vector.hpp test.hpp io_test.hpp
DEPS		=	$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ		=	main.o io_test.o test.o overload_arithmetic.o \
					overload_io.o overload_useful.o overload_notuseful.o
OBJ 		=	$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BDIR)/vector_class: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
