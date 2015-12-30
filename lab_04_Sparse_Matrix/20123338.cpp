// Lab 004
// Name : ���ȯ
// Student ID : 20123338

#include "lab004.h"

SparseMatrix SparseMatrix::Add(SparseMatrix &b) {
// Return the sum of the Sparse Matrices *this and b

	//SparseMatrix c;
	int ac = 0, bc = 0;//terms �� ����ŭ ������ ī��Ʈ

	SparseMatrix c(terms + b.terms);//c�� ũ��(capacity) �ʱ�ȭ
	
	//*this �� rows �� cols
	c.rows = rows;
	c.cols = cols;
	while (ac < terms || bc < b.terms)
	{
		if (Compare(smArray[ac], b.smArray[bc]) == 0)//0�� ������ a��b�� row�� col�� ��� ������ 
		{
			c.NewTerm(smArray[ac].row, smArray[ac].col, smArray[ac].value + b.smArray[bc].value);//���ο� terms ���� �� ����
			
			//���� ��ǥ�� �̵�
			ac++;
			bc++;
		}
		else if (Compare(smArray[ac], b.smArray[bc]) < 0) //������ ������ a�� row�� b�� row ���� �۴� 
		{
			c.NewTerm(smArray[ac].row, smArray[ac].col, smArray[ac].value);// a�� �����Ƿ� a�� ���� �Է�
			ac++;//a ��ǥ�� �̵�
		}
		else//����� ������ b�� �۴� 
		{
			c.NewTerm(b.smArray[bc].row, b.smArray[bc].col, b.smArray[bc].value);//b�� ���� �Է�
			bc++;//b ��ǥ �̵�
		}
		
	}
	
	return c;
}		


