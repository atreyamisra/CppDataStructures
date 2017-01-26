#include "SquareMatrix.h"
#include <iostream>
using namespace std;

int main()
{
	int** newmat = new int*[10];
	for (int i = 0; i < 10; i++) {
		newmat[i] = new int[5];
		for (int j = 0; j < 5; j++) {
			newmat[i][j] = 2;
		}
	}
	MathMatrix matrix(10, 5, newmat);
	SquareMatrix b (2, 2);
	MathMatrix a, c(b), dsub(3, 2, 2), d(3, 2, 0), e(3, 3, 0), f(0, 0, 0), g(0, 0, 0),  esub(3, 3, 0); //d on needs further work
	d.changeElement(0, 0, 1); d.changeElement(0, 1, 4); d.changeElement(1, 0, 2); d.changeElement(1, 1, 5); d.changeElement(2, 0, 3); d.changeElement(2, 1, 6);
		e.changeElement(0, 0, 1); e.changeElement(0, 1, 2); e.changeElement(0, 2, 3); e.changeElement(1, 0, 4); e.changeElement(1, 1, 5); e.changeElement(1, 2, 6);
	e.changeElement(2, 0, 7); e.changeElement(2, 1, 8); e.changeElement(2, 2, 9); esub.changeElement(0, 0, 1); esub.changeElement(0, 1, 4); esub.changeElement(0, 2, 8);
	esub.changeElement(1, 0, 3); esub.changeElement(1, 1, 2); esub.changeElement(1, 2, 5); esub.changeElement(2, 0, 7); esub.changeElement(2, 1, 9); esub.changeElement(2, 2, 6);
//	f.changeElement(0,0,2); f.changeElement(0, 1, 4); f.changeElement(0, 2, 6); f.changeElement(0, 3, 8); f.changeElement(0, 4, 10);
//	f.changeElement(1, 0, 12); f.changeElement(1, 1, 14); f.changeElement(1, 2, 16); f.changeElement(1, 3, 18); f.changeElement(1, 4,20);
//	f.changeElement(2, 0, 22); f.changeElement(2, 1, 24); f.changeElement(2, 2, 26); f.changeElement(2, 3, 28); f.changeElement(2, 4, 30);
	cout << "TESTING ADD AND + :" << endl;
	MathMatrix sum = f.add(g);
	MathMatrix sum2 = f + g;
	cout << endl << endl << "TESTING SUBTRACT AND - :" << endl;
	MathMatrix quotient = f.subtract(g);
	MathMatrix quotient2 = f - g;
	cout << endl << endl << "TESTING MULTIPLY AND *" << endl;
	cout << "You are multiplying this" << endl;
	cout << "By this" << endl;
	cout << "To reach this" << endl;
	MathMatrix product = f.multiply(g);
	cout << endl;
	MathMatrix product2 = f * g;
	cout << endl;
	MathMatrix prduct3 = esub.multiply(dsub);
	prduct3.printMatrix();

	cout << endl << endl << "TESTING TRANSPOSE" << endl;
	MathMatrix transpose = f.getTranspose();
	transpose.printMatrix();
	f.printMatrix();

	cout << endl << endl << "TESTING EQUALS AND ==" << endl;
	bool boolval = g.equals(g);
	printf("%d <- This number should be 1\n", boolval);
	cout << endl;

	cout << endl << endl << "TESTING numRows numCols getVal" << endl;
	int Number = f.numRows();
	printf("%d", Number);
	cout << endl;
	Number = f.numCols();
	printf("%d", Number);
	cout << endl;
	Number = f.getVal(2, 2);
	printf("%d", Number);
	cout << endl;

	cout << endl << endl << "TESTING SCALE AND CHANGE ELEMENT" << endl;
	MathMatrix scalar = f.scale(10);
	scalar.printMatrix();
	f.printMatrix();
	f.changeElement(2, 2, 69);
	f.printMatrix();

	cout << endl << endl << "TESTING DETERMINANT" << endl;
	Number = b.getDeterminant();
	printf("%d", Number);

	cout << endl << endl << "ON SQUARE MATRIX" << endl << "TESTING IDENTITY MATRIX" << endl;
	SquareMatrix identity = b.createIdentityMatrix(3);
	identity.printMatrix();



	cout << endl << endl << " TESTING SYMMETRY" << endl;

	
	getchar();
	return 0;
}