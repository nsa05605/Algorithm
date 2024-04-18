#include <bits/stdc++.h>
using namespace std;

// BOJ 1874 스택 수열
// 1부터 n까지의 수를 push하고 pop함으로써 나오는 수들로 입력되는 수열을 만들 수 있다면 순서를 출력하고,
// 불가능하면 NO를 출력.
// 첫 줄에 n이 주어지면, 이후 수열을 이루는 n개의 정수가 입력된다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    int N; cin >> N;
    int num, idx=0, curr_num=1;
    int order[200001];

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        while(curr_num <= num){ // num과 같아질 때까지 스택을 쌓음
            S.push(curr_num);
            order[idx] = 1;
            idx++; curr_num++;
        }
        if (S.top() == num){order[idx] = 0; idx++; S.pop();}    // 같아지면 pop으로 제거하고, order에 기록
        else {cout << "NO" << '\n'; return 0;}  // 스택의 가장 위 숫자가 num보다 작은데, num이 아니면 불가능함
    }
    for (int i = 0; i < idx; i++){
        if (order[i] == 0){cout << "-" << '\n';}
        else if (order[i] == 1){cout << "+" << '\n';}
    }

    return 0;
}