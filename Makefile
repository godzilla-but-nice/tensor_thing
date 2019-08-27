TEST = vector-test.cpp
CC = g++-9
OBJDIR = obj/
SRCDIR = src/
TESTDIR = tests/
OBJ = ColumnVector.o vector-test.o
DEP = ColumnVector.h
DEPS = $(DEP:%.h=$(SRCDIR)%.h) tests/
FULLTEST = $(TESTDIR)$(TEST)

.PHONY = all clean

all: test

test : $(OBJ)
	$(CC) -o test $(OBJ)

vector-test.o : $(FULLTEST) $(DEPS)
	@echo "building vector-test.o..."
	$(CC) -c $(FULLTEST)

ColumnVector.o : $(SRCDIR)ColumnVector.cpp $(DEPS)
	@echo "building ColumnVector.o..."
	$(CC) -c $(SRCDIR)ColumnVector.cpp 

clean :
	rm test $(OBJ)
	rm -r obj
	mkdir obj