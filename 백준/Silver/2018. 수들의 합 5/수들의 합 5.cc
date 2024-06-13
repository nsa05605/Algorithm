// 문제 정의
// 자연수 N은 몇 개의 연속된 자연수의 합으로 나타낼 수 있다. 이때 1 <= N <= 10,000,000
// N을 입력받아 가지수를 출력하는 프로그램을 작성하라

// 입력
// 첫째 줄에 정수 N이 주어진다.

// 문제 풀이
// 투 포인터로 문제 풀이를 진행
// 하나는 앞에서부터, 나머지 하나는 뒤에서부터 출발해서 이 사이의 값들을 모두 더해서 N이 나오면 정답에 추가


#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int start = 1, end = 1;
    int sum = 1;
    while(end != N)
    {
        if (sum == N){
            answer++;
            end++;
            sum += end;
        }
        else if (sum > N){
            sum -= start;
            start++;
        }
        else {
            end++;
            sum += end;
        }
    }

    cout << answer << '\n';
}