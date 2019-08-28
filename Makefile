TEST = vector-test.cpp
CXX ?= g++
OBJDIR = obj/
SRCDIR = src/
TESTDIR = tests/
OBJ = $(OBJDIR)ColumnVector.o $(OBJDIR)vector-test.o
DEP = ColumnVector.h
DEPS = $(DEP:%.h=$(SRCDIR)%.h) tests/
FULLTEST = $(TESTDIR)$(TEST)

.PHONY = all clean

all: test

test : $(OBJ)
	@echo "Creating executable..."
	$(CXX) -o $(OBJDIR)test $(OBJ)

$(OBJDIR)vector-test.o : $(FULLTEST) $(DEPS)
	@echo "building vector-test.o..."
	mkdir -p $(OBJDIR)
	$(CXX) -c $(FULLTEST) -o $(OBJDIR)vector-test.o

$(OBJDIR)ColumnVector.o : $(SRCDIR)ColumnVector.cpp $(DEPS)
	@echo "building ColumnVector.o..."
	mkdir -p $(OBJDIR)
	$(CXX) -c $(SRCDIR)ColumnVector.cpp -o $(OBJDIR)ColumnVector.o

clean :
	rm -r obj