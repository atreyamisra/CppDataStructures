#include <vector>
using namespace std;

class MathMatrix
{
protected:
	vector<vector<int>> mat;
	vector<int> row;
	int  i, j, colSize, rowSize, rowSize2;

private:
	int a, b;

public:

	
	MathMatrix();

	MathMatrix(int numRows, int numCols, int** mat);
    
    MathMatrix(const vector<vector<int>>& mat);

	MathMatrix(int numRows, int numCols, int initialValue);
	/*
		Destructor - delete all allocated member variables
	*/
	~MathMatrix();

	void changeElement(int row, int col, int newValue);
	
	int numRows() const;

	int numCols() const;

	int getVal(int row, int col);

	/*
		Returns the result of matrix addition as a new MathMatrix
	*/
	MathMatrix add(const MathMatrix& rightHandSide);

	/*
		Returns the result of matrix subtraction as a new MathMatrix
	*/
	MathMatrix subtract(const MathMatrix& rightHandSide);

	/*
		Returns the result of matrix multiplication as a new MathMatrix
	*/
	MathMatrix multiply(const MathMatrix& rightHandSide);

	/*
		Returns true if two MathMatricies have the same int in every
		position in the matrix. Note: matricies are not necessarily 
        equal in size.
	*/
	bool equals(const MathMatrix& rightHandSide);

	/*
		Overloaded + operator. Performs matrix addition.
	*/
	MathMatrix operator+(const MathMatrix& rightHandSide);

	/*
		Overloaded - operator. Performs matrix subtraction.
	*/
	MathMatrix operator-(const MathMatrix& rightHandSide);

	/*
		Overloaded * operator. Performs matrix multiplication
	*/
	MathMatrix operator*(const MathMatrix& rightHandSide);

	/*
		Overloaded == operator. Returns true if two MathMatricies
		are equal by the definition given above.
	*/
	bool operator==(const MathMatrix& rightHandSide);

	/*
		Multiplies each element in the matrix by a scaler and
		returns a new MathMatrix.
	*/
	MathMatrix scale(int factor);

	/*
		Returns the transpose of a MathMatrix by making each
		row a column and each column a row.
	*/
	MathMatrix getTranspose();

	 void printMatrix();

};