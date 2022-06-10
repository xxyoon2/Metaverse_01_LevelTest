/*
    [문제를 파악한 내용]
    - 1000 미만의 3의 승수(3^0, 3^1, 3^2, 3^3 ...)를 차례대로 출력
    [해결 아이디어]
    - 1000 을 넘기기 전까지 1부터 3을 곱해줌 (값은 누적되어야 함)
    - 반복적으로 곱을 해주기 때문에 루프문을 사용
*/

#include <stdio.h>

int main()
{
    int multiplierOf3 = 1;

    while (multiplierOf3 < 1000)
    {
        printf("%d\n", multiplierOf3);
        multiplierOf3 *= 3;
    }

}
