VectorOperations.o : VectorOperations.cc VectorOperations.hh
		g++ -c -O VectorOperations.cc

SparseMatrix.o : SparseMatrix.cc SparseMatrix.hh VectorOperations.hh
		g++ -c -O SparseMatrix.cc

main.o : main.cc VectorOperations.cc SparseMatrix.cc
		g++ -c -O main.cc

Assignment_1 : VectorOperations.o SparseMatrix.o main.o
		g++ -O -o Assignment_1 VectorOperations.o SparseMatrix.o main.o 