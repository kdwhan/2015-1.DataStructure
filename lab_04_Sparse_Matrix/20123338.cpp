// Lab 004
// Name : 김대환
// Student ID : 20123338

#include "lab004.h"

SparseMatrix SparseMatrix::Add(SparseMatrix &b) {
// Return the sum of the Sparse Matrices *this and b

	//SparseMatrix c;
	int ac = 0, bc = 0;//terms 의 수만큼 돌려줄 카운트

	SparseMatrix c(terms + b.terms);//c의 크기(capacity) 초기화
	
	//*this 의 rows 와 cols
	c.rows = rows;
	c.cols = cols;
	while (ac < terms || bc < b.terms)
	{
		if (Compare(smArray[ac], b.smArray[bc]) == 0)//0이 나오면 a와b의 row와 col이 모두 같을때 
		{
			c.NewTerm(smArray[ac].row, smArray[ac].col, smArray[ac].value + b.smArray[bc].value);//새로운 terms 만들어서 값 저장
			
			//다음 좌표로 이동
			ac++;
			bc++;
		}
		else if (Compare(smArray[ac], b.smArray[bc]) < 0) //음수가 나오면 a의 row가 b의 row 보다 작다 
		{
			c.NewTerm(smArray[ac].row, smArray[ac].col, smArray[ac].value);// a가 작으므로 a를 먼저 입력
			ac++;//a 좌표만 이동
		}
		else//양수가 나오면 b가 작다 
		{
			c.NewTerm(b.smArray[bc].row, b.smArray[bc].col, b.smArray[bc].value);//b를 먼저 입력
			bc++;//b 좌표 이동
		}
		
	}
	
	return c;
}		


