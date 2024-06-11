// 문제 정의
// 총 N명이 있고, 각각 0~N-1까지 번호가 매겨짐
// 아래와 같은 친구 관계를 가진 사람 A,B,C,D,E가 존재하는지 구하는 문제
// A<->B / B<->C / C<->D / D<->E

// 입력 및 출력
// 첫째 줄에 사람의 수 N (5 <= N <= 2000)과 친구 관계의 수 M (1 <= M <= 2000)이 주어진다.
// 둘째 줄부터 정수 a와 b가 주어지며, 이는 a와 b가 친구라는 의미
// 문제의 조건에 맞는 A,B,C,D,E가 존재하면 1, 아니면 0을 출력

// 문제 풀이
// DFS 알고리즘으로 풀면 될 것 같음
// 어느 한 노드에서 시작해서 연속으로 4개의 관계가 나오면 되는건가?


#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

int N, M;

bool visited[MAX];
vector<vector<int>> Person(MAX);

bool answer;

bool DFS(int cur, int cnt)
{
    if (cnt >= 4){return true;}

    visited[cur] = true;
    for (int next : Person[cur]){
        if (!visited[next]){
            if (DFS(next, cnt+1)){return true;}
        }
    }
    visited[cur] = false;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++){
        cin >> a >> b;
        Person[a].push_back(b);
        Person[b].push_back(a);
    }

    for (int i = 0; i < N; i++){
        fill(visited, visited + N, false);
        if (DFS(i, 0)) {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';

    return 0;
}