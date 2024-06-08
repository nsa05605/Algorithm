// 문제 정의
// 수빈이의 위치(N)와 동생의 위치(K)가 주어진다. (0 <= N, K <= 100,000)
// 수빈이가 움직일 수 있는 방법은 총 2개
//   1. 걷기 : x-1 혹은 x+1
//   2. 순간이동 : 2*x
// 수빈이와 동생의 위치가 주어졌을 때, 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고, 가장 빠른 시간으로 찾는 방법이 몇 가지인지 구하는 프로그램을 작성하라

// 입력
// 첫 줄에 수빈이의 위치 N과 동생의 위치 K가 주어진다.
// 출력
// 첫째 줄에는 수빈이가 동생을 찾는 가장 빠른 시간
// 둘째 줄에는 가장 빠른 시간으로 찾는 방법의 수를 출력

// 문제 풀이
// 최단 경로를 찾는 문제이므로 BFS 방법이 필요하지 않을까 싶고
// 이동하는 방법을 x-1, x+1, x*2 로 설정해서 움직여봐야 할 것 같음

#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

vector<int> graph(MAX, 0);
int N, K;
bool first = true;  // 처음으로 위치가 같은지
int visited[MAX] = {0};
int answer = MAX;
int num_of_answer = 0;

void BFS(int start, int time)
{
    queue<pair<int,int>> q;
    q.push({start, time});
    visited[start] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        visited[x] = true;
        // 첫 방식과 다른 방식으로 도달한 방법에 대해 위치가 같고, 걸린 시간도 같으면 정답 개수++
        if (!first && answer == cnt && x == K) {num_of_answer++;}
        
        // 처음으로 정답에 도달한 경우
        if (first && x == K){
            answer = cnt;       // 최소 시간 저장하고
            first = false;      // 처음 방문 여부는 false로 바꿔주고
            num_of_answer++;    // 정답 개수++
        }

        if (x+1 < MAX && !visited[x+1]){    // 걷기 +1
            q.push({x+1, cnt+1});
        }
        if (x-1 >= 0 && !visited[x-1]){     // 걷기 -1
            q.push({x-1, cnt+1});
        }
        if (2*x < MAX && !visited[2*x]){
            q.push({2*x, cnt+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    BFS(N, 0);
    cout << answer << '\n';
    cout << num_of_answer << '\n';

    return 0;
}