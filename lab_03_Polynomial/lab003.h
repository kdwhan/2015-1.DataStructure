// Lab 003 
// Name :
// Student ID :

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class Polynomial; // forward declaration

class Term {
friend class Polynomial;
private:
	float coef; //coefficient
	int exp; //exponent
};

class Polynomial {
	Term *termArray;
	int capacity;	// size of termArray
	int terms;	// number of nonzero terms

	void NewTerm(const float theCoeff, const int theExp);
	// Insert a new term into the polynomial

public:
	Polynomial(int capacity = 10);
	// construct the polynomial p(x)=0

	Polynomial Add(Polynomial &poly);
	//Return the sum of the polynomials *this and poly

	Polynomial Subtract(Polynomial &poly);
	//Return the difference of the polynomials *this and poly

	void InitPolynomial(const char *msg);
	// Initialize the polynomial

	// output the polynomial
	void Output (ostream & os);

}; 


