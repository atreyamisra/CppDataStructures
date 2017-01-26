/*
Metcalfe, Matthew and Misra, Atreya
mmm5563, am73676
16220
EE312- Assignment 7
*/
#include "poly.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Main function of your program - called by main
void runProgram() {
	// repeatedly prompt the user and process the selected
	// operation until the user selects the quit option.
	string filename, line, polys, polyOneLine, polyTwoLine, continueEnd, evalStr;
	int polyCount, operation, evalPoint, poly1, poly2, commaPosition;
newFile:
	filename.clear();
	cout << "Enter the file that you would like to work with: "; 
	cin >> filename;
	//cout << endl;
	cout << "The polynomials available for operation are:" << endl;
	fstream file;
	file.open(filename.c_str()); //might not need ios::in
	getline(file, line);
	polyCount = stoi(line); //maybe make polyCount a string?
	for (int i = polyCount; i > 0; i--) {
		getline(file, line);
		int number = polyCount - i + 1;
		cout << number << ". " << line << endl;
	} //MAKE POLY??
	if (file.is_open()) {
		file.close();
	}
	
sameFile:
	cout << "What operation would you like to perform?" << endl << "1. ADD polynomials" << endl << "2. MULTIPLY polynomials" << 
	endl << "3. EVALUATE polynomial" << endl << endl << "Enter choice #: "; 
	cin >> operation; 
	//cout << endl;
	switch (operation) {
	case 1:{ //ADD
//reAdd:
		cout <<  "Enter the two polynomials that you would like to work with: ";
		cin >> polys;
		//cout << endl;
		commaPosition = polys.find(",");
		poly1 = stoi(polys.substr(0, commaPosition));
		poly2 = stoi(polys.substr(commaPosition + 1, polys.length()));
		/*if (poly1 > polyCount || poly2 > polyCount) {
			cout << "Invalid input" << endl;
			goto reAdd;
		}*/
		file.open(filename.c_str());
		for (int i = poly1 + 1; i > 0; i--) {
			getline(file, polyOneLine);
		}
		if (file.is_open()) {
			file.close();
		}
		file.open(filename.c_str());
		for (int i = poly2 + 1; i > 0; i--) {
			getline(file, polyTwoLine);
		}
		if (file.is_open()) {
			file.close();
		}
		char * writable = new char[polyOneLine.size() + 1];
		copy(polyOneLine.begin(), polyOneLine.end(), writable);
		writable[polyOneLine.size()] = '\0';
		Poly * p1 = new Poly(writable);
		char * writable2 = new char[polyTwoLine.size() + 1];
		copy(polyTwoLine.begin(), polyTwoLine.end(), writable2);
		writable2[polyTwoLine.size()] = '\0';
		Poly * p2 = new Poly(writable2);
		p1->add(*p2);
		cout << "The symbolic sum of the 2 polynomials is:" << endl; 
		p1->print();
		cout << endl << endl;
		p1->~Poly();
		p2->~Poly();
		delete[] writable;
		delete[] writable2;
	}
		break;

	case 2: { //MULTIPLY
	//reMultiply:
		cout <<  "Enter the two polynomials that you would like to work with: ";
		cin >> polys;
		//cout << endl;
		commaPosition = polys.find(",");
		poly1 = stoi(polys.substr(0, commaPosition));
		poly2 = stoi(polys.substr(commaPosition + 1,polys.length()));
		/*if (poly1 > polyCount || poly2 > polyCount) {
			cout << "Invalid input" << endl;
			goto reMultiply;
		}*/
		file.open(filename.c_str());
		for (int i = poly1 + 1; i > 0; i--) {
			getline(file, polyOneLine);
		}
		if (file.is_open()) {
			file.close();
		}
		file.open(filename.c_str());
		for (int i = poly2 + 1; i > 0; i--) {
			getline(file, polyTwoLine);
		}
		if (file.is_open()) {
			file.close();
		}
		char * writable = new char[polyOneLine.size() + 1];
		copy(polyOneLine.begin(), polyOneLine.end(), writable);
		writable[polyOneLine.size()] = '\0';
		Poly * p1 = new Poly(writable);
		char * writable2 = new char[polyTwoLine.size() + 1];
		copy(polyTwoLine.begin(), polyTwoLine.end(), writable2);
		writable2[polyTwoLine.size()] = '\0';
		Poly * p2 = new Poly(writable2);
		//DO THE ACTUAL MULTIPLICATION 
		p1->multiply(*p2);
		cout << "The symbolic product of the 2 polynomials is:" << endl; 
		p1->print(); 
		cout << endl << endl;
		p1->~Poly();
		p2->~Poly();
		delete[] writable;
		delete[] writable2;
	}
		break;

	case 3: { //EVALUATE
	//reEval:
		cout <<  "Enter the polynomial that you would like to work with: ";
		cin >> polys; //Maybe make an int so it's easier
		poly1 = stoi(polys);
		/*if (poly1 > polyCount) {
			cout << "Invalid input" << endl;
			goto reEval;
		}*/
		file.open(filename.c_str());
		for (int i = poly1 + 1; i > 0; i--) {
			getline(file, polyOneLine);
		}
		if (file.is_open()) {
			file.close();
		}
		cout << "Enter the evaluation point (the value of x): ";
		cin >> evalStr;
		evalPoint = stoi(evalStr);
		char * writable = new char[polyOneLine.size() + 1];
		copy(polyOneLine.begin(), polyOneLine.end(), writable);
		writable[polyOneLine.size()] = '\0';
		Poly * p1 = new Poly(writable);
		cout << "Value of that polynomial at " << evalPoint <<" is: " << p1->eval(evalPoint) << endl << endl;
		p1->~Poly();
		delete[]writable;
	}
		break;
	}
keepGoing:
	cout << "Do you want to perform additional operations on the existing file (Y/N)? ";
	cin >> continueEnd;
	//cout << endl;
	if (continueEnd == "Y") {
		goto sameFile;
	}

	else if(continueEnd == "N") {
keepGoingTwo:
		cout << "Do you want to work with another file (Y/N)? ";
		cin >> continueEnd;
		//cout << endl;
		if (continueEnd == "Y") {
			goto newFile;
		}
		else if(continueEnd == "N") {
			cout << "Thank you for using this program!" << endl;
			//May need to free nodes and Polys and strings
		}
		else {
			cout << "Incorrect input" << endl;
			goto keepGoingTwo;
		}
	}
	else {
		cout << "Incorrect input" << endl;
		goto keepGoing;
	}
}

Poly::Poly(char* str) {
	if (str != NULL) {
		/*	string polynomial(str); //delete polynomial at end FIX THIS
			xLocation = polynomial.find("x");
			if (xLocation == polynomial.npos) {
				//Only one Number

				coefficient = stod(polynomial);
			}*/
		string tempStr(str);
		top = NULL;
		head = new Node; 
		head->next = NULL;
		head->coeff = 0;
		head->degree = 0;
		conductor = head;
		last = head;
		token = new char[500];
		token = strtok(str, " +x");
		while (token != NULL) { //WHAT TO DO FOR 0x CASE
			if (*token == '-') {
				token = strtok(NULL, " +x");
				coefficient = stod(token);
				coefficient = -coefficient;
			}
			else {
				coefficient = stod(token);
			}
			
				token = strtok(NULL, " +x");
				if (token != NULL) {
					if (*token == '-') {
						continue;
					}
				}
				if (token == NULL) {//end
		  
					if (tempStr.substr(tempStr.length() - 1, tempStr.length()) == "x") { //might not need the - 1
						power = 1;
					}
					else {
						power = 0;
					}
				}
				else if(strstr(token, "^") != NULL){
					memmove(token, token + 1, strlen(token));
					power = stoi(token);
					token = strtok(NULL, " +x");

				}
				else {
					power = 1;
					//token will have the value of the last value without an x
				}
				conductor->coeff = coefficient;
				conductor->degree = power;
				conductor->next = new Node;
				conductor = conductor->next;
				conductor->coeff = 0;
				conductor->degree = 0;
				conductor->next = NULL;
		}
		while (last->next != conductor) {
			last = last->next;
		}
		last->next = NULL;
		delete conductor;
	}


}

Poly::~Poly() {
	delete token;
	last = head;
	while (last->next != NULL) {
		conductor = last->next;
		delete last;
		last = conductor;
	}
	delete last;
	/*if (top) {
		last = top; //might need to check if top was set?
		while (last->next != NULL) {
			conductor = last->next;
			delete last;
			last = conductor;
		}
		delete last;
	}*/
	//delete coefficient and other ints?
}

Poly* Poly::add(Poly& otherPoly) {
	conductor = head;
	conductor2 = otherPoly.head;
	top = new Node;
	top->next = NULL;
	top->coeff = 0;
	top->degree = 0;
	last = top;
	conductor3 = top;
	while (conductor->next != NULL && conductor2->next != NULL) {
		if (conductor->degree > conductor2->degree) {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor = conductor->next;
		}
		else if (conductor->degree < conductor2->degree) {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor2 = conductor2->next;
		}
		else if (conductor->degree == conductor2->degree) {
			conductor3->coeff = conductor2->coeff + conductor->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor2 = conductor2->next;
			conductor = conductor->next;
		}
	}

	if (conductor->next == NULL) {
	loop1:
		if (conductor->degree > conductor2->degree) {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			goto nodeOneDone;
		}
		else if (conductor->degree < conductor2->degree) {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;

			if (conductor2->next != NULL) {
				conductor2 = conductor2->next;
				goto loop1;
			}
			else {
				goto bothDone;
			}
		}
		else if (conductor->degree == conductor2->degree) {
			conductor3->coeff = conductor2->coeff + conductor->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;

			if (conductor2->next != NULL) {
				conductor2 = conductor2->next;
				goto nodeOneDone;
			}
			else {
				goto bothDone;
			}
		}
	}
	else {
	loop2:
		if (conductor->degree > conductor2->degree) {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;

			if (conductor->next != NULL) {
				conductor = conductor->next;
				goto loop2;
			}
			else {
				goto bothDone;
			}
		}
		else if (conductor->degree < conductor2->degree) {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;

			goto nodeTwoDone;
		}
		else if (conductor->degree == conductor2->degree) {
			conductor3->coeff = conductor2->coeff + conductor->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;

			if (conductor->next != NULL) {
				conductor = conductor->next;
				goto nodeTwoDone;
			}
			else {
				goto end;
			}
		}
	}
	nodeOneDone:
		if (conductor2->next != NULL) {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor2 = conductor2->next;
			goto nodeOneDone;
		}
		else {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			goto end;
		}
	nodeTwoDone:
		if (conductor->next != NULL) {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor = conductor->next;
			goto nodeTwoDone;
		}
		else {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			goto end;
		}
	bothDone:
		if (conductor->degree > conductor2->degree) {
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
		}
		else if (conductor->degree < conductor2->degree) {
			conductor3->coeff = conductor2->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
			conductor3->coeff = conductor->coeff;
			conductor3->degree = conductor->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
		}
		else if (conductor->degree == conductor2->degree) {
			conductor3->coeff = conductor2->coeff + conductor->coeff;
			conductor3->degree = conductor2->degree;
			conductor3->next = new Node;
			conductor3 = conductor3->next;
			conductor3->coeff = 0;
			conductor3->degree = 0;
			conductor3->next = NULL;
		}

	end:
		while (last->next != conductor3) {
			last = last->next;
		}
		last->next = NULL;
		delete conductor3;
		last = head;
		while (last->next != NULL) {
			conductor = last->next;
			delete last;
			last = conductor;
		}
		delete last;
		head = top;
		return 0;
}

Poly* Poly::multiply(Poly& otherPoly) {
	int a = 0;
	int c = 0;
	double d = 0;
	conductor = head;
	conductor2 = otherPoly.head;
	top = new Node;
	top->next = NULL;
	conductor3 = top;
	conductor3->degree = conductor2->degree + conductor->degree;
	conductor3->coeff = conductor2->coeff * conductor->coeff;
	a = conductor3->degree - 1;
	//conductor = conductor->next; WRONG
	conductor2 = conductor2->next;
	for (a; a >= 0; a--) { //Creating a Linked List with the degree and empty coefficients
		conductor3->next = new Node;
		conductor3 = conductor3->next;
		conductor3->degree = a;
		conductor3->coeff = (double)0;
		conductor3->next = NULL;
	}
	
	//conductor3 = top->next
	while (conductor != NULL) {
		while (conductor2 != NULL) {
			c = conductor->degree + conductor2->degree;
			d = conductor2->coeff * conductor->coeff;
			conductor3 = top->next;
			while (conductor3 != NULL) {
				if (conductor3->degree == c) {
					conductor3->coeff = d + conductor3->coeff;
					conductor3 = conductor3->next;
					break;
				}
				if (conductor3->next != NULL) {
					conductor3 = conductor3->next;
				}

			}
			if (conductor2->next != NULL) {
				conductor2 = conductor2->next;
			}
			else {
				break;
			}
		}
		if (conductor->next != NULL) {
			conductor2 = otherPoly.head;
			conductor = conductor->next;
		}
		else {
			break;
		}
	}
	conductor3 = top;
	while (conductor3->next->coeff == 0 && conductor3->next != NULL) {
		while (conductor3->next != NULL) {
			 
				conductor2 = conductor3->next;
				conductor3->next = conductor2->next;
				delete conductor2;
			

		}
		if (conductor3->next != NULL) {
			conductor3 = conductor3->next;
		}
	}
	/*if (conductor3->next->coeff == 0) {
		conductor3->next = NULL;
	}*/
	last = head;
	while (last->next != NULL) {
		conductor = last->next;
		delete last;
		last = conductor;
	}
	delete last;
	head = top;
	return 0;
}

double Poly::eval(int x) {
	 y = 0;
	 z = 0;
	 a = (double)x;
	conductor = head;
	while (conductor != NULL) {
		power = conductor->degree;
		c = pow(a, power);
		coefficient = conductor->coeff;
		y = coefficient*c;
		z = z + y;
		conductor = conductor->next;
	}
	return z;
}

void Poly::print() {
	if (head == NULL) { //Maybe head->coeff == 0
		cout << "0" << endl;
	}
	else {
		conductor = head;
		while (conductor->next != NULL) {
			if (conductor->degree == 0) {
				cout << conductor->coeff; //SHOULD NEVER BE HIT I BELIEVE
			}
			else if (conductor->degree == 1) {
				cout << conductor->coeff << "x + ";
			}
			else {
				cout << conductor->coeff << "x^" << conductor->degree << " + ";
			}
			conductor = conductor->next;
		}
		if (conductor->degree == 0) {
			cout << conductor->coeff;
		}
		else if (conductor->degree == 1) {
			cout << conductor->coeff << "x";
		}
		else {
			cout << conductor->coeff << "x^" << conductor->degree;

		}
	}
}

bool Poly::equals(Poly& otherPoly) {
	conductor = head;
	conductor2 = otherPoly.head;
	while (conductor != NULL && conductor2 != NULL) {
		if (conductor->coeff == conductor2->coeff && conductor->degree == conductor2->degree) {
			conductor = conductor->next;
			conductor2 = conductor2->next;
		}
		else
			return 0;
	}
	return 1;
	
}