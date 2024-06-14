// 문제 정의
// N개의 수 A_1 ~ A_N 와 L이 주어진다.
// A_{i-L+1} ~ A_i 중 최솟값을 D_i라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하라

// 입력
// 첫째 줄에 N과 L (1 <= L <= N <= 5,000,000)
// 둘째 줄에 N개의 수 A_i가 주어진다.

// 문제 풀이
// 전체 범위가 5,000,000 이므로, O(N) 과정으로 접근해야 함
// 그러면 하나씩 검사하면서 지나가야 한다는 건데, 생각해보자
// 슬라이딩 윈도우 방법으로 수행하면 될 것 같은데, 이걸 O(N)으로 하려면?
// 찾아보니 deque 방법으로 수행해야 함
// 

#include <bits/stdc++.h>
using namespace std;

int N, L;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    deque<pair<int,int>> dq;

    for (int i = 0; i < N; i++){
        int now;
        cin >> now;

        while(dq.size() && dq.back().first > now){
            dq.pop_back();
        }
        dq.push_back({now, i});

        if (dq.front().second <= i - L){
            dq.pop_front();
        }

        cout << dq.front().first << " ";
    }

    return 0;
}