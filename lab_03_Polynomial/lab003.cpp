// Lab 003 
// Name :
// Student ID :

#include "lab003.h"

Polynomial Polynomial::Subtract(Polynomial &b) {
// Return the difference of the polynomials *this and b
	Polynomial c;
	int aPos = 0, bPos = 0;

	while (aPos < terms&&bPos < b.terms)
	{
		if (termArray[aPos].exp == b.termArray[bPos].exp){
			float t = termArray[aPos].coef - b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp){
			c.NewTerm(-b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else{
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}	
	}

	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < terms; bPos++)
		c.NewTerm(-b.termArray[bPos].coef, termArray[bPos].exp);

	return c;
}		



void Polynomial::Output(ostream & os) {
	os << "Number of terms = " << terms << ":";

	for (int i = 0; i < terms;i++)
		os << '('<<

}



