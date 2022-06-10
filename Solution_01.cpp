/*
	[문제를 파악한 내용] 
	- 함수 외수에서 두 정수형 변수의 값을 서로 바꾸는 swap()함수를 구현해야 함
	- 매개변수를 포인터와 레퍼런스 사용한 것으로 각각 따로 swap()함수 구현
	[해결 아이디어] 
	- 하나는 포인터, 하나는 레퍼런스를 이용해 두 매개변수의 값을 바꿔줌
*/

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
