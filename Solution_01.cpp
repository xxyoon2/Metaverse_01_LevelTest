#include <iostream>

using namespace std;

void swap1(int* a, int* b);	//포인터
void swap2(int& a, int& b);	//레퍼런스

int main()
{
	int a = 666, b = 999;
	swap1(&a, &b);

	int c = 0, d = 1;
	swap2(c, d);

	cout << a << " " << b << endl;
	cout << c << " " << d << endl;
}

//포인터
void swap1(int* lhs, int* rhs)
{
	if (lhs == NULL || rhs == NULL)
	{
		return;
	}

	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

//레퍼런스
void swap2(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
