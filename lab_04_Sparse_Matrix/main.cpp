#include <iostream>


class AA
{
private:
	int num;
public:
	AA(int n) :num(n)
	{
		std::cout << "��ü ����" << std::endl;
	}
	AA(AA& k) :num(k.num)
	{
		std::cout << "��ü ���� " << std::endl;
	}
	~AA()
	{
		std::cout << "�Ҹ� �Ѵ�." << std::endl;
	}
	AA Show()
	{
		std::cout << num << std::endl;
		return *this;
	}
	void Test()
	{
		AA test(4);
		test.Show();
	}
	AA Add(AA &A)
	{
		std::cout << "�߰� ����" << std::endl;
		num++;
		return A;
	}
private:

};



void main()
{
	AA k(4);
	AA q(k);

	k.Add(q).Show().Add(q);

	k.Show();
	q.Show();


}