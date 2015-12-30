#include <iostream>


class AA
{
private:
	int num;
public:
	AA(int n) :num(n)
	{
		std::cout << "°´Ã¼ »ý¼º" << std::endl;
	}
	AA(AA& k) :num(k.num)
	{
		std::cout << "°´Ã¼ º¹»ç " << std::endl;
	}
	~AA()
	{
		std::cout << "¼Ò¸ê ÇÑ´Ù." << std::endl;
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
		std::cout << "Áß°£ Á¡°Ë" << std::endl;
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