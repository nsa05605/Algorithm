// 문제 정의
// 피보나치 수를 구하는 문제
// n이 주어졌을 때, n번째 피보나치를 구하는 프로그램

// 입력
// n이 주어진다. (n <= 90)

// 문제 풀이
// 피보나치는 원래 재귀로 풀면 되는데, 얘도 그렇지 않을까 싶긴함
// 다만 n이 90이면 피보나치 수가 굉장히 커질 것 같아서, 단순 재귀로 풀면 오류가 발생할 것 같다.
// 일단 받는 수는 unsigned long long으로 해보고, 그래도 안되면 __int128 자료형도 사용 가능한 것 같다.
// 그리고 재귀로 하면 계산 비용이 낭비될 것 같으니, 이미 계산한 fibo는 배열에 담아서 가져오자


#include <bits/stdc++.h>
using namespace std;

#define MAX 91

int n;
unsigned long long fibonacci[MAX];

void fibo()
{
    for (int i = 2; i <= n; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fibonacci[0] = 0; fibonacci[1] = 1;
    fibo();

    cout << fibonacci[n] << '\n';

    return 0;
}