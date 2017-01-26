typedef struct Node {
	double coeff;
	int degree;
	Node* next;
} Node;

// function where the interactive menu should be implemented
void runProgram();

class Poly {
private:
	// add private members as needed
	int xLocation, power;
	//string *polynomial; 
	double coefficient, a, c, y, z;
	char * token;
	Node * head, *conductor, *conductor2, *conductor3, *last;
public:
	Node * top;
	Poly(char* str);
	~Poly();
	Poly* add(Poly& otherPoly);
	Poly* multiply(Poly& otherPoly);
	double eval(int x);
	void print();
	bool equals(Poly& otherPoly);
	// add public members if needed
};