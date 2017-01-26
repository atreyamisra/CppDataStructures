#include "MathMatrix.h"
using namespace std;

class SquareMatrix : public MathMatrix {
private:
	int determinant;

public:

	SquareMatrix();

	~SquareMatrix();

	SquareMatrix(int size, int initialValue);

	/*
		Returns a new SquareMatrix that is of dimensions
		size x size with 1's along the diagonal and 0
		in all other positions.
	*/
	SquareMatrix createIdentityMatrix(int size);

	/*
		Returns the determinant of the matrix.
	*/
	int getDeterminant();

	/*
		Returns true if SquareMatrix is equal to the
		transpose of itself.
	*/
	bool isSymmetric();
};