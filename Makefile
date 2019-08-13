CC = g++
CFLAGS = -I
OBJ = tensorFuncs.o test.o
DEP = tensor.h myVector.h scalar.h matrix.h

test : $(OBJ)
	$(CC) -o test $(OBJ)

test.o : test.cpp $(DEP)
	$(CC) -c test.cpp

tensorFuncs.o : tensorFuncs.cpp $(DEP)
	$(CC) -c tensorFuncs.cpp

clean :
	rm test $(OBJ)