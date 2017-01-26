#include "SquareMatrix.h"
using namespace std;

SquareMatrix::SquareMatrix()
{
	MathMatrix();
}

SquareMatrix::SquareMatrix(int size, int initialValue)
{
	MathMatrix(size, size, initialValue);
}

SquareMatrix::~SquareMatrix()
{
	/*EMPTY*/
}

SquareMatrix SquareMatrix::createIdentityMatrix(int size)
{
	SquareMatrix result(size, 0);
	for (i = 0; i < size; i++) {
		result.mat[i][i] = 1;
	}
	

	return result;
}

int SquareMatrix::getDeterminant()
{
	rowSize = mat.size();
	if (rowSize == 2) {
		determinant = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
	}
	else {
		determinant = (mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])) 
		- (mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2])) + (mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]));
	}
	return determinant;
}

bool SquareMatrix::isSymmetric()
{
	rowSize = mat.size();
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < rowSize; j++) {
			if (mat[i][j] != mat[j][i]) {
				return false;
			}
		}
	}
	return true;
}