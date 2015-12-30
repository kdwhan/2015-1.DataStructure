// Lab 003 
// Name :
// Student ID :

#include "lab003.h"


// constructor
Polynomial::Polynomial(int cap) : capacity(cap)
{
	termArray = new Term[capacity];
	terms = 0;
}


void Polynomial::NewTerm(const float theCoeff, const int theExp)
{	// Add a new term to the end of termArray
	if(terms == capacity)
	{// double capacity of termArray
		capacity *=2;
		Term *temp = new Term[capacity]; // new array
		memcpy(temp, termArray, terms * sizeof(Term));
		delete[] termArray;
		termArray = temp;
	}
	termArray[terms].coef = theCoeff;
	termArray[terms++].exp = theExp;
}

Polynomial Polynomial::Add(Polynomial &b)
{// Return the sum of the polynomials *this and b
    Polynomial c;
	int aPos = 0, bPos = 0;
	while((aPos<terms) && (bPos <b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp){
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if(termArray[aPos].exp<b.termArray[bPos].exp){
			c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else {
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
	// add in remaining terms of *this
	for(;aPos<terms;aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for(;bPos<b.terms;bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
	return c;
}		



// init the polynomial
void Polynomial::InitPolynomial(const char *msg)
{
	cout << endl << "Init Polynomial " << msg << endl;
	float coef;
	int exp;
	while (1)
	{
		cout << "Enter a term (coef, exp)" << endl;
		cin >> coef >> exp;
		if(exp == -1)
			return;
		NewTerm(coef, exp);
	}
}



int main()
{
	while(1)
	{
		Polynomial a;
		Polynomial b;

		// form the Polynomial a
		a.InitPolynomial("a");
		a.Output(cout);
		b.InitPolynomial("b");
		b.Output(cout);
	
		Polynomial c;
		cout << "c = a + b" << endl;
		c = a.Add(b);
		c.Output(cout);
	
		cout << "d = a - b" << endl;
		Polynomial d = a.Subtract(b);
		d.Output(cout);
		// CAUTION : output to STDERR
		d.Output(cerr);

		cout << "Continue (y/n) " << endl;
		char ans;
		cin >> ans;
		if(ans == 'n')
			break;
	}

	return 1;
}

