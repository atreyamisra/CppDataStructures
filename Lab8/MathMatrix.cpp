#include "MathMatrix.h" 
#include <iostream> //DELETE AFTERWARDS
using namespace std;

MathMatrix::MathMatrix()
{
	mat.push_back(row); //create row
	mat[0].push_back(0); //create column with value of zero
}

MathMatrix::MathMatrix(int numRows, int numCols, int** mat)
{
	for (i = 0; i < numRows; i++) {
		this->mat.push_back(row);
		for (j = 0; j < numCols; j++) {
			this->mat[i].push_back(mat[i][j]);
		}
	}
	
}

MathMatrix::MathMatrix(const vector<vector<int>>& mat)
{
	this->mat = mat;
}

MathMatrix::MathMatrix(int numRows, int numCols, int initialValue)
{
	for (i = 0; i < numRows; i++) {
		mat.push_back(row);
		for (j = 0; j < numCols; j++) {
			mat[i].push_back(initialValue);
		}
	}
}

MathMatrix::~MathMatrix()
{
	/* EMPTY */
}

void MathMatrix::changeElement(int row, int col, int newValue)
{
	mat[row][col] = newValue;
	return;
}
int MathMatrix::numRows() const
{
	return mat.size();
}
int MathMatrix::numCols() const
{
	if (mat.size() == 0) 
		return 0;
	else
		return mat[0].size();
}
int MathMatrix::getVal(int row, int col)
{
	return mat[row][col];
}
MathMatrix MathMatrix::add(const MathMatrix& rightHandSide)
{
	rowSize = mat.size();
	if (rowSize == 0) {
		MathMatrix result(rowSize, 0, 0);
		return result;
	}
	else {
		colSize = mat[0].size();
		MathMatrix result(rowSize, colSize, 0);
		result.mat = mat;
		for (i = 0; i < rowSize; i++) {
			for (j = 0; j < colSize; j++) {
				result.mat[i][j] = result.mat[i][j] + rightHandSide.mat[i][j];
			}
		}
		return result;
	}
}
MathMatrix MathMatrix::subtract(const MathMatrix& rightHandSide)
{
	rowSize = mat.size();
	if (rowSize == 0) {
		MathMatrix result(rowSize, 0, 0);
		return result;
	}
	else {
		colSize = mat[0].size();
		MathMatrix result(rowSize, colSize, 0);
		result.mat = mat;
		for (i = 0; i < rowSize; i++) {
			for (j = 0; j < colSize; j++) {
				result.mat[i][j] = result.mat[i][j] - rightHandSide.mat[i][j];
			}
		}

		return result;
	}
}
MathMatrix MathMatrix::multiply(const MathMatrix& rightHandSide)
{
	rowSize = mat.size();
	rowSize2 = rightHandSide.mat.size();
	if (rowSize == 0 && rowSize2 == 0) {
		MathMatrix result(rowSize, 0, 0);
		return result;
	}
	else {
		colSize = rightHandSide.mat[0].size();
		MathMatrix result(rowSize, colSize, 0);
		for (i = 0; i < rowSize; i++) {
			for (j = 0; j < colSize; j++) {
				for (a = 0, b = 0; a < rowSize2; a++, b++) {
					result.mat[i][j] = result.mat[i][j] + (mat[i][a] * rightHandSide.mat[b][j]);
				}
			}
		}

		return result;
	}

}

bool MathMatrix::equals(const MathMatrix& rightHandSide)
{
	rowSize = mat.size();
	if (rowSize == 0) {
		return false;
	}
	else {
		colSize = mat[0].size();
		for (i = 0; i < rowSize; i++) {
			for (j = 0; j < colSize; j++) {
				if (mat[i][j] != rightHandSide.mat[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
}

MathMatrix MathMatrix:: operator+(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	result = add(rightHandSide);
	return result;
}

MathMatrix MathMatrix:: operator-(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	result = subtract(rightHandSide);
	return result;
}
MathMatrix MathMatrix:: operator*(const MathMatrix& rightHandSide)
{
	MathMatrix result;
	result = multiply(rightHandSide);
	return result;
}

bool MathMatrix:: operator==(const MathMatrix& rightHandSide)
{
	if (equals(rightHandSide)) {
		return true;
	}
	return false;
}

MathMatrix MathMatrix::scale(int factor)
{
	MathMatrix result;
	result.mat = mat;
	rowSize = mat.size();
	colSize = mat[0].size();
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < colSize; j++) {
			result.mat[i][j] = result.mat[i][j] * factor;
		}
	}
	return result;
}
MathMatrix MathMatrix::getTranspose()
{
	rowSize = mat[0].size();
	colSize = mat.size();
	MathMatrix result(rowSize, colSize, 0);
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < colSize; j++) {
			result.mat[i][j] = mat[j][i];
		}
	}
	return result;
}
void MathMatrix::printMatrix() //DELETE AFTERWARDS
{
	rowSize = mat.size();
	colSize = mat[0].size();
	for (i = 0; i < rowSize; i++) {
		for (j = 0; j < colSize; j++) {
			cout << mat[i][j];
			printf(" ");
		}
		cout << endl;
	}
}