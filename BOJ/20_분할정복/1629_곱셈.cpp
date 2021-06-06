#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

/* 풀이 과정
    홀수 제곱 시 mod C 연산을 해주면 중복. -> 거기선 안해주고 아에 출력전에 해주기.
    int 범위로는 한계가 있음 -> 주어지는 정수가 INT_MAX 임.

*/ 

ll pow(ll A, ll B, ll C) {
    if(B == 0) return 1;
    if(B == 1) return A;

    if(B % 2 > 0) return pow(A,B-1,C) * A; 
    ll half = pow(A,B/2,C) % C;
    return half * half % C;
}

int main() {

    ll A,B,C;

    scanf("%lld %lld %lld",&A,&B,&C);
    printf("%lld\n",pow(A,B,C) % C);

    return 0;
}

