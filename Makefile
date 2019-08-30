TEST = vector-test.cpp matrix-test.cpp
CXX ?= g++
OBJDIR = obj/
SRCDIR = src/
TESTDIR = tests/
VECOBJ = ColumnVector.o vector-test.o
MATOBJ = ColumnVector.o Matrix.o matrix-test.o
VECOBJS = $(VECOBJ:%.o=$(OBJDIR)%.o)
MATOBJS = $(MATOBJ:%.o=$(OBJDIR)%.o)
DEP = ColumnVector.h Matrix.h
DEPS = $(DEP:%.h=$(SRCDIR)%.h) tests/
FULLTEST = $(join $(TESTDIR), $(TEST))

ifdef PHYSICELL_CPP 
	CXX := $(PHYSICELL_CPP)
endif

.PHONY = clean

all: VectorTest MatrixTest

VectorTest : $(VECOBJS)
	@echo "Creating executable..."
	$(CXX) -o VectorTest $(VECOBJS)

MatrixTest : $(MATOBJS)
	$(CXX) -o MatrixTest $(MATOBJS)

$(OBJDIR)vector-test.o : $(TESTDIR)vector-test.cpp $(DEPS)
	@echo "building vector-test.o..."
	mkdir -p $(OBJDIR)
	$(CXX) -c $(TESTDIR)vector-test.cpp -o $(OBJDIR)vector-test.o

$(OBJDIR)matrix-test.o : $(TESTDIR)matrix-test.cpp $(DEPS)
	$(CXX) -c $(TESTDIR)matrix-test.cpp -o $(OBJDIR)matrix-test.o

$(OBJDIR)ColumnVector.o : $(SRCDIR)ColumnVector.cpp $(DEPS)
	@echo "building ColumnVector.o..."
	mkdir -p $(OBJDIR)
	$(CXX) -c $(SRCDIR)ColumnVector.cpp -o $(OBJDIR)ColumnVector.o

$(OBJDIR)Matrix.o : $(SRCDIR)Matrix.cpp $(DEPS)
	@echo "building Matrix.o..."
	mkdir -p $(OBJDIR)
	$(CXX) -c $(SRCDIR)Matrix.cpp -o $(OBJDIR)Matrix.o

clean :
	rm -fr obj
	rm -f VectorTest
	rm -f MatrixTest
