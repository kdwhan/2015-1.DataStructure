// Lab 003 
// Name : 김대환
// Student ID : 20123338

#include "lab003.h"

Polynomial Polynomial::Subtract(Polynomial &b) {
// Return the difference of the polynomials *this and b
	Polynomial d;
	int aPos = 0, bPos = 0;
	while ((aPos <terms) && (bPos<b.terms))
		if (termArray[aPos].exp == b.termArray[bPos].exp){
			float t = termArray[aPos].coef - b.termArray[bPos].coef;
			if (t) d.NewTerm(t, termArray[aPos].exp);
			aPos++; bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp){
			d.NewTerm(-b.termArray[bPos].coef, b.termArray[bPos].exp);
			bPos++;
		}
		else{
			d.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			aPos++;
		}
		//남은 항들 더해주기
		for (; aPos < terms; aPos++)
			d.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
		for (; bPos < b.terms; bPos++)
			d.NewTerm(-b.termArray[bPos].coef, b.termArray[bPos].exp);
		return d;
}		



void Polynomial::Output(ostream & os) {
	os << "Number of terms = " << terms << ":";

	for (int i = 0; i < terms; i++)
	{
		os << '(' << termArray[i].coef << ',' << termArray[i].exp << ')';
	}
	std::cout << std::endl;
}



